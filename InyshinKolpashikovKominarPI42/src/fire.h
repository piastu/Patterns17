#ifndef FIRE_H
#define FIRE_H

#include <QPointF>
#include <QGraphicsRectItem>

class fire
{
public:
    fire(int x,int y,QGraphicsRectItem* i);
    QGraphicsRectItem* getItem();
    QPointF getNowPoint();
    int getPower();
    void deletePower();

private:
    int nowX;
    int nowY;
    int power;
    QGraphicsRectItem* item;
};

#endif // FIRE_H
