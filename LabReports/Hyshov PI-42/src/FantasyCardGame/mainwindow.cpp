#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	// зададим зерно для генератора случайных чисел
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	ui->setupUi(this);
	gs = GameSession::getInstance(true);
	gf = NULL;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionNewGame_triggered()
{
	if (gf)
		delete gf;
	gf = new GameForm(this);
	gs->reset();
	ui->gridLayout->addWidget(gf);
	gs->installController(dynamic_cast<GameController *>(gf));
	dynamic_cast<GameController *>(gf)->setContext(gs);
}

void MainWindow::on_actionExit_triggered()
{
	QApplication::exit();
}

void MainWindow::on_actionNewGameConsole_triggered()
{
	if (gf)
		delete gf;
	gf = new ConsoleGameForm(this);
	gs->reset();
	ui->gridLayout->addWidget(gf);
	gs->installController(dynamic_cast<GameController *>(gf));
	dynamic_cast<GameController *>(gf)->setContext(gs);
}

void MainWindow::on_actionLoad_triggered()
{
	if (gf == nullptr)
	{
		gf = new GameForm(gf);
		gs->installController(dynamic_cast<GameController *>(gf));
		dynamic_cast<GameController *>(gf)->setContext(gs, false);
	}
	int retCode = gs->loadState();
}

void MainWindow::on_actionSave_triggered()
{
	int retCode = gs->saveState();
}
