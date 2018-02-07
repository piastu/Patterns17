#include "dialogaddfilter.h"
#include "ui_dialogaddfilter.h"

DialogAddFilter::DialogAddFilter(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogAddFilter)
{
	ui->setupUi(this);
	filters = EffectLib::getInstance()->getAvailableFilters();
	int sizeInt = filters.size();
	for (int i = 0; i < sizeInt; i++)
	{
		ui->cbFlt->addItem(QString::fromStdWString(filters[i].displayName));
	}
}

DialogAddFilter::~DialogAddFilter()
{
	delete ui;
}

void DialogAddFilter::on_buttonBox_accepted()
{
	fltName = filters[ui->cbFlt->currentIndex()].name;
}
