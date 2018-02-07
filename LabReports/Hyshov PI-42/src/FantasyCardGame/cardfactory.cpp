#include "cardfactory.h"

CardFactory::CardFactory(QObject *parent) : QObject(parent)
{

}

ActorCardFactory::ActorCardFactory(QObject *parent) : CardFactory(parent)
{

}

void ActorCardFactory::setContext(GameSession *gs)
{
	context = gs;
}

void ActorCardFactory::installNamegen(NameGen *ng)
{
	nameGen = ng;
}

void ActorCardFactory::setEffectFactory(EffectFactory *ef)
{
	effFactory = ef;
}

ICard *ActorCardFactory::generateCard(bool connection)
{
	ActorCard *card = new ActorCard();
	card->setName(nameGen->randomActorName());
	QList<IEffect *> effects;
	card->setStat("health", 100, false);
	card->setStat("energy", 100, false);
	int numEffects = Random::randInt(1, 3);
	for (int j = 0; j < numEffects; j++)
	{
		IEffect *e = effFactory->generateEffect(connection);
		effects.push_back(e);
	}
	IEffectSelector *selector;
	switch (Random::randIntWeighted({5, 5}))
	{
		case 0:
			selector = new EffectSelectorRandom();
			break;
		case 1:
			selector = new EffectSelectorAll();
			break;
	}
	card->setEffectSelector(selector);
	card->setEffects(effects);
	if (connection)
	{
		//connect(card, SIGNAL(updateDrawable(listItem)), context, SLOT(listItemUpdateRepeater(listItem)));
		connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	}
	return card;
}

ActionCardFactory::ActionCardFactory(QObject *parent) : CardFactory(parent)
{

}

void ActionCardFactory::setContext(GameSession *gs)
{
	context = gs;
}

void ActionCardFactory::installNamegen(NameGen *ng)
{
	nameGen = ng;
}

void ActionCardFactory::setEffectFactory(EffectFactory *ef)
{
	effFactory = ef;
}

ICard *ActionCardFactory::generateCard(bool connection)
{
	ActionCard *card = new ActionCard();
	card->setName(nameGen->randomActionName());
	IEffect *e = effFactory->generateEffect(connection);
	card->setEffects({e});
	if (connection)
	{
		connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	}
	return card;
}

TeamCardFactory::TeamCardFactory(QObject *parent) : CardFactory(parent)
{

}

void TeamCardFactory::setContext(GameSession *gs)
{
	context = gs;
}

void TeamCardFactory::installNamegen(NameGen *ng)
{
	nameGen = ng;
}

void TeamCardFactory::setEffectFactory(EffectFactory *ef)
{
	effFactory = ef;
}

void TeamCardFactory::setSubfactories(CardFactory *forActor, CardFactory *forAction)
{
	actorFact = forActor;
	actionFact = forAction;
}

ICard *TeamCardFactory::generateCard(bool connection)
{
	int numMembers = Random::randInt(2, 5);
	TeamCard *card = new TeamCard();
	card->setName(nameGen->randomTeamName());
	QList<ICard *> members;
	for (int i = 0; i < numMembers; i++)
	{
		ICard *member;
		switch (Random::randIntWeighted({25, 15, 5}))
		{
			case 0:
				member = actorFact->generateCard(false);
				break;
			case 1:
				member = actionFact->generateCard(false);
				break;
			case 2:
				member = this->generateCard(false);
				break;
		}
		members.push_back(member);
	}
	card->setMembers(members);
	if (connection)
	{
		//connect(card, SIGNAL(updateDrawable(listItem)), context, SLOT(listItemUpdateRepeater(listItem)));
	}
	connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	return card;
}

CardFactoryTiered::CardFactoryTiered(QObject *parent) : QObject(parent)
{

}

CardFactoryTier2::CardFactoryTier2(QObject *parent) : CardFactoryTiered(parent)
{

}

void CardFactoryTier2::setEffectFactory(EffectFactory *ef)
{
	effFactory = ef;
}

ICard *CardFactoryTier2::generateActorCard(bool connection)
{
	ActorCard *card = new ActorCard();
	card->setName(nameGen->randomActorName());
	QList<IEffect *> effects;
	card->setStat("health", 200, false);
	card->setStat("energy", 200, false);
	card->setStat("healthInit", 200, false);
	card->setStat("energyInit", 200, false);
	int numEffects = Random::randInt(1, 3);
	for (int j = 0; j < numEffects; j++)
	{
		IEffect *e = effFactory->generateEffect(connection);
		e->setStat("power", e->getStat("power") * 2);
		e->setStat("amount", e->getStat("amount") * 2);
		effects.push_back(e);
	}
	IEffectSelector *selector;
	switch (Random::randIntWeighted({5, 5}))
	{
		case 0:
			selector = new EffectSelectorRandom();
			break;
		case 1:
			selector = new EffectSelectorAll();
			break;
	}
	card->setEffectSelector(selector);
	card->setEffects(effects);
	if (connection)
	{
		//connect(card, SIGNAL(updateDrawable(listItem)), context, SLOT(listItemUpdateRepeater(listItem)));
		connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	}
	return card;
}

ICard *CardFactoryTier2::generateActionCard(bool connection)
{
	ActionCard *card = new ActionCard();
	card->setName(nameGen->randomActionName());
	IEffect *e = effFactory->generateEffect(connection);
	card->setEffects({e});
	e->setStat("power", e->getStat("power") * 2);
	e->setStat("amount", e->getStat("amount") * 2);
	if (connection)
	{
		//connect(card, SIGNAL(updateDrawable(listItem)), context, SLOT(listItemUpdateRepeater(listItem)));
		connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	}
	return card;
}

ICard *CardFactoryTier2::generateTeamCard(bool connection)
{
	int numMembers = Random::randInt(5, 8);
	TeamCard *card = new TeamCard();
	card->setName(nameGen->randomTeamName());
	QList<ICard *> members;
	for (int i = 0; i < numMembers; i++)
	{
		ICard *member;
		switch (Random::randIntWeighted({25, 15, 5}))
		{
			case 0:
				member = this->generateActorCard(false);
				break;
			case 1:
				member = this->generateActionCard(false);
				break;
			case 2:
				member = this->generateTeamCard(false);
				break;
		}
		members.push_back(member);
	}
	card->setMembers(members);
	connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	return card;
}

void CardFactoryTier2::installNamegen(NameGen *ng)
{
	nameGen = ng;
}

void CardFactoryTier2::setContext(GameSession *gs)
{
	context = gs;
}

CardFactoryTier3::CardFactoryTier3(QObject *parent) : CardFactoryTiered(parent)
{

}

void CardFactoryTier3::setEffectFactory(EffectFactory *ef)
{
	effFactory = ef;
}

ICard *CardFactoryTier3::generateActorCard(bool connection)
{
	ActorCard *card = new ActorCard();
	card->setName(nameGen->randomActorName());
	QList<IEffect *> effects;
	card->setStat("health", 300, false);
	card->setStat("energy", 300, false);
	card->setStat("healthInit", 300, false);
	card->setStat("energyInit", 300, false);
	int numEffects = Random::randInt(1, 3);
	for (int j = 0; j < numEffects; j++)
	{
		IEffect *e = effFactory->generateEffect(connection);
		e->setStat("power", e->getStat("power") * 3);
		e->setStat("amount", e->getStat("amount") * 3);
		effects.push_back(e);
	}
	IEffectSelector *selector;
	switch (Random::randIntWeighted({5, 5}))
	{
		case 0:
			selector = new EffectSelectorRandom();
			break;
		case 1:
			selector = new EffectSelectorAll();
			break;
	}
	card->setEffectSelector(selector);
	card->setEffects(effects);
	if (connection)
	{
		connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	}
	return card;
}

ICard *CardFactoryTier3::generateActionCard(bool connection)
{
	ActionCard *card = new ActionCard();
	card->setName(nameGen->randomActionName());
	IEffect *e = effFactory->generateEffect(connection);
	card->setEffects({e});
	e->setStat("power", e->getStat("power") * 3);
	e->setStat("amount", e->getStat("amount") * 3);
	if (connection)
	{
		connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	}
	return card;
}

ICard *CardFactoryTier3::generateTeamCard(bool connection)
{
	int numMembers = Random::randInt(5, 8);
	TeamCard *card = new TeamCard();
	card->setName(nameGen->randomTeamName());
	QList<ICard *> members;
	for (int i = 0; i < numMembers; i++)
	{
		ICard *member;
		switch (Random::randIntWeighted({25, 15, 5}))
		{
			case 0:
				member = this->generateActorCard(false);
				break;
			case 1:
				member = this->generateActionCard(false);
				break;
			case 2:
				member = this->generateTeamCard(false);
				break;
		}
		members.push_back(member);
	}
	card->setMembers(members);
	connect(card, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	return card;
}

void CardFactoryTier3::installNamegen(NameGen *ng)
{
	nameGen = ng;
}

void CardFactoryTier3::setContext(GameSession *gs)
{
	context = gs;
}
