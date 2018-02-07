#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <QObject>
#include "defs.h"
#include "gamesession.h"
#include "card.h"
#include "namegen.h"
#include "effect.h"
#include "effectselector.h"
#include "effectfactory.h"

class GameSession;
class EffectFactory;

class CardFactoryTiered : public QObject
{
		Q_OBJECT
	public:
		CardFactoryTiered(QObject *parent = 0);
		virtual void setContext(GameSession *gs) = 0;
		virtual void installNamegen(NameGen *ng) = 0;
		virtual void setEffectFactory(EffectFactory *ef) = 0;
		virtual ICard * generateActorCard(bool connection = true) = 0;
		virtual ICard * generateActionCard(bool connection = true) = 0;
		virtual ICard * generateTeamCard(bool connection = true) = 0;
};

class CardFactoryTier2 : public CardFactoryTiered
{
		Q_OBJECT
	public:
		CardFactoryTier2(QObject *parent = 0);
		void setContext(GameSession *gs);
		void installNamegen(NameGen *ng);
		void setEffectFactory(EffectFactory *ef);
		ICard * generateActorCard(bool connection = true);
		ICard * generateActionCard(bool connection = true);
		ICard * generateTeamCard(bool connection = true);
	private:
		GameSession *context;
		NameGen *nameGen;
		EffectFactory *effFactory;
};

class CardFactoryTier3 : public CardFactoryTiered
{
		Q_OBJECT
	public:
		CardFactoryTier3(QObject *parent = 0);
		void setContext(GameSession *gs);
		void installNamegen(NameGen *ng);
		void setEffectFactory(EffectFactory *ef);
		ICard * generateActorCard(bool connection = true);
		ICard * generateActionCard(bool connection = true);
		ICard * generateTeamCard(bool connection = true);
	private:
		GameSession *context;
		NameGen *nameGen;
		EffectFactory *effFactory;
};

// фабрика карт
class CardFactory : public QObject
{
		Q_OBJECT
	public:
		explicit CardFactory(QObject *parent = 0);
		virtual void setContext(GameSession *gs) = 0;
		virtual void installNamegen(NameGen *ng) = 0;
		virtual void setEffectFactory(EffectFactory *ef) = 0;
		virtual ICard * generateCard(bool connect = true) = 0;

	private:

	signals:

	public slots:
};

// фабрика карт-персонажей
class ActorCardFactory : public CardFactory
{
		Q_OBJECT
	public:
		ActorCardFactory(QObject *parent = 0);
		void setContext(GameSession *gs);
		void installNamegen(NameGen *ng);
		void setEffectFactory(EffectFactory *ef);
		ICard * generateCard(bool connection = true);
	private:
		GameSession *context;
		NameGen *nameGen;
		EffectFactory *effFactory;
};

// фабрика карт-действий
class ActionCardFactory : public CardFactory
{
		Q_OBJECT
	public:
		ActionCardFactory(QObject *parent = 0);
		void setContext(GameSession *gs);
		void installNamegen(NameGen *ng);
		void setEffectFactory(EffectFactory *ef);
		ICard * generateCard(bool connection = true);
	private:
		GameSession *context;
		NameGen *nameGen;
		EffectFactory *effFactory;
};

// фабрика карт-команд
class TeamCardFactory : public CardFactory
{
		Q_OBJECT
	public:
		TeamCardFactory(QObject *parent = 0);
		void setContext(GameSession *gs);
		void installNamegen(NameGen *ng);
		void setEffectFactory(EffectFactory *ef);
		void setSubfactories(CardFactory *forActor, CardFactory *forAction);
		ICard * generateCard(bool connection = true);
	private:
		GameSession *context;
		NameGen *nameGen;
		EffectFactory *effFactory;
		CardFactory *actorFact, *actionFact;
};

#endif // CARDFACTORY_H
