#include "dialogaddclip.h"
#include "ui_dialogaddclip.h"

DialogAddClip::DialogAddClip(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogAddClip)
{
	ui->setupUi(this);
}

DialogAddClip::~DialogAddClip()
{
	delete ui;
}

void DialogAddClip::on_buttonBox_accepted()
{
	offsets.initOffset = ui->editInitOffset->text().toInt();
	offsets.offsetStart = ui->editOffsetStart->text().toInt();
	offsets.offsetEnd = ui->editOffsetEnd->text().toInt();
}
