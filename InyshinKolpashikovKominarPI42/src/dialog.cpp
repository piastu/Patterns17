#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->smallRadioButton->hide();
    used=false;
}

int Dialog::getHeight()
{
    return ui->spinBox->value();
}

int Dialog::getWidht()
{
    return ui->spinBox_2->value();
}

int Dialog::getStep()
{
    int step;
    if(ui->bigRadioButton->isChecked()==true)
        step=50;
    if(ui->midiumRadioButton->isChecked()==true)
        step=25;
    if(ui->smallRadioButton->isChecked()==true)
        step=10;
    return step;
}

bool Dialog::getUsed()
{
    return used;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    used=true;
    this->close();
}
