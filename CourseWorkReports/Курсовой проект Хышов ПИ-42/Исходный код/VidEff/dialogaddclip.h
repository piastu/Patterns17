#ifndef DIALOGADDCLIP_H
#define DIALOGADDCLIP_H

#include <QDialog>
#include "clip.h"

namespace Ui {
	class DialogAddClip;
}

class DialogAddClip : public QDialog
{
		Q_OBJECT

	public:
		explicit DialogAddClip(QWidget *parent = 0);
		ClipOffsets offsets;
		~DialogAddClip();

	private slots:
		void on_buttonBox_accepted();

	private:
		Ui::DialogAddClip *ui;
};

#endif // DIALOGADDCLIP_H
