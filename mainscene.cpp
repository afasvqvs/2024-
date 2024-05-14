#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include "qpainter.h"
#include <QMouseEvent>
#include <ctime>
#include <QSound>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initscene();

    playGAme();
}

MainScene::~MainScene()
{

}

void MainScene::initscene()
{

    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    setWindowTitle(GAME_TITLE);

    setWindowIcon(QIcon(GAME_ICON));

    m_Timer.setInterval(GAME_RATE);

    m_recoder=0;

    srand((unsigned int)time(NULL));

}

void MainScene::playGAme()
{
    QSound::play(SOUND_BACKGROUND);

    m_Timer.start();

    connect(&m_Timer,&QTimer::timeout,[=](){

        enemyToScene();

        updatePosition();

        update();

        cillisionDetection();

    });
}

void MainScene::updatePosition()
{
    m_map.mapPosition();

    m_ship.shoot();

    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_ship.m_bullet[i].m_Free==false)
        {
            m_ship.m_bullet[i].updatePosition();

        }
    }

    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free==false)
        {
            m_enemys[i].updatePosition();

        }
    }

    for(int i=0;i<BOOM_NUM;i++)
    {
        if(m_booms[i].m_Free==false)
        {
            m_booms[i].updateInfo();
        }
    }

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    painter.drawPixmap(m_ship.m_X,m_ship.m_Y,m_ship.m_myship);

    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_ship.m_bullet[i].m_Free==false)
        {
            painter.drawPixmap(m_ship.m_bullet[i].m_X,m_ship.m_bullet[i].m_Y,m_ship.m_bullet[i].m_Bullet);

        }
    }

    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free==false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }
   
    for(int i=0;i<BOOM_NUM;i++)
    {
        if(m_booms[i].m_Free==false)
        {
            painter.drawPixmap(m_booms[i].m_X,m_booms[i].m_Y,m_booms[i].m_pixArr[m_booms[i].m_index]);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
   int x= event->x()-m_ship.m_Rect.width()*0.5;
   int y= event->y()-m_ship.m_Rect.height()*0.5;

   if(x<=0)
   {
       x=0;
   }
   if(x>=GAME_WIDTH-m_ship.m_Rect.width())
   {
       x=GAME_WIDTH-m_ship.m_Rect.width();
   }
   if(y<=0)
   {
       y=0;
   }
   if(y>=GAME_HEIGHT-m_ship.m_Rect.height())
   {
       y=GAME_HEIGHT-m_ship.m_Rect.height();
   }

   m_ship.setPosition(x,y);
}

void MainScene::enemyToScene()
{
    m_recoder++;

    if(m_recoder<ENEMY_INTERVAL)
    {
        return;
    }

    m_recoder=0;

    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free=false;
            m_enemys[i].m_X=rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y=-m_enemys[i].m_Rect.height();
            break;

        }
    }

}

void MainScene::cillisionDetection()
{
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            continue;
        }

        for(int j=0;j<BULLET_NUM;j++)
        {
            if(m_ship.m_bullet[j].m_Free)
            {
                continue;
            }

            if(m_enemys[i].m_Rect.intersects(m_ship.m_bullet[j].m_Rect))
            {
                m_enemys[i].m_Free=true;
                m_ship.m_bullet[j].m_Free=true;

                for(int k=0;k<BOOM_NUM;k++)
                {
                    if(m_booms[k].m_Free)
                    {
                        QSound::play(SOUND_BOOM);

                        m_booms[k].m_Free=false;
                        m_booms[k].m_X=m_enemys[i].m_X;
                        m_booms[k].m_Y=m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }
    }

}
