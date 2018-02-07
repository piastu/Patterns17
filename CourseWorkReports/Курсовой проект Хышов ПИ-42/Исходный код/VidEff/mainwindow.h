#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QTimer>
#include <QLabel>
#include "mediaproject.h"
#include "dialognewproject.h"
#include "dialogaddclip.h"
#include "dialogaddtransition.h"
#include "dialogaddfilter.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);

		~MainWindow();

	public slots:
		void changeFrame();
		void msgFade();
	private slots:
		void on_btnLoad_clicked();
		void on_actionNew_triggered();
		void on_btnDelFromBin_clicked();

		void on_btnAddFromBin_clicked();

		void on_btnTrackAdd_clicked();

		void on_btnTrackDelete_clicked();

		void on_btnPlay_clicked();

		void on_listTracks_currentRowChanged(int currentRow);

		void on_listClips_currentRowChanged(int currentRow);

		void on_listEffects_currentRowChanged(int currentRow);

		void on_btnAddEffect_clicked();

		void on_btnRemoveEffect_clicked();

		void on_btnMakeTransition_clicked();

		void on_btnClipDelete_clicked();

		void on_btnStop_clicked();

	private:
		QMap<int, QImage> icons;
		QMap<int, QListWidgetItem *> items;
		QGraphicsScene *sc;
		QTimer *playTimer, *msgTimer;
		QLabel *statusLbl;
		Ui::MainWindow *ui;
		QImage convertFrame(Frame *frame);
		void msgShow(QString msg);
		void updateTrackList();
		void updateClipList();
		void updateEffectList();
		void updateFrame();
};

#endif // MAINWINDOW_H
