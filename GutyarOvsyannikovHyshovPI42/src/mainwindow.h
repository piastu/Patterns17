#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QPainter>
#include <QMessageBox>
#include <QCloseEvent>
#include <QInputDialog>
#include <QTime>
#include <dialogdish.h>
#include <model.h>
#include <renderwidget.h>
#include <util.h>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		void closeEvent(QCloseEvent *event);

	public slots:
		void receiveModelMessage(QString msg);

	private slots:
		void on_actionSetupModel_triggered();
		void on_btnSetupComplete_clicked();
		void on_comboTool_currentIndexChanged(int index);
		void on_btnAddCustomer_clicked();
		void on_comboCounter_currentIndexChanged(int index);
		void on_comboEmployee_currentIndexChanged(int index);
		void on_btnDeleteAll_clicked();
		void on_actionLoad_triggered();
		void on_actionSave_triggered();
		void on_btnAddDish_clicked();
		void on_btnRemoveDish_clicked();
		void on_listDishes_itemDoubleClicked(QListWidgetItem *item);
		void on_btnAddCustomerGroup_clicked();

		void on_btnShowHideLog_clicked();

		void on_btnClearLog_clicked();

	private:
		Ui::MainWindow *ui;
		RenderWidget *rw;
		QLabel *messageLabel;
		bool busy;
};

#endif // MAINWINDOW_H
