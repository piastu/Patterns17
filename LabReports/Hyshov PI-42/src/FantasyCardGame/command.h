#ifndef COMMAND_H
#define COMMAND_H

#include "defs.h"
#include "gamesession.h"
#include "player.h"

class GameSession;

class Command
{
	protected:
		GameSession *context;
	public:
		Command();
		void setContext(GameSession *gs);
		virtual void execute() = 0;
};

class PlayerCardUseCommand : public Command
{
	protected:
		QString pickID;
	public:
		PlayerCardUseCommand();
		void execute();
		void setPick(QString id);
};

class PlayerCardActivateCommand : public Command
{
	protected:
		QString pickID;
	public:
		PlayerCardActivateCommand();
		void execute();
		void setPick(QString id);
};

#endif // COMMAND_H
