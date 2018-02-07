#include "effect.h"

IEffect::IEffect(QObject *parent):QObject(parent)
{

}

AttackEffect::AttackEffect(QObject *parent):IEffect(parent)
{

}

QString AttackEffect::getName()
{
	return name;
}

void AttackEffect::setName(QString effectName)
{
	name = effectName;
}

int AttackEffect::getStat(QString statName)
{
	if (statName == "power")
		return power;
	else if (statName == "cost")
		return cost;
	else if (statName == "effectType")
		return 0;
	return 0;
}

void AttackEffect::setStat(QString statName, int statVal)
{
	if (statName == "power")
		power = statVal;
	else if (statName == "cost")
		cost = statVal;
}

void AttackEffect::act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src)
{

	for (int i = 0; i < cardsToAffect.size(); i++)
	{
		src->setStat("energy", -1 * cost, true);
		cardsToAffect[i]->setStat("health", -1 * power, true);
	}
}

QString AttackEffect::getFullInfo()
{
	return name + " (сила "
			+ QString::number(power)
			+ ", стоимость"
			+ QString::number(cost) + ");";
}

effectInfoItem AttackEffect::getInfo()
{
	effectInfoItem result;
	result.info = getFullInfo();
	result.canAffectEnemy = true;
	result.canAffectPlayer = false;
	result.effectType = 0;
	return result;
}

IEffect *AttackEffect::clone()
{
	AttackEffect *eff = new AttackEffect();
	eff->setName(name);
	eff->setStat("power", power);
	eff->setStat("cost", cost);
	return eff;
}

void AttackEffect::loadFromStream(QDataStream *stream)
{
	*stream >> name;
	*stream >> power;
	*stream >> cost;
}

void AttackEffect::saveToStream(QDataStream *stream)
{
	*stream << 'A';
	*stream << name;
	*stream << power;
	*stream << cost;
}

HelpEffect::HelpEffect(QObject *parent):IEffect(parent)
{

}

QString HelpEffect::getName()
{
	return name;
}

void HelpEffect::setName(QString effectName)
{
	name = effectName;
}

int HelpEffect::getStat(QString statName)
{
	if (statName == "amount")
		return amount;
	else if (statName == "helptype")
		return helpType;
	else if (statName == "limit")
		return cardsLimit;
	else if (statName == "effectType")
		return 1;
	return 0;
}

void HelpEffect::setStat(QString statName, int statVal)
{
	if (statName == "amount")
		amount = statVal;
	else if (statName == "helptype")
		helpType = statVal;
	else if (statName == "limit")
		cardsLimit = statVal;
}

void HelpEffect::act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src)
{
	for (int i = 0; i < cardsToAffect.size(); i++)
	{
		if (helpType == 0)
			cardsToAffect[i]->setStat("health", amount, true);
		else
			cardsToAffect[i]->setStat("energy", amount, true);
	}
}

QString HelpEffect::getFullInfo()
{
	return name + " (уровень "
			+ QString::number(amount)
			+ ");";
}

effectInfoItem HelpEffect::getInfo()
{
	effectInfoItem result;
	result.info = getFullInfo();
	result.canAffectEnemy = false;
	result.canAffectPlayer = true;
	result.effectType = 1;
	return result;
}

IEffect *HelpEffect::clone()
{
	HelpEffect *eff = new HelpEffect();
	eff->setName(name);
	eff->setStat("amount", amount);
	eff->setStat("helpType", helpType);
	eff->setStat("cardsLimit", cardsLimit);
	return eff;
}

void HelpEffect::loadFromStream(QDataStream *stream)
{
	*stream >> name;
	*stream >> amount;
	*stream >> helpType;
	*stream >> cardsLimit;
}

void HelpEffect::saveToStream(QDataStream *stream)
{
	*stream << 'H';
	*stream << name;
	*stream << amount;
	*stream << helpType;
	*stream << cardsLimit;
}


EffectDestabilizer::EffectDestabilizer(QObject *parent):IEffect(parent)
{

}

EffectDestabilizer::EffectDestabilizer(IEffect *core, QObject *parent):EffectDestabilizer(parent)
{
	coreEffect = core;
}

QString EffectDestabilizer::getName()
{
	return (coreEffect->getName() + " (" + name + ")");
}

void EffectDestabilizer::setName(QString effectName)
{
	name = effectName;
}

int EffectDestabilizer::getStat(QString statName)
{
	if (statName == "distAmount")
		return amount;
	else
		return coreEffect->getStat(statName);
}

void EffectDestabilizer::setStat(QString statName, int statVal)
{
	if (statName == "distAmount")
		amount = statVal;
	else
		coreEffect->setStat(statName, statVal);
}

void EffectDestabilizer::act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src)
{
	coreEffect->act(cardsToAffect, src);
	int effType = coreEffect->getStat("effectType");
	switch (effType)
	{
		case 0:
			{
				for (int i = 0; i < cardsToAffect.size(); i++)
					cardsToAffect[i]->setStat("health", -1 * (Random::randInt(1, amount)), true);
				break;
			}
		case 1:
			{
				for (int i = 0; i < cardsToAffect.size(); i++)
				{
					if (coreEffect->getStat("helpType") == 0)
						cardsToAffect[i]->setStat("health", amount, true);
					else
						cardsToAffect[i]->setStat("energy", amount, true);
				}
			}
	}
}

QString EffectDestabilizer::getFullInfo()
{
	return coreEffect->getFullInfo() + " (" + name + " (" + QString::number(amount) + "))";
}

effectInfoItem EffectDestabilizer::getInfo()
{
	effectInfoItem result = coreEffect->getInfo();
	result.info = getFullInfo();
	return result;
}

IEffect *EffectDestabilizer::clone()
{
	EffectDestabilizer *eff = new EffectDestabilizer(coreEffect->clone());
	eff->setName(name);
	eff->setStat("distAmount", amount);
	return eff;
}

void EffectDestabilizer::loadFromStream(QDataStream *stream)
{
	*stream >> name;
	*stream >> amount;
	IEffect *eff;
	int effType;
	*stream >> effType;
	switch (effType)
	{
		case 'A':
			eff = new AttackEffect();
			break;
		case 'H':
			eff = new HelpEffect();
			break;
		case 'D':
			eff = new EffectDestabilizer();
			break;
	}
	eff->loadFromStream(stream);
	coreEffect = eff;
}

void EffectDestabilizer::saveToStream(QDataStream *stream)
{
	*stream << 'D';
	*stream << name;
	*stream << amount;
	coreEffect->saveToStream(stream);
}

EffectChainlink::EffectChainlink(IEffect *effect, EffectChainlink *next)
{
	this->effect = effect;
	this->next = next;
}

void EffectChainlink::act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src)
{
	if (effect != nullptr)
		effect->act(cardsToAffect, src);
	if (next != nullptr)
		next->act(cardsToAffect, src);
}

EffectChainlink::~EffectChainlink()
{
	if (next != nullptr)
		delete next;
}
