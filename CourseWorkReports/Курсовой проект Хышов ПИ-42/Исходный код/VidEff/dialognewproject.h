#ifndef DIALOGNEWPROJECT_H
#define DIALOGNEWPROJECT_H

#include <QDialog>
#include "mediaproject.h"

namespace Ui {
	class DialogNewProject;
}

class DialogNewProject : public QDialog
{
		Q_OBJECT

	public:
		explicit DialogNewProject(QWidget *parent = 0);
		ProjectData projData;
		~DialogNewProject();

	private slots:
		void on_buttonBox_accepted();

	private:
		Ui::DialogNewProject *ui;
};

#endif // DIALOGNEWPROJECT_H
