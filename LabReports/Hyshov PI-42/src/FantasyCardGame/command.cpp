#include "command.h"

Command::Command()
{
	context = nullptr;
}

void Command::setContext(GameSession *gs)
{
	context = gs;
}

PlayerCardUseCommand::PlayerCardUseCommand() : Command()
{
	pickID = "";
}

void PlayerCardUseCommand::execute()
{
	Player *plr = context->getCurrentPlayer();
	if (plr != nullptr)
	{
		plr->setState(new PlayerStateCardSelect(dynamic_cast<Player*>(plr)), {pickID});
		plr->getThread()->terminate();
		plr->getThread()->start();
	}
}

void PlayerCardUseCommand::setPick(QString id)
{
	pickID = id;
}

PlayerCardActivateCommand::PlayerCardActivateCommand() : Command()
{
	pickID = "";
}

void PlayerCardActivateCommand::execute()
{
	Player *plr = context->getCurrentPlayer();
	if (plr != nullptr)
	{
		plr->setState(new PlayerStateCardActivation(dynamic_cast<Player*>(plr)), {pickID});
		plr->getThread()->terminate();
		plr->getThread()->start();
	}
}

void PlayerCardActivateCommand::setPick(QString id)
{
	pickID = id;
}
