#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QList>
#include <QVector>
#include <QTimer>
#include <QPoint>

#include "dialog.h"
#include "dialoguse.h"
#include "room.h"
#include "humen.h"
#include "fire.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void createMenu();
    void showButton();
    void hideButton();
    void life();
    void deliteItem(int inX, int inY, int x, int y);
    bool stepWey(int it, int number);
    ~MainWindow();

signals:


public slots:
    void newRoom();
    void loadRoom();
    void saveRoom();
    void Exit();

private slots:
    void on_addHumen_clicked(bool checked);
    void on_addWall_clicked(bool checked);
    void on_addExit_clicked(bool checked);
    void on_addFire_clicked(bool checked);
    void on_deleteButton_clicked(bool checked);
    void on_goButton_clicked();
    void on_stopButton_clicked();
    void updateHumen();
    void updateFire();

private:
    bool use;
    Ui::MainWindow *ui;
    QGraphicsScene *sc;
    QGraphicsView *gw;
    QTimer *timerHumen;
    QTimer *timerFire;
    QGraphicsEllipseItem *Humen;
    QGraphicsRectItem *Fire;
    room *house;
    QList< QList<int> > roomMatrica;
    QList<humen*> bodys;
    QList<fire*> burn;
    QList<fire*> tempBurn;
    int countSurvaiv;
    int countDead;
    int count;
    int countHumen;

protected:
    virtual void mousePressEvent(QMouseEvent *mouseEvent);
};

#endif // MAINWINDOW_H
