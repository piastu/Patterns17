#include "humen.h"

humen::humen(int x, int y, QGraphicsEllipseItem* i)
{
    hp=100;
    nowX=x;
    nowY=y;
    endX=nowX;
    endY=nowY;
    addX=0;
    addY=0;
    toExit=false;
    item=i;
    oldX=-1;
    oldY=-1;
}

QPointF humen::getNowPoint()
{
    QPointF temp;
    temp.setX(nowX);
    temp.setY(nowY);
    return temp;
}

QPointF humen::getEndPoint()
{
    QPointF temp;
    temp.setX(endX);
    temp.setY(endY);
    return temp;
}

QPointF humen::getAddStep()
{
    QPointF temp;
    temp.setX(addX);
    temp.setY(addY);
    return temp;
}

QPoint humen::getOld()
{
    QPoint temp;
    temp.setX(oldX);
    temp.setY(oldY);
    return temp;
}

QGraphicsEllipseItem *humen::getItem()
{
    return item;
}

int humen::getHP()
{
    return hp;
}

void humen::setAddPoint(int x, int y)
{
    addX=x;
    addY=y;
}

void humen::setEndPoint(int x, int y)
{
    endX=x;
    endY=y;
}

void humen::addPoint()
{
    nowX+=addX;
    nowY+=addY;
}

void humen::setWeyExit()
{
    toExit=true;
}

void humen::setOld(int x, int y)
{
    oldX=x;
    oldY=y;
}

bool humen::getWeyExit()
{
    return toExit;
}

bool humen::deliteHP()
{
    hp-=10;
    if(hp>0)
        return true;
    else
        return false;
}
