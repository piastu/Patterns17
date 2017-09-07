#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    use=false;
    countSurvaiv=0;
    countDead=0;
    count=0;
    countHumen=0;
    createMenu();
    gw=new QGraphicsView(ui->centralWidget);
    gw->hide();
    gw->resize(305,305);
    gw->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gw->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sc=new QGraphicsScene();
    gw->setScene(sc);
    hideButton();
    ui->stopButton->hide();
    ui->label->hide();
}

void MainWindow::newRoom()
{
    if(use)
    {
        sc->clear();
        countSurvaiv=0;
        countDead=0;
        count=0;
        countHumen=0;
        for(int i=0;i<roomMatrica[i].size();i++)
            roomMatrica[i].clear();
        roomMatrica.clear();
        bodys.clear();
        burn.clear();
    }
    Dialog dialog;
    dialog.show();
    this->hide();
    dialog.exec(); // показываем диалог, здесь стоим, пока диалог не закроют
    this->show();
    if(dialog.getUsed())
    {
        use=true;
        house=new room(dialog.getHeight(),dialog.getWidht(),dialog.getStep());
        int height=house->getH();
        int width=house->getW();
        int step=house->getS();
        QList<int> temp;
        temp.clear();
        for(int i=0;i<width/step;i++)
        {
            if(i==0 || i==width/step-1)
            {
                for(int j=0;j<height/step;j++)
                    temp.push_back(1);
            }
            else
            {
                for(int j=0;j<height/step;j++)
                    if(j==0 || j==height/step-1)
                        temp.push_back(1);
                    else
                        temp.push_back(0);
            }
            roomMatrica.push_back(temp);
            temp.clear();
        }
        gw->show();
        sc->setSceneRect(-5,-5,height+10,width+10);
        gw->resize(height+10,width+10);
        sc->addRect(0,0,step,width,QPen(Qt::NoPen),QBrush(Qt::gray));
        sc->addRect(height-step,0,step,width,QPen(Qt::NoPen),QBrush(Qt::gray));
        sc->addRect(step,0,height-step,step,QPen(Qt::NoPen),QBrush(Qt::gray));
        sc->addRect(0,width-step,height-step,step,QPen(Qt::NoPen),QBrush(Qt::gray));
        int xNow=0,yNow=0;
        for(int i=0;i<=width/step;i++)
        {
            sc->addLine(0,yNow,height,yNow);
            yNow+=step;
        }
        for(int i=0;i<=height/step;i++)
        {
            sc->addLine(xNow,0,xNow,width);
            xNow+=step;
        }
        showButton();
    }
}

void MainWindow::loadRoom()
{

}

void MainWindow::saveRoom()
{

}

void MainWindow::Exit()
{
    if(use)
    {
        DialogUse dialog;
        dialog.show();
        this->hide();
        dialog.exec();
        if(dialog.getUsed())
            this->close();
        else
            this->show();
    }
    else
    {
        this->close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addHumen_clicked(bool checked)
{
    if(checked)
    {
        ui->addWall->setChecked(false);
        ui->addExit->setChecked(false);
        ui->addFire->setChecked(false);
        ui->deleteButton->setChecked(false);
    }
}

void MainWindow::on_addWall_clicked(bool checked)
{
    if(checked)
    {
        ui->addHumen->setChecked(false);
        ui->addExit->setChecked(false);
        ui->addFire->setChecked(false);
        ui->deleteButton->setChecked(false);
    }
}

void MainWindow::on_addExit_clicked(bool checked)
{
    if(checked)
    {
        ui->addWall->setChecked(false);
        ui->addHumen->setChecked(false);
        ui->addFire->setChecked(false);
        ui->deleteButton->setChecked(false);
    }
}

void MainWindow::on_addFire_clicked(bool checked)
{
    if(checked)
    {
        ui->addWall->setChecked(false);
        ui->addExit->setChecked(false);
        ui->addHumen->setChecked(false);
        ui->deleteButton->setChecked(false);
    }
}

void MainWindow::on_deleteButton_clicked(bool checked)
{
    if(checked)
    {
        ui->addWall->setChecked(false);
        ui->addExit->setChecked(false);
        ui->addHumen->setChecked(false);
        ui->addFire->setChecked(false);
    }
}

void MainWindow::createMenu()
{
    QMenu *menuFile=new QMenu("File");
    QAction *newAction = new QAction("New",menuFile);
    //QAction *loadAction = new QAction("Load",menuFile);
    //QAction *saveAction = new QAction("Save",menuFile);
    QAction *exitAction = new QAction("Exit",menuFile);
    menuFile->addAction(newAction);
    //menuFile->addAction(loadAction);
    //menuFile->addAction(saveAction);
    menuFile->addAction(exitAction);
    ui->menuBar->addMenu(menuFile);
    connect(newAction, SIGNAL(triggered()), this, SLOT(newRoom()));
    //connect(loadAction, SIGNAL(triggered()), this, SLOT(loadRoom()));
    //connect(saveAction, SIGNAL(triggered()), this, SLOT(saveRoom()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(Exit()));
}

void MainWindow::mousePressEvent(QMouseEvent* mouseEvent)
{
    QString string=QString::number(bodys.size());
    ui->label_2->setText(string);
    if((mouseEvent->button()==Qt::LeftButton) && (mouseEvent->x()<=house->getH()+4 && mouseEvent->x()>=4) && (mouseEvent->y()>=37 && mouseEvent->y()<=house->getW()+37))
    {
        if(ui->addWall->isChecked()==true)//Если выбрано добавление стены
        {
            int x=mouseEvent->x()-4;
            int y=mouseEvent->y()-37;
            int stepX=x/house->getS();
            int stepY=y/house->getS();
            if(roomMatrica[stepY][stepX]==0)
            {
                sc->addRect(stepX*house->getS()+1,stepY*house->getS()+1,house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(Qt::gray));
                roomMatrica[stepY][stepX]=2;
            }
        }
        if(ui->addExit->isChecked()==true)//Если выбрано добавление выхода
        {
            int x=mouseEvent->x()-4;
            int y=mouseEvent->y()-37;
            int stepX=x/house->getS();
            int stepY=y/house->getS();
            if(roomMatrica[stepY][stepX]==1)
            {
                sc->addRect(stepX*house->getS()+1,stepY*house->getS()+1,house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(Qt::darkGreen));
                roomMatrica[stepY][stepX]=4;
            }

        }
        if(ui->deleteButton->isChecked()==true)//Если выбрано удаление
        {
            int x=mouseEvent->x()-4;
            int y=mouseEvent->y()-37;
            int stepX=x/house->getS();
            int stepY=y/house->getS();
            QString a=QString::number(roomMatrica[stepY][stepX]);
            ui->label_2->setText(a);
            if(roomMatrica[stepY][stepX]!=1)
            {
                if(roomMatrica[stepY][stepX]==4)
                {
                    sc->addRect(stepX*house->getS()+1,stepY*house->getS()+1,house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(Qt::gray));
                    roomMatrica[stepY][stepX]=1;
                }
                else
                {
                    if(roomMatrica[stepY][stepX]==2 || roomMatrica[stepY][stepX]==4 || roomMatrica[stepY][stepX]==-1 || roomMatrica[stepY][stepX]==0 || roomMatrica[stepY][stepX]==-2)
                    {
                        bool temp=true;
                        for(int i=0;i<bodys.size();i++)
                        {
                            int stepOne=bodys[i]->getNowPoint().x()/house->getS();
                            int stepTwo=bodys[i]->getNowPoint().y()/house->getS();
                            if(stepY==stepTwo && stepX==stepOne)
                            {
                                bodys[i]->getItem()->hide();
                                bodys.removeAt(i);
                                temp=false;
                            }
                        }
                        if(temp)
                            deliteItem(stepX,stepY,x,y);
                    }
                    else
                    {
                        for(int i=0;i<burn.size();i++)
                        {
                            int x1=burn[i]->getNowPoint().x()/house->getS();
                            int y1=burn[i]->getNowPoint().y()/house->getS();
                            if(y1==stepY && x1==stepX)
                            {
                                burn[i]->getItem()->hide();
                                burn.removeAt(i);
                                if(burn.isEmpty())
                                    ui->addFire->setEnabled(true);
                                roomMatrica[stepY][stepX]=0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(ui->addHumen->isChecked()==true)//Если выбрано добавление человека
        {
            int x=mouseEvent->x()-4;
            int y=mouseEvent->y()-37;
            int stepX=x/house->getS();
            int stepY=y/house->getS();
            if(roomMatrica[stepY][stepX]==0 || roomMatrica[stepY][stepX]==-1)
            {
                Humen=sc->addEllipse(stepX*house->getS()+5,stepY*house->getS()+5,house->getS()-10,house->getS()-10,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
                humen *temp=new humen(stepX*house->getS()+5,stepY*house->getS()+5,Humen);
                bodys.push_back(temp);
            }
        }
        if(ui->addFire->isChecked()==true)//Если выбрано добавление огня
        {
            int x=mouseEvent->x()-4;
            int y=mouseEvent->y()-37;
            int stepX=x/house->getS();
            int stepY=y/house->getS();
            if(roomMatrica[stepY][stepX]==0)
            {

                Fire=sc->addRect(stepX*house->getS()+1,stepY*house->getS()+1,house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(Qt::darkRed));
                fire *temp=new fire(stepX*house->getS()+1,stepY*house->getS()+1,Fire);
                burn.push_back(temp);
                roomMatrica[stepY][stepX]=5;
                ui->addFire->setEnabled(false);
            }
        }
    }
    if(mouseEvent->button()==Qt::RightButton)
    {
        ui->addHumen->setChecked(false);
        ui->addWall->setChecked(false);
        ui->addExit->setChecked(false);
        ui->addFire->setChecked(false);
        ui->deleteButton->setChecked(false);
    }
}

void MainWindow::updateHumen()
{
    if(bodys.isEmpty())
    {
        return;
    }
    for(int i=0;i<bodys.size();i++)
    {
        QPointF pointNow=bodys[i]->getNowPoint();
        QPointF pointEnd=bodys[i]->getEndPoint();
        int stepX=pointNow.x()/house->getS();
        int stepY=pointNow.y()/house->getS();
        if(pointNow==pointEnd)
        {
            if(bodys[i]->getWeyExit())
            {
                bodys[i]->getItem()->hide();
                bodys.removeAt(i);
                countSurvaiv++;
                break;
            }
            if(roomMatrica[stepY][stepX+1]==4 || roomMatrica[stepY][stepX-1]==4 || roomMatrica[stepY+1][stepX]==4 || roomMatrica[stepY-1][stepX]==4)
            {
                if(roomMatrica[stepY][stepX+1]==4)
                {
                    bodys[i]->setAddPoint(5,0);
                    bodys[i]->setEndPoint(pointNow.x()+house->getS(),pointNow.y());

                }
                if(roomMatrica[stepY][stepX-1]==4)
                {
                    bodys[i]->setAddPoint(-5,0);
                    bodys[i]->setEndPoint(pointNow.x()-house->getS(),pointNow.y());
                }
                if(roomMatrica[stepY+1][stepX]==4)
                {
                    bodys[i]->setAddPoint(0,5);
                    bodys[i]->setEndPoint(pointNow.x(),pointNow.y()+house->getS());
                }
                if(roomMatrica[stepY-1][stepX]==4)
                {
                    bodys[i]->setAddPoint(0,-5);
                    bodys[i]->setEndPoint(pointNow.x(),pointNow.y()-house->getS());
                }
                bodys[i]->setWeyExit();
            }
            else
            {
                if((roomMatrica[stepY-1][stepX]==5 || roomMatrica[stepY-1][stepX]==1 || roomMatrica[stepY-1][stepX]==2)
                        && (roomMatrica[stepY+1][stepX]==5 || roomMatrica[stepY+1][stepX]==1 || roomMatrica[stepY+1][stepX]==2)
                        && (roomMatrica[stepY][stepX-1]==5 || roomMatrica[stepY][stepX-1]==1 || roomMatrica[stepY][stepX-1]==2)
                        && (roomMatrica[stepY][stepX+1]==5 || roomMatrica[stepY][stepX+1]==1 || roomMatrica[stepY][stepX+1]==2)
                        && (roomMatrica[stepY-1][stepX-1]==5 || roomMatrica[stepY-1][stepX-1]==1 || roomMatrica[stepY-1][stepX-1]==2)
                        && (roomMatrica[stepY-1][stepX+1]==5 || roomMatrica[stepY-1][stepX+1]==1 || roomMatrica[stepY-1][stepX+1]==2)
                        && (roomMatrica[stepY+1][stepX-1]==5 || roomMatrica[stepY+1][stepX-1]==1 || roomMatrica[stepY+1][stepX-1]==2)
                        && (roomMatrica[stepY+1][stepX+1]==5 || roomMatrica[stepY+1][stepX+1]==1 || roomMatrica[stepY+1][stepX+1]==2))
                {
                    if(stepWey(i,5))
                    {
                        continue;
                    }
                }
                else
                {
                    if(stepWey(i,0))
                    {
                        continue;
                    }
                }
            }
            QPointF tempOne=bodys[i]->getAddStep();
            QPointF tempTwo=bodys[i]->getItem()->pos();
            bodys[i]->getItem()->setPos(tempTwo+tempOne);
            bodys[i]->addPoint();
        }
        else
        {
            QPointF tempOne=bodys[i]->getAddStep();
            QPointF tempTwo=bodys[i]->getItem()->pos();
            bodys[i]->getItem()->setPos(tempTwo+tempOne);
            bodys[i]->addPoint();
        }


    }
    count++;
    if(count==4)
    {
        life();
        count=0;
    }
    QString asurv=QString::number(countSurvaiv);
    QString adead=QString::number(countDead);
    QString alive=QString::number(countHumen);
    ui->label_2->setText(asurv);
    ui->label->setText("Live humen = "+alive+"\n"+"Survivors humen = "+asurv+"\n"+"Dead humen = "+adead);
}

bool MainWindow::stepWey(int it, int number)
{
    QPointF pointNow=bodys[it]->getNowPoint();
    int stepX=pointNow.x()/house->getS();
    int stepY=pointNow.y()/house->getS();
    bool noWey=true;
    int countWay=0;
    do{
        int r=rand()%8+1;
        switch(r)
        {
        case 1:
        {
            if(roomMatrica[stepY-1][stepX]==number || roomMatrica[stepY-1][stepX]==-1)
            {
                bodys[it]->setAddPoint(0,-5);
                bodys[it]->setEndPoint(pointNow.x(),pointNow.y()-house->getS());
                noWey=false;
                countWay=7;
                bodys[it]->getItem()->setZValue(1);
                if(stepX==bodys[it]->getOld().x() && stepY-1==bodys[it]->getOld().y())
                    continue;
                else
                    bodys[it]->setOld(stepX,stepY);
            }
            break;
        }
        case 2:
        {
            if(roomMatrica[stepY][stepX+1]==number || roomMatrica[stepY][stepX+1]==-1)
            {
                bodys[it]->setAddPoint(5,0);
                bodys[it]->setEndPoint(pointNow.x()+house->getS(),pointNow.y());
                noWey=false;
                countWay=7;
                bodys[it]->getItem()->setZValue(1);
                if(stepX+1==bodys[it]->getOld().x() && stepY==bodys[it]->getOld().y())
                    continue;
                else
                    bodys[it]->setOld(stepX,stepY);
            }
            break;
        }
        case 3:
        {
            if(roomMatrica[stepY+1][stepX]==number || roomMatrica[stepY+1][stepX]==-1)
            {
                bodys[it]->setAddPoint(0,5);
                bodys[it]->setEndPoint(pointNow.x(),pointNow.y()+house->getS());
                noWey=false;
                countWay=7;
                bodys[it]->getItem()->setZValue(1);
                if(stepX==bodys[it]->getOld().x() && stepY+1==bodys[it]->getOld().y())
                    continue;
                else
                    bodys[it]->setOld(stepX,stepY);
            }
            break;
        }
        case 4:
        {
            if(roomMatrica[stepY][stepX-1]==number || roomMatrica[stepY][stepX-1]==-1)
            {
                bodys[it]->setAddPoint(-5,0);
                bodys[it]->setEndPoint(pointNow.x()-house->getS(),pointNow.y());
                noWey=false;
                countWay=7;
                bodys[it]->getItem()->setZValue(1);
                if(stepX-1==bodys[it]->getOld().x() && stepY==bodys[it]->getOld().y())
                    continue;
                else
                    bodys[it]->setOld(stepX,stepY);
            }
            break;
        }
        case 5:
        {
            if((roomMatrica[stepY-1][stepX+1]==number || roomMatrica[stepY-1][stepX+1]==-1) && (roomMatrica[stepY][stepX+1]!=2 && roomMatrica[stepY-1][stepX]!=2))
            {
                bodys[it]->setAddPoint(5,-5);
                bodys[it]->setEndPoint(pointNow.x()+house->getS(),pointNow.y()-house->getS());
                noWey=false;
                countWay=7;
                bodys[it]->getItem()->setZValue(1);
                if(stepX+1==bodys[it]->getOld().x() && stepY-1==bodys[it]->getOld().y())
                    continue;
                else
                    bodys[it]->setOld(stepX,stepY);
            }
            break;
        }
        case 6:
        {
            if((roomMatrica[stepY+1][stepX+1]==number || roomMatrica[stepY+1][stepX+1]==-1) && (roomMatrica[stepY+1][stepX]!=2 && roomMatrica[stepY][stepX+1]!=2))
            {
                bodys[it]->setAddPoint(5,5);
                bodys[it]->setEndPoint(pointNow.x()+house->getS(),pointNow.y()+house->getS());
                noWey=false;
                countWay=7;
                bodys[it]->getItem()->setZValue(1);
                if(stepX+1==bodys[it]->getOld().x() && stepY+1==bodys[it]->getOld().y())
                    continue;
                else
                    bodys[it]->setOld(stepX,stepY);
            }
            break;
        }
        case 7:
        {
            if((roomMatrica[stepY+1][stepX-1]==number || roomMatrica[stepY+1][stepX-1]==-1) && (roomMatrica[stepY+1][stepX]!=2 && roomMatrica[stepY][stepX-1]!=2))
            {
                bodys[it]->setAddPoint(-5,5);
                bodys[it]->setEndPoint(pointNow.x()-house->getS(),pointNow.y()+house->getS());
                noWey=false;
                countWay=7;
                bodys[it]->getItem()->setZValue(1);
                if(stepX-1==bodys[it]->getOld().x() && stepY+1==bodys[it]->getOld().y())
                    continue;
                else
                    bodys[it]->setOld(stepX,stepY);
            }
            break;
        }
        case 8:
        {
            if((roomMatrica[stepY-1][stepX-1]==number || roomMatrica[stepY-1][stepX-1]==-1) && (roomMatrica[stepY-1][stepX]!=2 && roomMatrica[stepY][stepX-1]!=2))
            {
                bodys[it]->setAddPoint(-5,-5);
                bodys[it]->setEndPoint(pointNow.x()-house->getS(),pointNow.y()-house->getS());
                noWey=false;
                countWay=7;
                bodys[it]->getItem()->setZValue(1);
                if(stepX-1==bodys[it]->getOld().x() && stepY-1==bodys[it]->getOld().y())
                    continue;
                else
                    bodys[it]->setOld(stepX,stepY);
            }
            break;
        }
        }
        countWay++;
    }while(countWay!=8);
    return noWey;
}


void MainWindow::updateFire()
{
    tempBurn.clear();
    if(burn.isEmpty())
        return;
    else
    {
        QVector<QPointF> tempDelete;
        tempDelete.clear();
        for(int i=0;i<burn.size();i++)
        {
            QPointF nowPoint=burn[i]->getNowPoint();
            int stepX=nowPoint.x()/house->getS();
            int stepY=nowPoint.y()/house->getS();
            if(roomMatrica[stepY-1][stepX]==0)
            {
                Fire=sc->addRect(stepX*house->getS()+1,stepY*house->getS()+1-house->getS(),house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(Qt::darkRed));
                fire *temp=new fire(stepX*house->getS()+1,stepY*house->getS()+1-house->getS(),Fire);
                tempBurn.push_back(temp);
                roomMatrica[stepY-1][stepX]=5;
            }
            if(roomMatrica[stepY+1][stepX]==0)
            {
                Fire=sc->addRect(stepX*house->getS()+1,stepY*house->getS()+1+house->getS(),house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(Qt::darkRed));
                fire *temp=new fire(stepX*house->getS()+1,stepY*house->getS()+1+house->getS(),Fire);
                tempBurn.push_back(temp);
                roomMatrica[stepY+1][stepX]=5;
            }
            if(roomMatrica[stepY][stepX+1]==0)
            {
                Fire=sc->addRect(stepX*house->getS()+1+house->getS(),stepY*house->getS()+1,house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(Qt::darkRed));
                fire *temp=new fire(stepX*house->getS()+1+house->getS(),stepY*house->getS()+1,Fire);
                tempBurn.push_back(temp);
                roomMatrica[stepY][stepX+1]=5;
            }
            if(roomMatrica[stepY][stepX-1]==0)
            {
                Fire=sc->addRect(stepX*house->getS()+1-house->getS(),stepY*house->getS()+1,house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(Qt::darkRed));
                fire *temp=new fire(stepX*house->getS()+1-house->getS(),stepY*house->getS()+1,Fire);
                tempBurn.push_back(temp);
                roomMatrica[stepY][stepX-1]=5;
            }
            burn[i]->deletePower();
            if(burn[i]->getPower()==0)
            {
                roomMatrica[stepY][stepX]=-1;
                Fire=sc->addRect(stepX*house->getS()+1,stepY*house->getS()+1,house->getS()-1,house->getS()-1,QPen(Qt::NoPen),QBrush(QColor(Qt::black).light(200)));
                tempDelete.push_back(burn[i]->getNowPoint());
            }
            if(burn[i]->getPower()==1)
                burn[i]->getItem()->setBrush(Qt::yellow);
            if(burn[i]->getPower()==2)
                burn[i]->getItem()->setBrush(Qt::red);
        }
        burn+=tempBurn;
        if(!tempDelete.isEmpty())
        {
            for(int i=0;i<tempDelete.size();i++)
            {
                for(int j=0;j<burn.size();j++)
                {
                    if(tempDelete[i]==burn[j]->getNowPoint())
                    {
                        burn[j]->getItem()->hide();
                        burn.removeAt(j);
                    }
                }
            }
        }

    }
}

void MainWindow::life()
{
    if(bodys.isEmpty())
        return;
    for(int i=0;i<bodys.size();i++)
    {
        QPointF nowPoint=bodys[i]->getNowPoint();
        int stepX=nowPoint.x()/house->getS();
        int stepY=nowPoint.y()/house->getS();
        if(roomMatrica[stepY][stepX]==5)
        {
            bool life=bodys[i]->deliteHP();
            if(!life)
            {
                bodys[i]->getItem()->setBrush(QBrush(Qt::lightGray));
                bodys[i]->getItem()->setZValue(1);
                bodys[i]->getItem()->hide();
                bodys.removeAt(i);
                countDead++;
                roomMatrica[stepY][stepX]=-2;
            }
            else
            {
                if(bodys[i]->getHP()==75)
                    bodys[i]->getItem()->setBrush(QBrush(Qt::blue));
                if(bodys[i]->getHP()==50)
                    bodys[i]->getItem()->setBrush(QBrush(QColor(Qt::blue).light(150)));
                if(bodys[i]->getHP()==25)
                    bodys[i]->getItem()->setBrush(QBrush(QColor(Qt::blue).light(190)));
            }
        }
    }
}

void MainWindow::on_stopButton_clicked()
{
    ui->stopButton->hide();
    ui->addExit->setChecked(false);
    ui->addHumen->setChecked(false);
    ui->addWall->setChecked(false);
    ui->deleteButton->setChecked(false);
    if(burn.isEmpty())
        ui->addFire->setEnabled(true);
    timerHumen->stop();
    timerFire->stop();
    ui->label->hide();
    showButton();
    //countDead=0;
    //countSpace=0;
}

void MainWindow::deliteItem(int inX, int inY, int x, int y)
{
    QGraphicsRectItem *temp = dynamic_cast < QGraphicsRectItem * > (sc->itemAt(x,y,QTransform()));
    if(temp!=NULL)
    {
        temp->hide();
        roomMatrica[inY][inX]=0;
    }
}

void MainWindow::on_goButton_clicked()
{
    hideButton();
    ui->label->show();
    ui->stopButton->show();
    timerHumen=new QTimer(this);
    timerFire=new QTimer(this);
    connect(timerHumen,SIGNAL(timeout()),this,SLOT(updateHumen()));
    connect(timerFire,SIGNAL(timeout()),this,SLOT(updateFire()));
    countHumen=bodys.size();
    timerHumen->start(20*ui->spinBox->value());
    timerFire->start(1000*ui->spinBox_2->value());
}

void MainWindow::showButton()
{
    ui->addHumen->show();
    ui->addWall->show();
    ui->addExit->show();
    ui->addFire->show();
    ui->deleteButton->show();
    ui->goButton->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->spinBox->show();
    ui->spinBox_2->show();
}

void MainWindow::hideButton()
{
    ui->addHumen->hide();
    ui->addWall->hide();
    ui->addExit->hide();
    ui->addFire->hide();
    ui->deleteButton->hide();
    ui->goButton->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->spinBox->hide();
    ui->spinBox_2->hide();
}
