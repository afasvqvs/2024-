#include "myship.h"
#include "config.h"

MyShip::MyShip()
{
    m_myship.load(MYSHIP_PATH);

    m_X=(GAME_WIDTH-m_myship.width())*0.5;
    m_Y=GAME_HEIGHT-m_myship.height();

    m_Rect.setWidth(m_myship.width());
    m_Rect.setHeight(m_myship.height());
    m_Rect.moveTo(m_X,m_Y);
}

void MyShip::shoot()
{
    m_recoder++;

    if(m_recoder<BULLET_INTERVAL)
    {
        return;
    }

    m_recoder=0;

    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_bullet[i].m_Free)
        {
            m_bullet[i].m_Free=false;
            m_bullet[i].m_X=m_X+m_Rect.width()*0.5-50;
            m_bullet[i].m_Y=m_Y-50;
            break;

        }
    }
}

void MyShip::setPosition(int x, int y)
{
    m_X=x;
    m_Y=y;
    m_Rect.moveTo(m_X,m_Y);
}
