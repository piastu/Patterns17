#include "fire.h"


fire::fire(int x, int y, QGraphicsRectItem *i)
{
    nowX=x;
    nowY=y;
    item=i;
    power=3;
}

QGraphicsRectItem *fire::getItem()
{
    return item;
}

QPointF fire::getNowPoint()
{
    QPointF temp;
    temp.setX(nowX);
    temp.setY(nowY);
    return temp;
}

void fire::deletePower()
{
    power--;
}

int fire::getPower()
{
    return power;
}

