#ifndef HUMEN_H
#define HUMEN_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QPointF>

class humen
{
public:
    humen(int x, int y, QGraphicsEllipseItem* i);
    QPointF getNowPoint();
    QPointF getEndPoint();
    QPointF getAddStep();
    QPoint getOld();
    QGraphicsEllipseItem* getItem();
    int getHP();
    void setAddPoint(int x, int y);
    void setEndPoint(int x,int y);
    void addPoint();
    void setWeyExit();
    void setOld(int x,int y);
    bool getWeyExit();
    bool deliteHP();

private:
    int hp;
    int nowX;
    int nowY;
    int endX;
    int endY;
    int addX;
    int addY;
    int oldX;
    int oldY;
    bool toExit;
    QGraphicsEllipseItem* item;
};

#endif // HUMEN_H
