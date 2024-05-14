#ifndef MYSHIP_H
#define MYSHIP_H
#include <QPixmap>
#include <QRect>
#include "bullet.h"


class MyShip
{
public:
    MyShip();

    void shoot();

    void setPosition(int x,int y);

public:

    QPixmap m_myship;

    int m_X;
    int m_Y;

    QRect m_Rect;

    Bullet m_bullet[BULLET_NUM];

    int m_recoder;
};

#endif // MYSHIP_H
