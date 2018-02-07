#include "player.h"

Player::Player(QObject *parent):QObject(parent)
{
	actionID = 0;
	actionPick = {};
	currentState = new PlayerStateInitial(dynamic_cast<Player*>(this));
	assignedThread = new QThread(this);
	currentCardAction = -1;
	connect(assignedThread, SIGNAL(started()), this, SLOT(makeTurn()));
	pickStrategy = nullptr;
}

Player::Player(bool isCPU, QObject *parent):Player(parent)
{
	cpu = isCPU;
	if (isCPU)
	{
		if (Random::probability(0.5))
			pickStrategy = new CPUPickRandom();
		else
			pickStrategy = new CPUPickWeakestFirst();
		if (Random::probability(0.5))
			pickStrategyUsed = new CPUPickRandom();
		else
			pickStrategyUsed = new CPUPickWeakestFirst();
	}
}

QList<ICard *> Player::getCards()
{
	return cards;
}

QList<ICard *> Player::getCardsInUse()
{
	return cardsInUse;
}

QList<ICard *> Player::getPickedCards()
{
	return pickedCards;
}

void Player::giveCards(QList<ICard *> cardsToGive)
{
	int sum = cardsToGive.size();
	for (int i = 0; i < sum; i++)
		cards.push_back(cardsToGive[i]);
}

void Player::pickCards(QList<ICard *> cardsToPick)
{
	pickedCards = cardsToPick;
}

void Player::pickCards(QVector<QString> cardsToPick)
{
	selection = cardsToPick;
}

void Player::setCards(QList<ICard *> cardsToSet)
{
	cards = cardsToSet;
}

void Player::setCardsInUse(QList<ICard *> cardsUsed)
{
	cardsInUse = cardsUsed;
}

void Player::makeTurn()
{
	// ID действий:
	// 0: начальное
	// 1: вывод карты на поле
	// 2: задействование выведенной карты
	// 3: выбор целевой карты
	// 10: окончание хода
	currentState->run();
	if (needToRestartThread)
	{
		needToRestartThread = false;
		emit restart();
	}

}

void Player::callActionSelect()
{
	ICard *c = (ICard *)QObject::sender();
	if (cpu)
	{
		int num = c->getEffects().size();
		sendActionSelect(Random::randInt(0, num - 1));
		this->setState(new PlayerStateTargetSelect(dynamic_cast<Player *>(this)), {});
	}
}

void Player::callTurnEnd()
{
	currentState = new PlayerStateFinal(dynamic_cast<Player *>(this));
	restart();
}

bool Player::isCPU()
{
	return cpu;
}

QThread *Player::getThread()
{
	return assignedThread;
}

void Player::setAction(int id, QList<QString> pick)
{
	actionPick = pick;
	actionID = id;
}

void Player::setState(IPlayerState *state)
{
	currentState = state;
}

void Player::setState(IPlayerState *state, QList<QString> pick)
{
	actionPick = pick;
	currentState = state;
}

QList<QString> Player::getActionPick()
{
	return actionPick;
}

QString Player::getCurrentPick()
{
	return currentPick;
}

QVector<QString> Player::getSelection()
{
	return selection;
}

void Player::setCurrentPick(QString pick)
{
	currentPick = pick;
}

void Player::chooseCardAction(int id)
{
	currentCardAction = id;
}

int Player::getCardAction()
{
	return currentCardAction;
}

QString Player::getCardFullInfo(QString uid)
{
	int sizeInt;
	sizeInt = cards.size();
	for (int i = 0; i < sizeInt; i++)
		if (cards[i]->getUID() == uid)
			return cards[i]->getFullInfo();
	sizeInt = cardsInUse.size();
	for (int i = 0; i < sizeInt; i++)
		if (cardsInUse[i]->getUID() == uid)
			return cardsInUse[i]->getFullInfo();
	return "";
}

void Player::setRestartTask(bool ok)
{
	needToRestartThread = ok;
}

CPUCardPickStrategy *Player::getStrategy(bool forActivation)
{
	return (forActivation ? pickStrategyUsed : pickStrategy);
}

void Player::attachMediator(PlayerMediator *mediator)
{
	if (this->mediator != mediator)
		this->mediator = mediator;
}

void Player::detachMediator(PlayerMediator *mediator)
{
	if (this->mediator == mediator)
		this->mediator = nullptr;
}

QList<ICard *> Player::lookForNextPlayerUsedCards()
{
	QList<ICard *> result;
	if (mediator != nullptr)
		result = mediator->showNextPlayerCards();
	return result;
}

effectInfoItem Player::getSelectedEffectInfo()
{
	return eInfo;
}

void Player::tellSelectedEffectInfo(effectInfoItem e)
{
	eInfo = e;
}

void Player::disposeCard()
{
	QObject *o = QObject::sender();
	ICard *card = dynamic_cast<ICard *>(o);
	int cardID = cardsInUse.indexOf(card);
	if (cardID != -1)
	{
		cardsInUse.removeAt(cardID);
	}
}


IPlayerState::IPlayerState(QObject *parent) : QObject(parent)
{

}

IPlayerState::IPlayerState(Player *plr, QObject *parent) : IPlayerState(parent)
{

}

PlayerStateInitial::PlayerStateInitial(QObject *parent) : IPlayerState(parent)
{

}

PlayerStateInitial::PlayerStateInitial(Player *plr, QObject *parent) : PlayerStateInitial(parent)
{
	context = plr;
}

void PlayerStateInitial::setContext(Player *plr)
{
	context = plr;
}

Player *PlayerStateInitial::getContext()
{
	return context;
}

void PlayerStateInitial::run()
{
	bool isCPU = context->isCPU();
	if (isCPU)
	{
		int actionID = Random::randIntWeighted({context->getCards().empty() ? 0 : 5, context->getCardsInUse().empty() ? 0 : 5});
		if (actionID == 0)
			context->setState(new PlayerStateCardSelect(dynamic_cast<Player*>(context)));
		else if (actionID == 1)
			context->setState(new PlayerStateCardActivation(dynamic_cast<Player*>(context)));
		context->setRestartTask(true);
	}
	else
	{
		return;
	}
}

PlayerStateCardSelect::PlayerStateCardSelect(QObject *parent) : IPlayerState(parent)
{

}

PlayerStateCardSelect::PlayerStateCardSelect(Player *plr, QObject *parent) : PlayerStateCardSelect(parent)
{
	context = plr;
}

void PlayerStateCardSelect::setContext(Player *plr)
{
	context = plr;
}

Player *PlayerStateCardSelect::getContext()
{
	return context;
}

void PlayerStateCardSelect::run()
{
	GameSession *gs = GameSession::getInstance();
	bool isCPU = context->isCPU();
	if (isCPU)
	{
		QList<ICard *> cards = context->getCards(),
				cardsInUse = context->getCardsInUse();
		int randNum = context->getStrategy()->pickCard(cards);
		cardsInUse.push_back(cards.takeAt(randNum));
		context->setCards(cards);
		context->setCardsInUse(cardsInUse);
		context->addID(listItem(cardsInUse.back()->getDrawable(),
					   cardsInUse.back()->getPseudoDrawable(),
					   cardsInUse.back()->getName(),
					   cardsInUse.back()->getUID()), 2);
		context->showCardCount(cards.size());
		gs->msgRepeater("Игрок вывел на поле " + cardsInUse.back()->getName());
		context->setState(new PlayerStateInitial(dynamic_cast<Player*>(context)), QList<QString>());
		context->getThread()->msleep(250);
		context->turnEnd();
	}
	else
	{
		int pick = 0;
		QList<ICard *> cards = context->getCards(),
				cardsInUse = context->getCardsInUse();
		QList<QString> actionPick = context->getActionPick();
		for (int i = 0; i < cards.size(); i++)
			if (cards[i]->getUID() == actionPick[0])
			{
				pick = i;
				break;
			}
		context->removeID(listItem(cards[pick]->getDrawable(), cards[pick]->getPseudoDrawable(), cards[pick]->getName(), cards[pick]->getUID()));
		cardsInUse.push_back(cards.takeAt(pick));
		context->setCards(cards);
		context->setCardsInUse(cardsInUse);
		context->addID(listItem(cardsInUse.back()->getDrawable(), cardsInUse.back()->getPseudoDrawable(), cardsInUse.back()->getName(), cardsInUse.back()->getUID()), 1);
		gs->msgRepeater("Игрок вывел на поле " + cardsInUse.back()->getName());
		// вывели карту, можно переводить ход
		context->setState(new PlayerStateInitial(dynamic_cast<Player*>(context)), QList<QString>());
		context->getThread()->msleep(250);
		context->turnEnd();
	}
}

PlayerStateCardActivation::PlayerStateCardActivation(QObject *parent) : IPlayerState(parent)
{

}

PlayerStateCardActivation::PlayerStateCardActivation(Player *plr, QObject *parent) : PlayerStateCardActivation(parent)
{
	context = plr;
}

void PlayerStateCardActivation::setContext(Player *plr)
{
	context = plr;
}

Player *PlayerStateCardActivation::getContext()
{
	return context;
}

void PlayerStateCardActivation::run()
{
	GameSession *gs = GameSession::getInstance();
	bool isCPU = context->isCPU();
	if (isCPU)
	{
		QList<ICard *> cardsInUse = context->getCardsInUse();
		int randNum = (cardsInUse.size() != 1) ? context->getStrategy(true)->pickCard(cardsInUse) : 0;
		//actionPick = randNum;
		context->setState(new PlayerStateTargetSelect(dynamic_cast<Player*>(context)));
		context->setCurrentPick(cardsInUse[randNum]->getUID());
		gs->msgRepeater("Игрок выбрал " + cardsInUse[randNum]->getName());
		QList<effectInfoItem> effs = cardsInUse[randNum]->getEffectsInfo();
		int effID = Random::randInt(0, effs.size() - 1);
		context->chooseCardAction(effID);
		emit context->showPickedCardInfoSingle(effs[effID]);
		QList<ICard *> pick;
		if (effs[effID].canAffectEnemy)
		{
			QList<ICard *> playerCards = context->lookForNextPlayerUsedCards();
			if (!playerCards.empty())
			{
				int cardId = Random::randInt(0, playerCards.size() - 1);
				pick.push_back(playerCards[cardId]);
			}
		}
		if (effs[effID].canAffectPlayer)
		{
			int cardId = Random::randInt(0, cardsInUse.size() - 1);
			pick.push_back(cardsInUse[cardId]);
		}
		context->pickCards(pick);
		context->restart();
	}
	else
	{
		QList<ICard *> cardsInUse = context->getCardsInUse();
		QList<QString> actionPick = context->getActionPick();
		int pick = 0;
		for (int i = 0; i < cardsInUse.size(); i++)
			if (cardsInUse[i]->getUID() == actionPick[0])
			{
				pick = i;
				break;
			}
		emit context->showPickedCardInfo(cardsInUse[pick]->getEffectsInfo());
		gs->msgRepeater("Игрок выбрал " + cardsInUse[pick]->getName());
		context->setState(new PlayerStateTargetSelect(dynamic_cast<Player*>(context)));
	}
}

PlayerStateTargetSelect::PlayerStateTargetSelect(QObject *parent) : IPlayerState(parent)
{

}

PlayerStateTargetSelect::PlayerStateTargetSelect(Player *plr, QObject *parent) : PlayerStateTargetSelect(parent)
{
	context = plr;
}

void PlayerStateTargetSelect::setContext(Player *plr)
{
	context = plr;
}

Player *PlayerStateTargetSelect::getContext()
{
	return context;
}

void PlayerStateTargetSelect::run()
{
	GameSession *gs = GameSession::getInstance();
	bool isCPU = context->isCPU();
	if (isCPU)
	{
		QList<ICard *> cardsInUse = context->getCardsInUse();
		QList<ICard *> pickedCards = context->getPickedCards();
		QString currentPick = context->getCurrentPick();
		int pick = 0;
		if (pickedCards.empty())
		{
			gs->msgRepeater("Игрок ничего не выбрал и пропускает ход.");
			context->callTurnEnd();
			return;
		}
		for (int i = 0; i < cardsInUse.size(); i++)
			if (cardsInUse[i]->getUID() == currentPick)
			{
				pick = i;
				break;
			}
		cardsInUse[pick]->makeActionSelection(context->getCardAction());
		cardsInUse[pick]->act(context->getPickedCards());
		context->callTurnEnd();
	}
	else
	{
		QList<ICard *> cardsInUse = context->getCardsInUse();
		QList<QString> actionPick = context->getActionPick();
		int pick = 0;
		for (int i = 0; i < cardsInUse.size(); i++)
			if (cardsInUse[i]->getUID() == actionPick[0])
			{
				pick = i;
				break;
			}
		cardsInUse[pick]->makeActionSelection(context->getCardAction());
		QList<ICard *> tCards, tPick;
		QVector<QString> selection = context->getSelection();
		effectInfoItem eInfo = context->getSelectedEffectInfo();
		if (eInfo.canAffectEnemy)
			tCards.append(context->lookForNextPlayerUsedCards());
		if (eInfo.canAffectPlayer)
			tCards.append(cardsInUse);
		for (int i = 0; i < selection.size(); i++)
		{
			for (int j = 0; j < tCards.size(); j++)
			{
				if (selection[i] == tCards[j]->getUID())
				{
					tPick.push_back(tCards[j]);
				}
			}
		}
		context->pickCards(tPick);
		cardsInUse[pick]->act(context->getPickedCards());
		context->callTurnEnd();
	}
}

PlayerStateFinal::PlayerStateFinal(QObject *parent) : IPlayerState(parent)
{

}

PlayerStateFinal::PlayerStateFinal(Player *plr, QObject *parent) : PlayerStateFinal(parent)
{
	context = plr;
}

void PlayerStateFinal::setContext(Player *plr)
{
	context = plr;
}

Player *PlayerStateFinal::getContext()
{
	return context;
}

void PlayerStateFinal::run()
{
	bool isCPU = context->isCPU();
	if (isCPU)
	{
		context->setState(new PlayerStateInitial(dynamic_cast<Player *>(context)), {});
		context->setCurrentPick("");
		context->chooseCardAction(-1);
		context->getThread()->msleep(250);
		context->turnEnd();
	}
	else
	{
		context->setState(new PlayerStateInitial(dynamic_cast<Player *>(context)), {});
		context->setCurrentPick("");
		context->chooseCardAction(-1);
		context->getThread()->msleep(250);
		context->turnEnd();
	}
}

CPUCardPickStrategy::CPUCardPickStrategy()
{

}

CPUPickRandom::CPUPickRandom() : CPUCardPickStrategy()
{

}

int CPUPickRandom::pickCard(QList<ICard *> cards)
{
	return Random::randInt(0, cards.size() - 1);
}

CPUPickWeakestFirst::CPUPickWeakestFirst()
{

}

int CPUPickWeakestFirst::pickCard(QList<ICard *> cards)
{
	QList<int> actors, actions;
	int sizeInt = cards.size();
	int result = 0;
	for (int i = 0; i < sizeInt; i++)
	{
		// если это действие (а оно всега имеет 999 HP)
		if (cards[i]->getStat("health") == 999)
			actions.push_back(i);
		else
			actors.push_back(i);
	}
	bool selectActions = ((!actors.empty() && !actions.empty() && Random::probability(0.5))
						  || (actors.empty() && !actions.empty()));
	if (!selectActions)
	{
		// выбираем из актеров и команд
		sizeInt = actors.size();
		int curHealth = cards[actors[0]]->getStat("health");
		result = actors[0];
		for (int i = 1; i < sizeInt; i++)
		{
			int nextHealth = cards[actors[i]]->getStat("health");
			if (nextHealth < curHealth)
			{
				result = actors[i];
				curHealth = nextHealth;
			}
		}
	}
	else
	{
		// выбираем из действий
		result = actions[Random::randInt(0, actions.size() - 1)];
	}
	return result;
}

PlayerMediator::PlayerMediator(QObject *parent) : QObject(parent)
{

}

QList<ICard *> PlayerMediator::showNextPlayerCards()
{
	QList<ICard *> result;
	Player *nextPlayer = GameSession::getInstance()->getNextPlayer();
	if (nextPlayer != nullptr)
		result = nextPlayer->getCardsInUse();
	return result;
}
