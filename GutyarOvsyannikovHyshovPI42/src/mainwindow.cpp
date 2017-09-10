#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	busy = false;
	messageLabel = new QLabel(this);
	statusBar()->addWidget(messageLabel);
	ui->groupControl->setHidden(false);
	ui->comboCounter->setHidden(true);
	ui->comboEmployee->setHidden(true);
	ui->groupCustomers->setHidden(true);
	ui->actionLoad->setEnabled(true);
	ui->actionSave->setEnabled(true);
	ui->listDishes->setEnabled(true);
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	rw = new RenderWidget(this);
	ui->drawLayout->addWidget(rw);
	Model::getInstance().setRoomSize(20, 20);
	connect(&Model::getInstance(), SIGNAL(needsRepaint()), rw, SLOT(update()));
	connect(rw, SIGNAL(clickAtCoord(QPointF, QRectF)), &Model::getInstance(), SLOT(clickAtCoord(QPointF, QRectF)));
	connect(rw, SIGNAL(readyToPaint(QPainter*,QRectF)), &Model::getInstance(), SLOT(Draw(QPainter*,QRectF)));
	connect(&Model::getInstance(), SIGNAL(message(QString)), this, SLOT(receiveModelMessage(QString)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionSetupModel_triggered()
{
	int w, h;
	w = QInputDialog::getInt(this, "Ввод параметров", "Введите ширину (минимум 20)", 20, 20);
	h = QInputDialog::getInt(this, "Ввод параметров", "Введите высоту (минимум 20)", 20, 20);
	Model::getInstance().resetModel(false);
	Model::getInstance().setRoomSize(w, h);
	ui->groupControl->setHidden(false);
	ui->actionLoad->setEnabled(true);
	ui->actionSave->setEnabled(true);
	ui->comboTool->setCurrentIndex(0);
	ui->comboCounter->setHidden(true);
	ui->comboEmployee->setHidden(true);
	ui->actionLoad->setEnabled(true);
	ui->actionSave->setEnabled(true);
	ui->groupPalette->setHidden(false);
	ui->groupStartItems->setHidden(false);
	ui->groupCustomers->setHidden(true);
	ui->btnSetupComplete->setHidden(false);
	ui->listDishes->clear();
	ui->listDishes->setEnabled(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	event->ignore();
	if (busy)
	{
		QMessageBox(QMessageBox::Information, "Ошибка", "В данный момент невозможно выйти: программа занята.\nПопробуйте немного позже.", QMessageBox::Ok, this).exec();
		return;
	}
	QMessageBox *mb = new QMessageBox(QMessageBox::Question, "Выход", "Вы уверены, что хотите выйти?", QMessageBox::Yes | QMessageBox::No, this);
	if (mb->exec() == QMessageBox::Yes && !busy)
	{
		Model::getInstance().resetModel(true);
		event->accept();
	}
}

void MainWindow::on_btnSetupComplete_clicked()
{
	if (Model::getInstance().getTablesCount() == 0)
	{
		QMessageBox(QMessageBox::Information, "Ошибка", "Добавьте хотя бы один стол.", QMessageBox::Ok, this).exec();
		return;
	}
	if (!Model::getInstance().verifyPaths())
	{
		QMessageBox(QMessageBox::Information, "Ошибка", "Один или несколько столов недостижимы.\nПопробуйте изменить схему.", QMessageBox::Ok, this).exec();
		return;
	}
	ui->frameDishManage->setHidden(true);
	ui->groupPalette->setHidden(true);
	ui->groupCustomers->setHidden(false);
	ui->groupStartItems->setHidden(true);
	Model::getInstance().setDesignMode(false);
	Model::getInstance().setEmployeeCellsState(true);
	Model::getInstance().putItems(ui->spinTrays->value(), ui->spinTowels->value(), ui->spinForks->value(), ui->spinSpoons->value(), ui->spinKnives->value());
	ui->btnSetupComplete->setHidden(true);
	ui->actionLoad->setEnabled(false);
	ui->actionSave->setEnabled(false);
	ui->listDishes->setEnabled(false);
	Model::getInstance().activateEmployees();
}

void MainWindow::on_comboTool_currentIndexChanged(int index)
{
	Model::getInstance().setPlacementID(index);
	Model::getInstance().setDesignMode(true);
	if (index < 5)
	{
		ui->comboCounter->setHidden(true);
		ui->comboEmployee->setHidden(true);
	}
	else if (index < 6)
	{
		ui->comboCounter->setHidden(false);
		ui->comboEmployee->setHidden(true);
		Model::getInstance().setPlacementIDSub(ui->comboCounter->currentIndex());
	}
	else
	{
		ui->comboCounter->setHidden(true);
		ui->comboEmployee->setHidden(false);
		Model::getInstance().setPlacementIDSub(ui->comboEmployee->currentIndex());
	}
}

void MainWindow::on_btnAddCustomer_clicked()
{
	float money = QInputDialog::getDouble(this, "Добавление покупателя", "Сколько денег?", 150.0, 10.0);
	Model::getInstance().addCustomer(money);
}

void MainWindow::on_comboCounter_currentIndexChanged(int index)
{
	Model::getInstance().setPlacementIDSub(index);
}

void MainWindow::on_comboEmployee_currentIndexChanged(int index)
{
	Model::getInstance().setPlacementIDSub(index);
}

void MainWindow::on_btnDeleteAll_clicked()
{
	Model::getInstance().resetModel(false);
	rw->update();
}

void MainWindow::on_actionLoad_triggered()
{
	QString fName = QFileDialog::getOpenFileName(this, "Загрузка...", QDir::currentPath());
	if (!fName.isNull())
	{
		QFile fin;
		fin.setFileName(fName);
		fin.open(QFile::ReadOnly);
		QDataStream inp(&fin);
		if (!Model::getInstance().readFromStream(inp))
			QMessageBox(QMessageBox::Information, "Ошибка", "Невозможно загрузить схему из файла.", QMessageBox::Ok, this).exec();
		fin.close();
		ui->listDishes->clear();
		int nr = 0;
		while (Model::getInstance().getDish(nr) != NULL)
		{
			ui->listDishes->addItem(Model::getInstance().getDish(nr)->getName());
			nr++;
		}
		rw->update();
	}
}

void MainWindow::on_actionSave_triggered()
{
	QString fName = QFileDialog::getSaveFileName(this, "Сохранение...", QDir::currentPath());
	if (!fName.isNull())
	{
		QFile fout;
		fout.setFileName(fName);
		fout.open(QFile::WriteOnly | QFile::Truncate);
		if (!fout.isOpen())
		{
			QMessageBox(QMessageBox::Information, "Ошибка", "Невозможно открыть файл.", QMessageBox::Ok, this).exec();
			return;
		}
		QDataStream out(&fout);
		if (!Model::getInstance().writeToStream(out))
			QMessageBox(QMessageBox::Information, "Ошибка", "Невозможно сохранить схему в файл.", QMessageBox::Ok, this).exec();
		fout.close();
	}
}
void MainWindow::on_btnAddDish_clicked()
{
	DialogDish *dd = new DialogDish(this);
	if (dd->exec() == QDialog::Accepted)
	{
		Model::getInstance().addDish(dd->getDish());
		ui->listDishes->addItem(dd->getDish()->getName());
	}
	delete dd;
}

void MainWindow::on_btnRemoveDish_clicked()
{
	if (ui->listDishes->currentRow() != -1)
	{
		Model::getInstance().deleteDish(ui->listDishes->currentRow());
		delete ui->listDishes->takeItem(ui->listDishes->currentRow());
	}
}

void MainWindow::on_listDishes_itemDoubleClicked(QListWidgetItem *item)
{
	if (ui->listDishes->row(item) == -1)
		return;
	DialogDish *dd = new DialogDish(Model::getInstance().getDish(ui->listDishes->row(item)), this);
	if (dd->exec() == QDialog::Accepted)
	{
		item->setText(dd->getDish()->getName());
	}
	delete dd;
}

void MainWindow::on_btnAddCustomerGroup_clicked()
{
	float money = QInputDialog::getDouble(this, "Добавление покупателей...", "По сколько денег?", 150.0, 10.0);
	int count = QInputDialog::getInt(this, "Добавление посетителей...", "Сколько человек?\n(минимум 2)", 2, 2, 200);
	ui->actionSetupModel->setEnabled(false);
	int group = qrand()%10000;
	busy = true;
	for (int i = 0; i < count; i++)
	{
		doDelay(100);
		Model::getInstance().addCustomerGroup(money, group);
	}
	ui->actionSetupModel->setEnabled(true);
	busy = false;
}

void MainWindow::receiveModelMessage(QString msg)
{
	messageLabel->setText(msg);
	ui->listLog->addItem("[" + QTime::currentTime().toString("hh:mm:ss.zzz") + "] " + msg);
	ui->listLog->scrollToBottom();
}

void MainWindow::on_btnShowHideLog_clicked()
{
	ui->listLog->setHidden(!ui->listLog->isHidden());
	ui->btnClearLog->setHidden(!ui->btnClearLog->isHidden());
}

void MainWindow::on_btnClearLog_clicked()
{
	ui->listLog->clear();
}
