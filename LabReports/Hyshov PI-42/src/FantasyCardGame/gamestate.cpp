#include "gamestate.h"

GameState::GameState()
{

}

void GameState::setCardSet(QList<ICard *> cards, int cardsType)
{
	switch (cardsType)
	{
		case GS_POOL:
			pool = cards;
			break;
		case GS_PLAYER:
			player = cards;
			break;
		case GS_PLAYERUSED:
			playerUsed = cards;
			break;
		case GS_ENEMY:
			enemy = cards;
			break;
		case GS_ENEMYUSED:
			enemyUsed = cards;
			break;
		case GS_BEATEN:
			beaten = cards;
			break;
		default:
			break;
	}
}

QList<ICard *> GameState::getCardSet(int cardsType)
{
	switch (cardsType)
	{
		case GS_POOL:
			return pool;
			break;
		case GS_PLAYER:
			return player;
			break;
		case GS_PLAYERUSED:
			return playerUsed;
			break;
		case GS_ENEMY:
			return enemy;
			break;
		case GS_ENEMYUSED:
			return enemyUsed;
			break;
		case GS_BEATEN:
			return beaten;
			break;
		default:
			return QList<ICard *>();
			break;
	}
}

void GameState::setPlayersFlag(bool flag)
{
	playersFlag = flag;
}

bool GameState::getPlayersFlag()
{
	return playersFlag;
}
