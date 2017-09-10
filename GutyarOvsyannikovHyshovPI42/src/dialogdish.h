#ifndef DIALOGDISH_H
#define DIALOGDISH_H

#include <QDialog>
#include <QMessageBox>
#include <dish.h>

namespace Ui {
	class DialogDish;
}

class DialogDish : public QDialog
{
		Q_OBJECT

	public:
		explicit DialogDish(QWidget *parent = 0);
		explicit DialogDish(Dish *src, QWidget *parent = 0);
		~DialogDish();
		Dish * getDish();

	private slots:
		void on_btnOK_clicked();
		void on_btnCancel_clicked();

	private:
		Ui::DialogDish *ui;
		Dish *dish;
		bool editMode;
};

#endif // DIALOGDISH_H
