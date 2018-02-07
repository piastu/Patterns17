#include "dialogaddtransition.h"
#include "ui_dialogaddtransition.h"

DialogAddTransition::DialogAddTransition(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogAddTransition)
{
	ui->setupUi(this);
	trans = EffectLib::getInstance()->getAvailableTransitions();
	int sizeInt = trans.size();
	for (int i = 0; i < sizeInt; i++)
	{
		ui->cbTrans->addItem(QString::fromStdWString(trans[i].displayName));
	}
}

DialogAddTransition::~DialogAddTransition()
{
	delete ui;
}

void DialogAddTransition::on_buttonBox_accepted()
{
	transData.frames = ui->editFrames->text().toInt();
	transData.name = trans[ui->cbTrans->currentIndex()].name;
}
