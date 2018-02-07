#include "dialognewproject.h"
#include "ui_dialognewproject.h"

DialogNewProject::DialogNewProject(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogNewProject)
{
	ui->setupUi(this);
}

DialogNewProject::~DialogNewProject()
{
	delete ui;
}

void DialogNewProject::on_buttonBox_accepted()
{
	projData.w = ui->sbWidth->value();
	projData.h = ui->sbHeight->value();
	projData.framerate = ui->sbFramerate->value();
}
