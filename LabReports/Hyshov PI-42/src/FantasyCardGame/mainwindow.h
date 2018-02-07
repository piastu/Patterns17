#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include "gameform.h"
#include "consolegameform.h"
#include "gamecontroller.h"
#include "gamesession.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:
		void on_actionNewGame_triggered();
		void on_actionNewGameConsole_triggered();
		void on_actionExit_triggered();

		void on_actionLoad_triggered();

		void on_actionSave_triggered();

	private:
		Ui::MainWindow *ui;
		QWidget *gf;
		GameSession *gs;
};

#endif // MAINWINDOW_H
