#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "defs.h"
#include "card.h"

enum GameStateCardsSet
{
	GS_POOL = 0,
	GS_PLAYER,
	GS_PLAYERUSED,
	GS_ENEMY,
	GS_ENEMYUSED,
	GS_BEATEN
};

class GameState
{
	private:
		QList <ICard *> pool,
		player,
		playerUsed,
		enemy,
		enemyUsed,
		beaten;
		bool playersFlag;
	public:
		GameState();
		void setCardSet(QList<ICard *> cards, int cardsType);
		QList<ICard *> getCardSet(int cardsType);
		void setPlayersFlag(bool flag);
		bool getPlayersFlag();
};

#endif // GAMESTATE_H
