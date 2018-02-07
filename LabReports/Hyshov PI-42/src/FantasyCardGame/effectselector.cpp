#include "effectselector.h"

IEffectSelector::IEffectSelector(QObject *parent) : QObject(parent)
{

}

EffectSelectorRandom::EffectSelectorRandom(QObject *parent) : IEffectSelector(parent)
{

}

QList<IEffect *> EffectSelectorRandom::selectEffect(QList<IEffect *> effs)
{
	return {effs[Random::randInt(0, effs.size() - 1)]};
}

int EffectSelectorRandom::getType()
{
	return 0;
}

EffectSelectorAll::EffectSelectorAll(QObject *parent) : IEffectSelector(parent)
{

}

QList<IEffect *> EffectSelectorAll::selectEffect(QList<IEffect *> effs)
{
	QList<IEffect *> result, src = effs;
	while (!src.empty())
		result.push_back(src.takeAt(Random::randInt(0, src.size() - 1)));
	return result;
}

int EffectSelectorAll::getType()
{
	return 1;
}
