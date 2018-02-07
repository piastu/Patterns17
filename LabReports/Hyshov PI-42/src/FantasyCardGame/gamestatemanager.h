#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <QObject>
#include "defs.h"
#include "card.h"
#include "gamestate.h"

class GameState;
class CardStreamWriter;

class GameStateManager : public QObject
{
		Q_OBJECT
	public:
		explicit GameStateManager(QObject *parent = 0);
		void saveState(GameState *gs, int *ok = NULL);
		GameState * loadState(int *ok = NULL);
	signals:

	public slots:
};

#endif // GAMESTATEMANAGER_H
