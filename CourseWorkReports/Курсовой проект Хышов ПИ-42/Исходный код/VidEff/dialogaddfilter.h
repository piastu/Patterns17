#ifndef DIALOGADDFILTER_H
#define DIALOGADDFILTER_H

#include <QDialog>
#include "defs.h"
#include "effectlib.h"

namespace Ui {
	class DialogAddFilter;
}

class DialogAddFilter : public QDialog
{
		Q_OBJECT

	public:
		explicit DialogAddFilter(QWidget *parent = 0);
		wstring fltName;
		~DialogAddFilter();

	private slots:
		void on_buttonBox_accepted();

	private:
		Ui::DialogAddFilter *ui;
		vector<EntryDisp> filters;
};

#endif // DIALOGADDFILTER_H
