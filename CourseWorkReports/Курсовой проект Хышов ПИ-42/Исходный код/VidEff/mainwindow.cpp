#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	sc = new QGraphicsScene(ui->graphView);
	ui->graphView->setScene(sc);
	sc->clear();
	playTimer = new QTimer(this);
	playTimer->setInterval(24);
	connect(playTimer, SIGNAL(timeout()), this, SLOT(changeFrame()));
	statusLbl = new QLabel("");
	statusBar()->addWidget(statusLbl);
	msgTimer = new QTimer(this);
	msgTimer->setInterval(2000);
	connect(msgTimer, SIGNAL(timeout()), this, SLOT(msgFade()));
}

QImage MainWindow::convertFrame(Frame *frame)
{
	int w = frame->width(), h = frame->height();
	QImage result = QImage(w, h, QImage::Format_RGBA8888);
	uint32_t *data = frame->getData();
	Color c;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			c.rgba = data[i * w + j];
			int r = c.r();
			int g = c.g();
			int b = c.b();
			result.setPixel(j, i, QColor(r, g, b).rgb());
		}
	}
	return result;
}

void MainWindow::msgShow(QString msg)
{
	statusLbl->setText(msg);
	msgTimer->singleShot(2000, this, SLOT(msgFade()));
}

void MainWindow::updateTrackList()
{
	ui->listTracks->clear();
	MediaProject *mp = MediaProject::getInstance();
	vector<TrackInfo> tracks = mp->getTracksInfo();
	int sizeInt = tracks.size();
	for (int i = 0; i < sizeInt; i++)
	{
		TrackInfo tInfo = tracks[i];
		ui->listTracks->addItem(QString("(%1) %2 frm, %3 clips").arg(i + 1).arg(tInfo.length).arg(tInfo.numClips));
	}
}

void MainWindow::updateClipList()
{
	ui->listClips->clear();
	MediaProject *mp = MediaProject::getInstance();
	if (ui->listTracks->currentRow() < 0 || ui->listTracks->currentRow() >= mp->getTracksNum())
		return;
	vector<ClipInfo> clips = mp->getClipsInfo(ui->listTracks->currentRow());
	int sizeInt = clips.size();
	for (int i = 0; i < sizeInt; i++)
	{
		ClipInfo cInfo = clips[i];
		ui->listClips->addItem(QString("(%1) %2 frm, type %3").arg(i + 1).arg(cInfo.frames).arg(cInfo.ctype));
	}
}

void MainWindow::updateEffectList()
{
	ui->listEffects->clear();
	MediaProject *mp = MediaProject::getInstance();
	int track = ui->listTracks->currentRow();
	if (track == -1)
	{
		return;
	}
	int idx = ui->listClips->currentRow();
	if (idx == -1)
	{
		return;
	}
	vector<FilterEntry> usedFilters = mp->getUsedFilters(track, idx);
	int sizeInt = usedFilters.size();
	for (int i = 0; i < sizeInt; i++)
	{
		ui->listEffects->addItem(QString::fromStdWString(usedFilters[i].flt));
	}
}

void MainWindow::updateFrame()
{
	MediaProject *mp = MediaProject::getInstance();
	Frame *frame = mp->getCurrentFrame();
	QImage img = convertFrame(frame);
	delete frame;
	sc->clear();
	sc->addPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::changeFrame()
{
	MediaProject *mp = MediaProject::getInstance();
	bool ok = mp->movePtr(1);
	ui->lcdFrame->display(mp->getFramePtr());
	Frame *frame = mp->getCurrentFrame();
	QImage img = convertFrame(frame);
	delete frame;
	sc->clear();
	sc->addPixmap(QPixmap::fromImage(img));
	if (!ok)
	{
		mp->seek(0);
		playTimer->stop();
	}
}

void MainWindow::msgFade()
{
	statusLbl->setText("");
}

void MainWindow::on_btnLoad_clicked()
{
	MediaProject *mp = MediaProject::getInstance();
	ProjectData projData = mp->getProjectData();
	Frame *frame;
	QFileDialog *fileDlg = new QFileDialog(this, tr("Загрузить..."), QString(), tr("Изображения (*.bmp *.jpg *.png)"));
	QString fname;
	if (fileDlg->exec())
		fname = fileDlg->selectedFiles().at(0);
	if (fname.isNull() || fname.isEmpty())
		return;
	QImage img = QImage(fname).scaled(projData.w, projData.h);
	QImage icon = img.scaledToHeight(48);
	int w = img.width(), h = img.height();
	Color c;
	frame = new Frame(w, h, nullptr);
	uint32_t *frameData = frame->getData();
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			QRgb rgb = img.pixel(j, i);
			QColor srcCol = QColor(rgb);
			c.setR(srcCol.red());
			c.setG(srcCol.green());
			c.setB(srcCol.blue());
			c.setA(srcCol.alpha());
			frameData[i * w + j] = c.rgba;
		}
	}
	Picture *pict = new Picture(frame);
	int uid = pict->getUID();
	icons[uid] = icon;
	QListWidgetItem *wi = new QListWidgetItem(QIcon(QPixmap::fromImage(img)), QString::number(uid, 16));
	items[uid] = wi;
	ui->listBin->addItem(wi);
	mp->addSource(pict);
}

void MainWindow::on_actionNew_triggered()
{
	DialogNewProject *dnp = new DialogNewProject(this);
	int res = dnp->exec();
	ProjectData projData;
	if (res != QDialog::Accepted)
		return;
	projData = dnp->projData;
	MediaProject *mp = MediaProject::getInstance();
	mp->reset(projData.w, projData.h, projData.framerate);
	playTimer->setInterval(1000 / projData.framerate);
	sc->clear();
}

void MainWindow::on_btnDelFromBin_clicked()
{
	QList<QListWidgetItem *> selection = ui->listBin->selectedItems();
	if (selection.empty())
		return;
	for (int i = selection.size() - 1; i >= 0; i--)
	{
		QListWidgetItem *wi = selection.takeAt(i);
		int uid = items.key(wi);
		items.remove(uid);
		icons.remove(uid);
		ui->listBin->removeItemWidget(wi);
		delete wi;
		MediaProject::getInstance()->deleteSource(uid);
	}
	updateFrame();
	updateTrackList();
}

void MainWindow::on_btnAddFromBin_clicked()
{
	QListWidgetItem *wi = ui->listBin->currentItem();
	MediaProject *mp = MediaProject::getInstance();
	int tracksNum = mp->getTracksNum();
	if (tracksNum < 1)
	{
		msgShow("Отсутствуют дорожки!");
		return;
	}
	int idx = ui->listTracks->currentRow();
	int uid = items.key(wi);
	DialogAddClip *addDlg = new DialogAddClip(this);
	int res = addDlg->exec();
	ClipOffsets offsets;
	if (res == QDialog::Accepted)
	{
		offsets = addDlg->offsets;
	}
	else
	{
		return;
	}
	mp->addClip(uid, idx, offsets.initOffset, offsets.offsetStart, offsets.offsetEnd);
	updateTrackList();
	updateFrame();
}

void MainWindow::on_btnTrackAdd_clicked()
{
	MediaProject *mp = MediaProject::getInstance();
	mp->addTrack();
	updateTrackList();
	updateFrame();
}

void MainWindow::on_btnTrackDelete_clicked()
{
	MediaProject *mp = MediaProject::getInstance();
	int idx = ui->listTracks->currentRow();
	if (idx < 0 || idx >= mp->getTracksNum())
		return;
	mp->deleteTrack(idx);
	mp->updateLengths();
	updateTrackList();
	updateFrame();
}

void MainWindow::on_btnPlay_clicked()
{
	if (playTimer->isActive())
		playTimer->stop();
	else
		playTimer->start();
}

void MainWindow::on_listTracks_currentRowChanged(int currentRow)
{
	ui->listClips->clear();
	updateClipList();
}

void MainWindow::on_listClips_currentRowChanged(int currentRow)
{
	ui->listEffects->clear();
	updateEffectList();
}

void MainWindow::on_listEffects_currentRowChanged(int currentRow)
{

}

void MainWindow::on_btnAddEffect_clicked()
{
	MediaProject *mp = MediaProject::getInstance();
	int track = ui->listTracks->currentRow();
	if (track == -1)
	{
		msgShow("Сначала выберите дорожку!");
		return;
	}
	int idx = ui->listClips->currentRow();
	if (idx == -1)
	{
		msgShow("Сначала выберите клип!");
		return;
	}
	DialogAddFilter *fltDlg = new DialogAddFilter(this);
	int res = fltDlg->exec();
	wstring fltName;
	if (res == QDialog::Accepted)
		fltName = fltDlg->fltName;
	else
		return;
	mp->addFilter(track, idx, fltName);
	updateEffectList();
	updateFrame();
}

void MainWindow::on_btnRemoveEffect_clicked()
{
	MediaProject *mp = MediaProject::getInstance();
	int track = ui->listTracks->currentRow();
	if (track == -1)
	{
		msgShow("Сначала выберите дорожку!");
		return;
	}
	int idx = ui->listClips->currentRow();
	if (idx == -1)
	{
		msgShow("Сначала выберите клип!");
		return;
	}
	int fltIdx = ui->listEffects->currentRow();
	if (fltIdx == -1)
		return;
	mp->removeFilter(track, idx, fltIdx);
	updateEffectList();
	updateFrame();
}

void MainWindow::on_btnMakeTransition_clicked()
{
	MediaProject *mp = MediaProject::getInstance();
	int track = ui->listTracks->currentRow();
	if (track == -1)
	{
		msgShow("Сначала выберите дорожку!");
		return;
	}
	int idx = ui->listClips->currentRow();
	if (idx == -1)
	{
		msgShow("Сначала выберите клип!");
		return;
	}
	int clipCnt = mp->getClipsInfo(track).size();
	if (clipCnt < 2)
	{
		msgShow("На дорожке менее 2-х клипов!");
		return;
	}
	DialogAddTransition *transDlg = new DialogAddTransition(this);
	int res = transDlg->exec();
	TransitionData trans;
	if (res == QDialog::Accepted)
		trans = transDlg->transData;
	else
		return;
	delete transDlg;
	int idA, idB;
	if (idx < (clipCnt - 1))
	{
		idA = idx;
		idB = idA + 1;
	}
	else
	{
		idB = idx;
		idA = idx - 1;
	}
	mp->makeTransition(idA, idB, track, trans.name, trans.frames);
	updateClipList();
	updateTrackList();
	updateFrame();
}

void MainWindow::on_btnClipDelete_clicked()
{
	int track = ui->listTracks->currentRow();
	int idx = ui->listClips->currentRow();
	MediaProject *mp = MediaProject::getInstance();
	if (track < 0 || track >= mp->getTracksNum())
		return;
	mp->removeClip(idx, track);
	updateTrackList();
	updateClipList();
	updateFrame();
}

void MainWindow::on_btnStop_clicked()
{
	playTimer->stop();
	MediaProject *mp = MediaProject::getInstance();
	mp->movePtr(0);
	ui->lcdFrame->display(mp->getFramePtr());
	Frame *frame = mp->getCurrentFrame();
	QImage img = convertFrame(frame);
	delete frame;
	sc->clear();
	sc->addPixmap(QPixmap::fromImage(img));
}
