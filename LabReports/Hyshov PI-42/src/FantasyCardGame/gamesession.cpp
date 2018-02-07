#include "gamesession.h"

GameSession * GameSession::instance = NULL;

GameSession::GameSession(QObject *parent):QObject(parent)
{
	int sizeInt = 0;
	infoTrans = new InfoTransmitter(this);
	cio = new CardInfoObserver(this);
	gsm = new GameStateManager(this);
	pMed = new PlayerMediator();
	NameGen *ng = new NameGen();
	effFactory = new EffectFactory(this);
	effFactory->installNamegen(ng);
	effFactory->setContext(this);
	// создаем фабрики карт
	cardFactories.push_back(new ActorCardFactory(this));
	cardFactories.push_back(new ActionCardFactory(this));
	TeamCardFactory *tcf = new TeamCardFactory(this);
	tcf->setSubfactories(cardFactories[0], cardFactories[1]);
	cardFactories.push_back(tcf);
	sizeInt = cardFactories.size();
	for (int i = 0; i < sizeInt; i++)
	{
		cardFactories[i]->setContext(this);
		cardFactories[i]->installNamegen(ng);
		cardFactories[i]->setEffectFactory(effFactory);
	}
	CardFactoryTiered *cft2 = new CardFactoryTier2(this);
	cft2->setContext(this);
	cft2->installNamegen(ng);
	cft2->setEffectFactory(effFactory);
	cardFactoriesTiered.push_back(cft2);
	CardFactoryTiered *cft3 = new CardFactoryTier3(this);
	cft3->setContext(this);
	cft3->installNamegen(ng);
	cft3->setEffectFactory(effFactory);
	cardFactoriesTiered.push_back(cft3);
	// генерируем карты и забиваем в пул
	CardPool *cp = CardPool::getInstance();
	QList<ICard *> pregenCards = generateCards(CARD_POOL_SIZE);
	while (!pregenCards.empty())
		cp->putCard(pregenCards.takeFirst());
	cp->shuffle();
	connect(this, SIGNAL(sendMsg(QString)), infoTrans, SLOT(receiveMsg(QString)));
	connect(infoTrans, SIGNAL(sendMsg(QString)), this, SLOT(msgRepeater(QString)));
	ready = false;
	currentTurn = -1;
	winner = -1;
}

void GameSession::installController(GameController *gc)
{
	controller = gc;
}

void GameSession::initialize(int numCards)
{
	CardPool *cp = CardPool::getInstance();
	// настраиваем игроков
	// пока что здесь их всего два
	// так что пусть игроком 0 будет человек
	players.push_back(new Player(false));
	players.push_back(new Player(true));
	foreach (Player *p, players) {
		connect(p, SIGNAL(turnEnd()), this, SLOT(nextTurn()));
		connect(p, SIGNAL(removeID(listItem)), this, SLOT(listItemRemoveRepeater(listItem)));
		connect(p, SIGNAL(addID(listItem,int)), this, SLOT(listItemAddRepeater(listItem,int)));
		connect(p, SIGNAL(restart()), this, SLOT(restartPlayerThread()));
		connect(p, SIGNAL(showPickedCardInfo(QList<effectInfoItem>)), this, SLOT(effectsInfoRepeater(QList<effectInfoItem>)));
		connect(p, SIGNAL(sendActionSelect(int)), this, SLOT(setCurrentAction(int)));
		connect(p, SIGNAL(showPickedCardInfoSingle(effectInfoItem)), this, SLOT(setCurEffInfo(effectInfoItem)));
		connect(p, SIGNAL(sendMsg(QString)), infoTrans, SLOT(receiveMsg(QString)));
		p->attachMediator(pMed);
	}
	connect(players[1], SIGNAL(showCardCount(int)), this, SLOT(cardCountRepeater(int)));
	for (int k = 0; k < players.size(); k++)
	{
		// раздадим карты
		QList<ICard *> cards;
		for (int i = 0; i < numCards; i++)
			cards.push_back(cp->getCard());
		players[k]->giveCards(cards);
		for (int i = 0; i < cards.size(); i++)
		{
			cards[i]->attachObserver(cio);
			connect(cards[i], SIGNAL(disposeMe()), players[k], SLOT(disposeCard()));
			connect(cards[i], SIGNAL(callActionSelect()), players[k], SLOT(callActionSelect()));
			connect(players[k], SIGNAL(sendActionSelect(int)), cards[i], SLOT(makeActionSelection(int)));
		}
	}
	ready = true;
}

QList<ICard *> GameSession::generateCards(int num, int ctype, bool connections)
{
	QList<ICard *> cards;
	for (int i = 0; i < num; i++)
	{
		int cardType = 0;
		if (ctype == -1)
			cardType = Random::randIntWeighted({25, 15, 5});
		else
			cardType = ctype;
		switch (Random::randIntWeighted({25, 5}))
		{
			case 0:
				cards.push_back(cardFactories[cardType]->generateCard(connections));
				break;
			case 1:
				CardFactoryTiered *cft = cardFactoriesTiered[Random::randInt(0, cardFactoriesTiered.size() - 1)];
				switch (cardType)
				{
					case 0:
						cards.push_back(cft->generateActorCard());
						break;
					case 1:
						cards.push_back(cft->generateActionCard());
						break;
					case 2:
						cards.push_back(cft->generateTeamCard());
						break;
				}
				break;
		}
	}
	return cards;
}

GameSession *GameSession::getInstance(bool reset)
{
	if (instance == NULL)
		instance = new GameSession();
	if (reset)
		instance->reset();
	return instance;
}

void GameSession::reset()
{
	int sizeInt = 0;
	CardPool *cp = CardPool::getInstance();
	QList<ICard *> usedCards;
	sizeInt = players.size();
	for (int i = 0; i < sizeInt; i++)
	{
		usedCards.append(players[i]->getCards());
		usedCards.append(players[i]->getCardsInUse());
	}
	while (!players.empty())
	{
		Player *plr = players.takeFirst();
		plr->detachMediator(pMed);
		delete plr;
	}
	while (!usedCards.empty())
		cp->putCard(usedCards.takeFirst());
	while (!beatenCards.empty())
		cp->putCard(beatenCards.takeFirst());
	cp->shuffle();
	ready = false;
	currentTurn = -1;
	winner = -1;
}

QList<listItem> GameSession::getDrawables()
{
	QList<ICard *> enemyCards, playerCards;
	int enemyID = (players[0]->isCPU() ? 0 : 1);
	int playerID = ((enemyID == 1) ? 0 : 1);
	enemyCards = players[enemyID]->getCards();
	playerCards = players[playerID]->getCards();
	QList<listItem> litems;
	for (int i = 0; i < playerCards.size(); i++)
	{
		listItem li;
		li.drawable = playerCards[i]->getDrawable();
		li.pseudoDrawable = playerCards[i]->getPseudoDrawable();
		li.name = playerCards[i]->getName();
		li.uid = playerCards[i]->getUID();
		litems.push_back(li);
	}
	return litems;
}

bool GameSession::isReady()
{
	return ready;
}

InfoTransmitter *GameSession::getInfoTrans()
{
	return infoTrans;
}

QString GameSession::getCardFullInfo(QString uid)
{
	int sizeInt = players.size();
	for (int i = 0; i < sizeInt; i++)
	{
		QString result = players[i]->getCardFullInfo(uid);
		if (result != "")
			return result;
	}
	return "";
}

int GameSession::saveState()
{
	CardPool *cp = CardPool::getInstance();
	GameState *gs = new GameState();
	gs->setCardSet(beatenCards, GameStateCardsSet::GS_BEATEN);
	if (players.size() >= 2)
	{
		gs->setPlayersFlag(true);
		gs->setCardSet(players[0]->getCards(), GameStateCardsSet::GS_PLAYER);
		gs->setCardSet(players[0]->getCardsInUse(), GameStateCardsSet::GS_PLAYERUSED);
		gs->setCardSet(players[1]->getCards(), GameStateCardsSet::GS_ENEMY);
		gs->setCardSet(players[1]->getCardsInUse(), GameStateCardsSet::GS_ENEMYUSED);
	}
	else
		gs->setPlayersFlag(false);
	QList<ICard *> poolCards;
	while (!cp->isEmpty())
		poolCards.push_back(cp->getCard());
	gs->setCardSet(poolCards, GameStateCardsSet::GS_POOL);
	while (!poolCards.empty())
		cp->putCard(poolCards.takeFirst());
	int result = 0;
	gsm->saveState(gs, &result);
	delete gs;
	return result;
}

int GameSession::loadState()
{
	int result = 0;
	GameState *gs;
	gs = gsm->loadState(&result);
	if (result != 0)
		return result;
	reset();
	CardPool *cp = CardPool::getInstance();
	beatenCards = gs->getCardSet(GameStateCardsSet::GS_BEATEN);
	QList<ICard *> cards;
	cards = gs->getCardSet(GameStateCardsSet::GS_POOL);
	cp->clear();
	while (!cards.empty())
		cp->putCard(cards.takeFirst());
	cp->shuffle();
	if (gs->getPlayersFlag())
	{
		initialize(0);
		players[0]->setCards(gs->getCardSet(GameStateCardsSet::GS_PLAYER));
		players[0]->setCardsInUse(gs->getCardSet(GameStateCardsSet::GS_PLAYERUSED));
		players[1]->setCards(gs->getCardSet(GameStateCardsSet::GS_ENEMY));
		players[1]->setCardsInUse(gs->getCardSet(GameStateCardsSet::GS_ENEMYUSED));
		beatenCards = gs->getCardSet(GameStateCardsSet::GS_BEATEN);
	}
	if (controller)
	{
		controller->clearAllEntries();
		if (gs->getPlayersFlag())
		{
			cards = gs->getCardSet(GameStateCardsSet::GS_PLAYER);
			while (!cards.empty())
				controller->addCardEntry(getCardListItem(cards.takeFirst()), 0);
			cards = gs->getCardSet(GameStateCardsSet::GS_PLAYERUSED);
			while (!cards.empty())
				controller->addCardEntry(getCardListItem(cards.takeFirst()), 1);
			cards = gs->getCardSet(GameStateCardsSet::GS_ENEMY);
			controller->showEnemyCardCount(cards.size());
			while (!cards.empty())
				controller->addCardEntry(getCardListItem(cards.takeFirst()), 2);
			cards = gs->getCardSet(GameStateCardsSet::GS_ENEMYUSED);
			controller->makeReady();
		}
	}
	delete gs;
	return result;
}

Player *GameSession::getCurrentPlayer()
{
	if (players.empty())
		return nullptr;
	return players[currentTurn];
}

Player *GameSession::getNextPlayer()
{
	if (players.empty())
		return nullptr;
	return players[(currentTurn + 1) % players.size()];
}

void GameSession::setCurrentAction(int id)
{
	//curCardAction = id;
	players[currentTurn]->chooseCardAction(id);
}

void GameSession::msgRepeater(QString msg)
{
	controller->showMsg(msg);
}

void GameSession::disposeCard()
{
	QObject *o = QObject::sender();
	ICard *card = dynamic_cast<ICard *>(o);
	beatenCards.push_back(card);
	card->detachObserver(cio);
	listItem li;
	li.uid = card->getUID();
	listItemRemoveRepeater(li);
}

void GameSession::disposeCard(ICard *card)
{
	beatenCards.push_back(card);
	card->detachObserver(cio);
	listItem li;
	li.uid = card->getUID();
	listItemRemoveRepeater(li);
}

void GameSession::nextTurn()
{
	if (currentTurn == -1)
		currentTurn = (currentTurn + 1) % players.size();
	players[currentTurn]->getThread()->terminate();
	// так как тут 2 игрока
	if (players[currentTurn]->getCards().empty() && players[currentTurn]->getCardsInUse().empty())
		winner = (currentTurn + 1) % players.size();
	currentTurn = (currentTurn + 1) % players.size();
	if (players[currentTurn]->getCards().empty() && players[currentTurn]->getCardsInUse().empty())
		winner = (currentTurn + 1) % players.size();
	// запускаем тред следующего игрока
	if (winner == -1)
	{
		controller->showMsg("Игрок " + QString::number(currentTurn + 1) + " делает ход...");
		if (!players[currentTurn]->isCPU())
			controller->makeReady();
		players[currentTurn]->getThread()->start(QThread::LowestPriority);
	}
	else
	{
		controller->showMsg("Победил игрок " + QString::number(currentTurn + 1) + "!");
		controller->showGameResult(winner);
		reset();
	}
}

void GameSession::cardInfoRequest(int dest, QString id)
{
	QList<ICard *> cards;
	foreach (Player *p, players)
	{
		cards.append(p->getCards());
		cards.append(p->getCardsInUse());
	}
	int pick = 0;
	for (int i = 0; i < cards.size(); i++)
		if (cards[i]->getUID() == id)
		{
			pick = i;
			break;
		}
	emit getCardInfo(cards[pick]->getFullInfo(), dest);
}

void GameSession::cardSelectCall()
{
	// ходит ли компьютер
	if (players[currentTurn]->isCPU())
	{
		// выберем одну карту
		QList<ICard *> pick;
		if (eInfo.canAffectEnemy)
		{
			QList<ICard *> playerCards = players[(currentTurn + 1) % players.size()]->getCardsInUse();
			if (!playerCards.empty())
			{
				int cardId = Random::randInt(0, playerCards.size() - 1);
				pick.push_back(playerCards[cardId]);
			}
		}
		if (eInfo.canAffectPlayer)
		{
			QList<ICard *> enemyCards = players[currentTurn]->getCardsInUse();
			int cardId = Random::randInt(0, enemyCards.size() - 1);
			pick.push_back(enemyCards[cardId]);
		}
		players[currentTurn]->pickCards(pick);
		selection.clear();
		restartPlayerThread();
	}
	else
	{
		QList<ICard *> cards, pick;
		if (eInfo.canAffectEnemy)
			cards.append(players[(currentTurn + 1) % players.size()]->getCardsInUse());
		if (eInfo.canAffectPlayer)
			cards.append(players[currentTurn]->getCardsInUse());
		for (int i = 0; i < selection.size(); i++)
		{
			for (int j = 0; j < cards.size(); j++)
			{
				if (selection[i] == cards[j]->getUID())
				{
					pick.push_back(cards[j]);
				}
			}
		}
		players[currentTurn]->chooseCardAction(curCardAction);
		players[currentTurn]->pickCards(pick);
		selection.clear();
		controller->setCardSelectMode(false, false);
		restartPlayerThread();
	}
}

void GameSession::listItemRemoveRepeater(listItem item)
{
	controller->removeCardEntry(item);
}

void GameSession::listItemAddRepeater(listItem item, int dest)
{
	controller->addCardEntry(item, dest);
}

void GameSession::listItemUpdateRepeater(listItem item)
{
	controller->updateCardEntry(item);
}

void GameSession::selectionModeRepeater(bool enable, bool owned)
{
	controller->setCardSelectMode(enable, owned);
}

void GameSession::cardCountRepeater(int count)
{
	controller->showEnemyCardCount(count);
}

void GameSession::effectsInfoRepeater(QList<effectInfoItem> effs)
{
	controller->callForActionChoose(effs);
}

void GameSession::restartPlayerThread()
{
	players[currentTurn]->getThread()->terminate();
	players[currentTurn]->getThread()->start();
}

void GameSession::sendCardSelection(QVector<QString> ids, effectInfoItem eff)
{
	selection = ids;
	eInfo = eff;
	players[currentTurn]->tellSelectedEffectInfo(eff);
	players[currentTurn]->pickCards(ids);
	restartPlayerThread();
}

void GameSession::setCurEffInfo(effectInfoItem eff)
{
	eInfo = eff;
}
