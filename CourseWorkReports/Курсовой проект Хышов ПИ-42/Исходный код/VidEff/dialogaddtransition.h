#ifndef DIALOGADDTRANSITION_H
#define DIALOGADDTRANSITION_H

#include <QDialog>
#include "defs.h"
#include "effectlib.h"

namespace Ui {
	class DialogAddTransition;
}

struct TransitionData
{
		wstring name;
		int frames;
};

class DialogAddTransition : public QDialog
{
		Q_OBJECT

	public:
		explicit DialogAddTransition(QWidget *parent = 0);
		TransitionData transData;
		~DialogAddTransition();

	private slots:
		void on_buttonBox_accepted();

	private:
		Ui::DialogAddTransition *ui;
		vector<EntryDisp> trans;
};

#endif // DIALOGADDTRANSITION_H
