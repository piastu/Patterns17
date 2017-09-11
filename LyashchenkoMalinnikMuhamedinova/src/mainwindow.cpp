#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <string>
#include <ctime>
#include <QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool f=false;
    Gamers=(Gamer *)operator new(sizeof(Gamer) * 16);

    Load();
    Table(f);
    sc = new QGraphicsScene();
    ui->graphicsView->setScene(sc);
    sc->clear();
    QPointF ctr((float)this->ui->graphicsView->width() / 2.0, (float)this->ui->graphicsView->height() / 2.0);
    QPixmap pm(ui->graphicsView->size());
    QPainter pn(&pm);
    // очистка
    pn.fillRect(QRectF(0.0, 0.0, this->ui->graphicsView->width(), this->ui->graphicsView->height()), QBrush(Qt::white));
    // рисуем вершины вокруг центра
    for (int i = 0; i < Quantity; i++)
    {
        QBrush br(QColor(205, 0, 0));
        QPen pen(QBrush(QColor(205, 0, 0)), 2.0);
        pn.setBrush(br);
        // кружок
        pn.drawEllipse(ctr + QPointF(125.0 * cos(2.0 * pi * i / (float)Quantity), 125.0 * sin(2.0 * pi * i / (float)Quantity)), 15.0, 15.0);
        pn.setPen(QPen(QBrush(Qt::white), 1.0));
        // и текст в нем (т. е. ключ)
        pn.drawText(ctr + QPointF(125.0 * cos(2.0 * pi * i / (float)Quantity), 125.0 * sin(2.0 * pi * i /(float)Quantity)) + QPointF(-4.0, 4.0), QString::number(i+1));
    }
    QBrush br(QColor(139, 69, 19));
    QPen pen(QBrush(Qt::black), 2.0);
    pn.setBrush(br);
    pn.drawEllipse(ctr, 100.0, 100.0);
    sc->addPixmap(pm);
}
// Старт игры
void MainWindow::on_btnStart_clicked()
{
    bool f=true;
    timed=1;
    ui->listWidget->addItem("День");
    ui->listWidget->addItem("Жители знакомятся");
    casting();
    Table(f);
}
// Вызов шага игры
void MainWindow::on_btnNext_clicked()
{
    Course();
}
// Шаг игры
void MainWindow::Course()
{
    bool fl=true;
    int *victim;
    int v, f;
    int vict[16];
    int gamers[16][N-1];
    int max,imax,omax,iomax;
    QString s;
    victim=new int[Quantity];
    for(int i=0;i<Quantity;i++)
    {   for(int j=0;j<N-1;j++)
            switch (j)
            {
                case 0:{
                        gamers[i][0]=Gamers[i].getoratory();
                        break;
                       }
                case 1:{
                        gamers[i][1]=Gamers[i].getluck();
                        break;
                       }
                case 2:{
                        gamers[i][2]=Gamers[i].getacting();
                        break;
                       }
                case 3:{
                        gamers[i][3]=Gamers[i].getconformality();
                        break;
                       }
                case 4:{
                        gamers[i][4]=Gamers[i].getrole();
                        break;
                       }
                case 5:{
                        gamers[i][5]=Gamers[i].getstatus();
                        break;
                       }
                default: break;
             }
    }
    for(int i=0;i<Quantity;i++)
        victim[i]=0;
    if(timed==1)
    {
        ui->listWidget->addItem("Ночь");
        for(int i=0;i<Quantity;i++)
            if(Gamers[i].getstatus()==0 && Gamers[i].getrole()==1)
            {
                v=Gamers[i].course(timed,gamers,Quantity,i,f);
                victim[v]+=1;
            }
        max=victim[0];
        imax=0;
        for(int i=1;i<Quantity;i++)
        if(victim[i]>max)
        {
            max=victim[i];
            imax=i;
        }
        Gamers[imax].amendstatus(timed);
        s="Мафия убила мирного "+QString::fromStdString(Gamers[imax].getName());
        ui->listWidget->addItem(s);
        Graphic();
        Table(fl);
        if(difference()==1)
        {
            QMessageBox mbox;
                mbox.setText("Победила мафия");
                mbox.exec();
                ui->pushButton_2->setEnabled(false);
        }
        else
        {
            timed=0;
        }
    }
    else
    {
        ui->listWidget->addItem("День");
        f=0;
        for(int i=0;i<Quantity;i++)
            if(Gamers[i].getstatus()==0)
            {
                v=Gamers[i].course(timed,gamers,Quantity,i,f);
                victim[v]+=1;
                vict[i]=v;
                if(f==0)
                    f=1;
                else
                    f=0;
            }
        omax=1;
        for(int i=0;i<Quantity;i++)
            if(Gamers[i].getoratory()>omax && Gamers[i].getstatus()==0)
            {
                omax=Gamers[i].getoratory();
                iomax=i;
            }
        for(int i=0;i<Quantity;i++)
        {
            if(Gamers[i].getconformality()>5 && Gamers[i].getstatus()==0)
            {
                if(Gamers[i].getstatus()==1)
                {
                    if(Gamers[vict[iomax]].getrole()==0)
                    {
                        victim[vict[i]]--;
                        vict[i]=vict[iomax];
                        victim[vict[i]]++;
                    }
                }
                else
                {
                    if(i!=vict[iomax])
                    {
                        victim[vict[i]]--;
                        vict[i]=vict[iomax];
                        victim[vict[i]]++;
                    }
                }
            }
        }
        for(int i=0;i<Quantity;i++)
        {
            if(Gamers[i].getstatus()==0)
            {
                s="Житель "+QString::fromStdString(Gamers[i].getName())+" проголосовал за "+QString::fromStdString(Gamers[vict[i]].getName());
                ui->listWidget->addItem(s);
            }
        }
        max=victim[0];
        imax=0;
        for(int i=1;i<Quantity;i++)
          if(victim[i]>max)
            {
                max=victim[i];
                imax=i;
            }
        Gamers[imax].amendstatus(timed);
        s="Жители посадили ";
        if(Gamers[imax].getrole()==0)
            s+="мирного "+QString::fromStdString(Gamers[imax].getName());
        else
            s+="мафиози "+QString::fromStdString(Gamers[imax].getName());
        ui->listWidget->addItem(s);
        Graphic();
        Table(fl);
        if(difference()==1)
        {
            QMessageBox mbox;
                mbox.setText("Победила мафия");
                mbox.exec();
                ui->pushButton_2->setEnabled(false);
        }
         else
            if(difference()==2)
            {
                QMessageBox mbox;
                    mbox.setText("Победили мирные жители");
                    mbox.exec();
                    ui->pushButton_2->setEnabled(false);
            }
            else
            {
                timed=1;
            }
    }

}
// Считывание записей об игроках из файла
void MainWindow::Load()
{
    int num, num2, num3, num4, num5;
    string s;
    ifstream inp("C:\\My Proj\\Pracktika\\Gamer.txt");
    if (inp.is_open())
    {
        if (inp >> num)
        {   Quantity=num;
            for (int i = 0; i < num; i++)
            {

                if ((inp >> s)&&(inp >> num2) && (inp >> num3) && (inp >> num4) && (inp >> num5))
                {
                    if((num2>Min && num2<Max) && (num3>Min && num3<Max)&&(num4>Min && num4<Max)&&(num5>Min && num5<Max))
                    {
                        new( &Gamers[i])Gamer(s,num2,num3,num4,num5);
                    }
                    else
                    {
                        QMessageBox mbox;
                            mbox.setText("Ошибка. Неверная характеристика игрока.");
                            mbox.exec();
                            delete ui;
                    }
                }
                else return;
            }
        }
        else return;
    }
    else return;
}
// Графическое отображение игроков
void MainWindow::Graphic()
{
    sc->clear();
    QPointF ctr((float)this->ui->graphicsView->width() / 2.0, (float)this->ui->graphicsView->height() / 2.0);
    QPixmap pm(ui->graphicsView->size());
    QPainter pn(&pm);
    // очистка
    pn.fillRect(QRectF(0.0, 0.0, this->ui->graphicsView->width(), this->ui->graphicsView->height()), QBrush(Qt::white));
    // рисуем вершины вокруг центра
    for (int i= 0; i < Quantity; i++)
    {

        if(Gamers[i].getstatus()==0)
        {
            QBrush br(QColor(205, 0, 0));
            QPen pen(QBrush(QColor(205, 0, 0)), 2.0);
            pn.setBrush(br);
            // кружок
            pn.drawEllipse(ctr + QPointF(125.0 * cos(2.0 * pi * i / (float)Quantity), 125.0 * sin(2.0 * pi * i / (float)Quantity)), 15.0, 15.0);
            pn.setPen(QPen(QBrush(Qt::white), 1.0));
            // и текст в нем (т. е. ключ)
            pn.drawText(ctr + QPointF(125.0 * cos(2.0 * pi * i / (float)Quantity), 125.0 * sin(2.0 * pi * i /(float)Quantity)) + QPointF(-4.0, 4.0), QString::number(i+1));
        }

    }
    QBrush br(QColor(139, 69, 19));
    QPen pen(QBrush(Qt::black), 2.0);
    pn.setBrush(br);
    pn.drawEllipse(ctr, 100.0, 100.0);
    sc->addPixmap(pm);
}
// Информация об игроках в виде таблицы
void MainWindow::Table(bool f)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList () << "Имя" << "Красноречие" << "Удача" << "Актерское мастерство" << "Конформность" << "Роль" << "Статус");
    ui->tableWidget->horizontalHeader()->resizeSection(3,150);
    ui->tableWidget->horizontalHeader()->resizeSection(6,110);
    ui->tableWidget->setRowCount(Quantity);
    QTableWidgetItem *item;
    for(int i=0;i<Quantity;i++)
        for(int j=0;j<N;j++)
        {
            switch (j)
            {
                case 0:{
                        string s=Gamers[i].getName();
                        item=new QTableWidgetItem(QString::fromStdString(s));
                        break;
                       }
                case 1:{
                        int s=Gamers[i].getoratory();
                        item=new QTableWidgetItem(QString::number(s));
                        break;
                       }
                case 2:{
                        int s=Gamers[i].getluck();
                        item=new QTableWidgetItem(QString::number(s));
                        break;
                       }
                case 3:{
                        int s=Gamers[i].getacting();
                        item=new QTableWidgetItem(QString::number(s));
                        break;
                       }
                case 4:{
                        int s=Gamers[i].getconformality();
                        item=new QTableWidgetItem(QString::number(s));
                        break;
                       }
                case 5:{

                        if(f==false)
                            item=new QTableWidgetItem("");
                        else
                       {
                            int s=Gamers[i].getrole();
                            if(s==0)
                                item=new QTableWidgetItem("Мирный");
                            else
                                item=new QTableWidgetItem("Мафия");
                       }
                        break;
                       }
                case 6:{
                        int s=Gamers[i].getstatus();
                        if(s==0)
                            item=new QTableWidgetItem("Играет");
                        else
                            if(s==1)
                                item=new QTableWidgetItem("Умер");
                            else
                                item=new QTableWidgetItem("В тюрме");
                        break;
                       }
                default: break;
            }

            ui->tableWidget->setItem(i, j, item);
        }
}
// Разница между количеством мирных и мафии
int MainWindow::difference()
{
    int maf, civilian;
    maf=civilian=0;
    for(int i=0;i<Quantity;i++)
        if(Gamers[i].getstatus()==0)
        {
            if(Gamers[i].getrole()==0)
                civilian++;
            else
                maf++;
        }
    if(maf==0)
        return 2;
    if(maf>=civilian)
        return 1;
    else
        return 0;
}
//  Распределение ролей
void MainWindow::casting()
{
    int qmaf;
    int *quantm;
    bool f;
    qmaf=Quantity/3;
    quantm=new int[qmaf];
    srand(time(NULL));
    quantm[0]=rand() % Quantity;
    for(int i=0;i<qmaf;i++)
    {
        do{
            quantm[i]=rand() % Quantity;
            f=true;
            for(int j=0;j<i;j++)
                if(quantm[i]==quantm[j])
                    f=false;

        }while(f==false);
    }
    for(int i=0;i<qmaf;i++)
        Gamers[quantm[i]].amendrole();
}
// Деструктор формы
MainWindow::~MainWindow()
{
    delete ui;
}
// Методы класса игрок
//
Gamer::Gamer(string N,int o,int l,int a,int c)
{
    name=N;
    oratory=o;
    luck=l;
    acting=a;
    conformality=c;
    status=0;
    role=new Civilian;
}
Gamer::Gamer()
{
    name="";
    oratory=0;
    luck=0;
    acting=0;
    conformality=0;
    status=0;
    role=new Civilian;
}
// Возврат имени игрока
string Gamer:: getName()
{
    return name;
}
// Возврат красноречия
int Gamer:: getoratory()
{
    return oratory;
}
// Возврат удачи
int Gamer:: getluck()
{
    return luck;
}
// Возврат актерского мастерства
int Gamer:: getacting()
{
    return acting;
}
// Возврат конформности
int Gamer:: getconformality()
{
    return conformality;
}
// Возврат статуса
int Gamer:: getstatus()
{
    return status;
}
// Возврат роли
int Gamer:: getrole()
{
   return role->getrole();
}
//
int Gamer::course(int time,int (*gamers)[N-1],int Quantity,int gamer,int f)
{
    return role->course(time,gamers,Quantity,gamer,f);
}
// Изменение роли
void Gamer::amendrole()
{
    delete role;
    role=new Mafia();
}
// Изменение статуса
void Gamer::amendstatus(int time)
{
    if(time==0)
        this->status=2;
    else
        this->status=1;
}
// Методы класса мирный житель
//
int Civilian::course(int time,int (*gamers)[N-1],int Quantity,int gamer,int f)
{
    Civilian *c = new Civilian;
    if(time==0)
       return c->vote(gamers, Quantity,gamer,f);
    else
        return 0;
}
// Возврат роли
int Civilian::getrole()
{
    return 0;
}
// Дневное голосование
int Civilian::vote(int (*gamers)[N-1],int Quantity,int gamer,int f)
{
    int j=2;
    int min=10, imin;
    if(f==0)
    {
        for(int i=0;i<Quantity;i++)
        {
            if(i!=gamer)
            {
                if((gamers[i][j]<min) && (gamers[i][j+3]==0))
                {
                    min=gamers[i][j];
                    imin=i;
                }
            }
        }
    }
    else
    {
        srand(time(NULL));
        imin=rand() % Quantity;
        for(int i=0;(imin==gamer)||(gamers[imin][j+3]!=0);i++)
            imin=rand() % Quantity;
    }
    return imin;
}
//Методы класса мафия
//
int Mafia::course(int time,int (*gamers)[N-1],int Quantity,int gamer,int f)
{

    Mafia *m=new Mafia;
    if(time==0)
       return m->vote(gamers,Quantity);
    else
       return m->kill(gamers,Quantity);
}
// Возврат роли
int Mafia::getrole()
{
    return 1;
}
// Выбор жертвы
int Mafia::kill(int (*gamers)[N-1],int Quantity)
{
    int j=1;
    int min=10, imin;
    for(int i=0;i<Quantity;i++)
    {
        if(gamers[i][j+3]==0)
        {
            if((gamers[i][j]<min) && (gamers[i][j+4]==0))
            {
                min=gamers[i][j];
                imin=i;
            }
        }
    }
    return imin;
}
// Дневное голосование
int Mafia::vote(int (*gamers)[N-1],int Quantity)
{
    int j=1,k=0;
    int min, imin;
    do{
        min=gamers[k][j];
        imin=k;
        k++;
    }while(gamers[k-1][j+4]!=0 && gamers[k-1][j+3]!=0);
    for(int i=k;i<Quantity;i++)
    {
        if((gamers[i][j]<min) && (gamers[i][j+4]==0) && (gamers[i][j+3]==0))
        {
            min=gamers[i][j];
            imin=i;
        }
    }
    return imin;
}
