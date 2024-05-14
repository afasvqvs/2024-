#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "myship.h"
#include "bullet.h"
#include "enemyplane.h"
#include "boom.h"

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

    void enemyToScene();

    EnemyPlane m_enemys[ENEMY_NUM];

    int m_recoder;

    Map m_map;

    MyShip m_ship;

    QTimer m_Timer;

    void cillisionDetection();

    Boom m_booms[BOOM_NUM];
    
};

#endif // MAINSCENE_H
