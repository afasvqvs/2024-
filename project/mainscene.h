#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "myship.h"
#include "bullet.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();

    void initscene();

    void playGAme();

    void updatePosition();

    void paintEvent(QPaintEvent *);

    void mouseMoveEvent(QMouseEvent *);

    Map m_map;

    MyShip m_ship;

    QTimer m_Timer;

    //Bullet temp_Bullet;
};

#endif // MAINSCENE_H
