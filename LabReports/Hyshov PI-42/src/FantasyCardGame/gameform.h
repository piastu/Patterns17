#ifndef GAMEFORM_H
#define GAMEFORM_H

#include <QWidget>
#include <QMap>
#include <QMessageBox>
#include <QInputDialog>
#include <QListWidget>
#include "gamesession.h"
#include "command.h"

namespace Ui {
	class GameForm;
}

class GameForm : public QWidget, public GameController
{
		Q_OBJECT

	public:
		explicit GameForm(QWidget *parent = 0);
		void setContext(GameSession *game, bool initial = true);
		void addCardEntry(listItem item, int dest);
		void updateCardEntry(listItem item);
		void removeCardEntry(listItem item);
		void getCardInfo(QString cardInfo, int dest);
		void setCardSelectMode(bool enable, bool isOwned);
		void callForActionChoose(QList<effectInfoItem> effs);
		void showGameResult(int playerID);
		void showEnemyCardCount(int count);
		void showMsg(QString msg);
		void makeReady();
		void clearAllEntries();
		~GameForm();
	public slots:

		void initUI();
		void readyToStart();

	signals:
		void useCard(QString id);
		void activateCard(QString id);
		void sendCardSelection(QVector<QString> ids, effectInfoItem eff);
		void cardInfoRequest(int dest, QString id);

	private slots:
		void on_btnUsedCardAct_clicked();
		void on_btnPlayerCardUse_clicked();
		void on_btnTargetCardSelect_clicked();
		void deselectAll();
		void on_listEnemyCards_itemSelectionChanged();
		void on_listPlayerUsedCards_itemSelectionChanged();
		void on_listPlayerCards_itemSelectionChanged();

	private:
		Ui::GameForm *ui;
		GameSession *gs;
		bool selectOwnedCards;
		QMap<QString, int> cardMapping;
		QMap<QString, QListWidgetItem *> cardItems;
		QList<effectInfoItem> currEffs;
		int currEffID;
};

#endif // GAMEFORM_H
