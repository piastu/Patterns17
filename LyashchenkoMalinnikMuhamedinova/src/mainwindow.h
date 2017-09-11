#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
const double pi = 3.1415927;
const int N=7;
const int Min=0;
const int Max=11;
using namespace std;
namespace Ui {
class MainWindow;
}

class Role
{
public:
    virtual int course(int time,int (*gamers)[N-1],int Quantity,int gamer,int f)=0;
    virtual int getrole()=0;
};
// Класс игрок
class Gamer
{
public:
    int course(int time,int (*gamers)[N-1],int Quantity,int gamer,int f);
    void amendrole();
    void amendstatus(int time);
    Gamer(string N,int o,int l,int a,int c);
    Gamer();
    ~Gamer();
    string getName();
    int getoratory();
    int getluck();
    int getacting();
    int getconformality();
    int getstatus();
    int getrole();
private:
    string name;        // Имя
    int oratory;        // Красноречие
    int luck;           // Удача
    int acting;         // Актерские способности
    int conformality;   // Конформность
    int status;         // Статус в игре
    Role *role;         // Роль в игре
};
// Класс мирный житель
class Civilian : public Role
{
public:
    int course(int time,int (*gamers)[N-1],int Quantity,int gamer,int f);
    int getrole();
    int vote(int (*gamers)[N-1],int Quantity,int gamer,int f);
};
// Класс Маффия
class Mafia : public Role
{
public:
    int course(int time,int (*gamers)[N-1],int Quantity,int gamer,int f);
    int getrole();
    int kill(int (*gamers)[N-1],int Quantity);
    int vote(int (*gamers)[N-1],int Quantity);
};
// Класс формы
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Graphic();
    void Table(bool f);
    void Load();
    int difference();
    void casting();
    void Course();
private slots:
    void on_btnStart_clicked();
    void on_btnNext_clicked();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *sc;
    Gamer *Gamers;
    int Quantity;
    int timed;
};

#endif // MAINWINDOW_H
