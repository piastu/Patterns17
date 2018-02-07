#ifndef EFFECTFACTORY_H
#define EFFECTFACTORY_H

#include <QObject>
#include "defs.h"
#include "namegen.h"
#include "gamesession.h"
#include "effect.h"

class GameSession;
class AttackEffect;
class HelpEffect;

class EffectBuilder : public QObject
{
		Q_OBJECT
	public:
		EffectBuilder(QObject *parent = 0);
		void generateEffect(int eType);
		void applyModifier();
		IEffect *getEffect();
	private:
		IEffect *result;
};

class EffectBuildDirector : public QObject
{
		Q_OBJECT
	public:
		EffectBuildDirector(QObject *parent = 0);
		EffectBuildDirector(EffectBuilder *bldr, QObject *parent = 0);
		void construct();
	private:
		EffectBuilder *builder;
};

class EffectFactory : public QObject
{
		Q_OBJECT
	public:
		explicit EffectFactory(QObject *parent = 0);
		void setContext(GameSession *gs);
		void installNamegen(NameGen *ng);
		IEffect * generateEffect(bool connection = true);
	private:
		GameSession *context;
		NameGen *nameGen;
		EffectBuilder *builder;
		EffectBuildDirector *director;

	signals:

	public slots:
};

#endif // EFFECTFACTORY_H
