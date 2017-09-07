#include "dialoguse.h"
#include "ui_dialoguse.h"

DialogUse::DialogUse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUse)
{
    ui->setupUi(this);
}

bool DialogUse::getUsed()
{
    return used;
}

DialogUse::~DialogUse()
{
    delete ui;
    used=false;
}

void DialogUse::on_pushButton_clicked()
{
    used=true;
    this->close();
}

void DialogUse::on_pushButton_2_clicked()
{
    used=false;
    this->close();
}
