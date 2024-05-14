#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include "qpainter.h"
#include <QMouseEvent>


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

}

void MainScene::playGAme()
{
    m_Timer.start();

    connect(&m_Timer,&QTimer::timeout,[=](){

        updatePosition();

        update();
    });
}

void MainScene::updatePosition()
{
    m_map.mapPosition();

    m_ship.shoot();
    for(int i=0;i<BULLET_INTERVAL;i++)
    {
        if(m_ship.m_bullet[i].m_Free==false)
        {
            m_ship.m_bullet[i].updatePosition();

        }
    }
    //temp_Bullet.m_Free=false;
    //temp_Bullet.updatePosition();
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    painter.drawPixmap(m_ship.m_X,m_ship.m_Y,m_ship.m_myship);

    for(int i=0;i<BULLET_INTERVAL;i++)
    {
        if(m_ship.m_bullet[i].m_Free==false)
        {
            painter.drawPixmap(m_ship.m_bullet[i].m_X,m_ship.m_bullet[i].m_Y,m_ship.m_bullet[i].m_Bullet);

        }
    }
    //painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);
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
