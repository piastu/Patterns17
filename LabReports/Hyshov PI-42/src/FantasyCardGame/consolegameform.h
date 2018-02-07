#ifndef CONSOLEGAMEFORM_H
#define CONSOLEGAMEFORM_H

#include <QWidget>
#include "gamecontroller.h"
#include "gamesession.h"
#include "defs.h"
#include "command.h"

namespace Ui {
	class ConsoleGameForm;
}

enum commandID {
	CMD_CARDNUM = 0,
	CMD_SELECT_CMD,
	CMD_SHOW_PLAYERCARDS,
	CMD_SHOW_PLAYERUSEDCARDS,
	CMD_SHOW_ENEMYCARDS,
	CMD_SELECT_ACTION,
	CMD_SELECT_CARDTOACTIVATE,
	CMD_SELECT_CARDTOUSE,
	CMD_SELECT_TARGET,
	CMD_ENDGAME,
	CMD_IDLE
};

class ConsoleGameForm : public QWidget, public GameController
{
		Q_OBJECT
	public:
		explicit ConsoleGameForm(QWidget *parent = 0);
		void setContext(GameSession *game, bool initial = true);
		void callForActionChoose(QList<effectInfoItem> actions);
		void showGameResult(int playerID);
		void showEnemyCardCount(int count);
		void getCardInfo(QString cardInfo, int dest);
		void setCardSelectMode(bool enable, bool isOwned);
		void showMsg(QString msg);
		void addCardEntry(listItem item, int dest);
		void updateCardEntry(listItem item);
		void removeCardEntry(listItem item);
		void makeReady();
		void clearAllEntries();
		void submitCommand(QString cmdText);
		void execCommand(int cmdNum);
		void showTargets();

		~ConsoleGameForm();

	private:
		Ui::ConsoleGameForm *ui;
		GameSession *gs;
		bool selectOwnedCards;
		QMap<QString, int> cardMapping;
		QMap<QString, listItem> cardItems;
		QList<effectInfoItem> currEffs;
		QList<QString> currSelectionSet;
		QString currPick, targetPick;
		int currEffID;
		commandID cmdID;
		void initUI();

	public slots:

	private slots:
		void on_btnSubmit_clicked();
};

#endif // CONSOLEGAMEFORM_H
