#include "effectfactory.h"

EffectFactory::EffectFactory(QObject *parent) : QObject(parent)
{
	builder = new EffectBuilder(this);
	director = new EffectBuildDirector(builder, this);
}

void EffectFactory::setContext(GameSession *gs)
{
	context = gs;
}

void EffectFactory::installNamegen(NameGen *ng)
{
	nameGen = ng;
}

IEffect *EffectFactory::generateEffect(bool connection)
{
	IEffect *e;
	director->construct();
	e = builder->getEffect();
	if (connection)
		connect(e, SIGNAL(callCardSelect()), context, SLOT(cardSelectCall()));
	connect(e, SIGNAL(sendMsg(QString)), context->getInfoTrans(), SLOT(receiveMsg(QString)));
	return e;
}

EffectBuilder::EffectBuilder(QObject *parent)
{

}

void EffectBuilder::generateEffect(int eType)
{
	NameGen *nameGen = new NameGen();
	switch (eType)
	{
		case 0:
			{
				result = new AttackEffect();
				result->setName(nameGen->randomEffectName());
				result->setStat("cost", Random::randInt(1, 5));
				result->setStat("power", Random::randInt(10, 40));
				break;
			}
		case 1:
			{
				result = new HelpEffect();
				result->setName(nameGen->randomEffectName());
				result->setStat("amount", Random::randInt(10, 50));
				result->setStat("limit", 1);
				result->setStat("helptype", Random::randIntWeighted({10, 5}));
				break;
			}
	}
}

void EffectBuilder::applyModifier()
{
	EffectDestabilizer *destab = new EffectDestabilizer(result);
	destab->setName("разброс");
	destab->setStat("distAmount", Random::randInt(5, 10));
	result = destab;
}

IEffect *EffectBuilder::getEffect()
{
	return result;
}

EffectBuildDirector::EffectBuildDirector(QObject *parent) : QObject(parent)
{

}

EffectBuildDirector::EffectBuildDirector(EffectBuilder *bldr, QObject *parent) : EffectBuildDirector(parent)
{
	builder = bldr;
}

void EffectBuildDirector::construct()
{
	builder->generateEffect(Random::randIntWeighted({75, 25}));
	if (Random::probability(0.5))
		builder->applyModifier();
}
