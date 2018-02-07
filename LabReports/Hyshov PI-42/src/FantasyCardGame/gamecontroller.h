#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "defs.h"
#include "util.h"

class GameSession;

class GameController
{
	public:
		explicit GameController();
		virtual void showMsg(QString msg) = 0;
		virtual void addCardEntry(listItem item, int dest) = 0;
		virtual void updateCardEntry(listItem item) = 0;
		virtual void removeCardEntry(listItem item) = 0;
		virtual void callForActionChoose(QList<effectInfoItem> actions) = 0;
		virtual void showGameResult(int playerID) = 0;
		virtual void showEnemyCardCount(int count) = 0;
		virtual void getCardInfo(QString cardInfo, int dest) = 0;
		virtual void setCardSelectMode(bool enable, bool isOwned) = 0;
		virtual void setContext(GameSession *game, bool initial = true) = 0;
		virtual void makeReady() = 0;
		virtual void clearAllEntries() = 0;
};

#endif // GAMECONTROLLER_H
