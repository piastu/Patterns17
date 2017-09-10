#include "dialogdish.h"
#include "ui_dialogdish.h"

DialogDish::DialogDish(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogDish)
{
	ui->setupUi(this);
	editMode = false;
	this->setWindowTitle("Добавление блюда");
}

DialogDish::DialogDish(Dish *src, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogDish)
{
	ui->setupUi(this);
	editMode = true;
	this->setWindowTitle("Изменение блюда");
	dish = src;
	ui->editName->setText(dish->getName());
	ui->spinPrice->setValue(dish->getPrice());
	ui->spinQuantity->setValue(dish->getQuantity());
	ui->spinPopularity->setValue(dish->getPopularity());
	ui->cbFork->setChecked(dish->getReqUtensils().at(0));
	ui->cbSpoon->setChecked(dish->getReqUtensils().at(1));
	ui->cbKnife->setChecked(dish->getReqUtensils().at(2));
}

DialogDish::~DialogDish()
{
	delete ui;
}

void DialogDish::on_btnOK_clicked()
{
	if (ui->editName->text().isEmpty() || ui->editName->text().isNull())
	{
		return;
	}
	if (editMode)
		dish->replaceData(ui->editName->text(), ui->spinPrice->value(), ui->spinQuantity->value(), ui->spinPopularity->value(), QList<bool>({ui->cbFork->isChecked(), ui->cbSpoon->isChecked(), ui->cbKnife->isChecked()}));
	else
		dish = new Dish(ui->editName->text(), ui->spinPrice->value(), ui->spinQuantity->value(), ui->spinPopularity->value(), QList<bool>({ui->cbFork->isChecked(), ui->cbSpoon->isChecked(), ui->cbKnife->isChecked()}));
	accept();
}

void DialogDish::on_btnCancel_clicked()
{
	reject();
}

Dish * DialogDish::getDish()
{
	return (dish != NULL) ? dish : NULL;
}
