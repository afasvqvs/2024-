#ifndef BOOM_H
#define BOOM_H
#include "config.h"
#include <QPixmap>
#include <QVector>



class Boom
{
public:
    Boom();

    void updateInfo();

public:

    QVector<QPixmap> m_pixArr;

    int m_X;
    int m_Y;

    bool m_Free;

    int m_Recoder;

    int m_index;
};

#endif // BOOM_H
