#pragma once
#ifndef IEFFECT_H
#define IEFFECT_H

#include <QObject>
#include "defs.h"
#include "transmitters.h"

const QList<QString> effectDict = {"AttackEffect",
								   "HelpEffect"};
class ICard;

// интерфейс действия карты
class IEffect : public QObject
{
	Q_OBJECT
	public:
		IEffect(QObject *parent = 0);
		virtual QString getName() = 0;
		virtual void setName(QString effectName) = 0;
		virtual int getStat(QString statName) = 0;
		virtual void setStat(QString statName, int statVal) = 0;
		virtual void act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src) = 0;
		virtual QString getFullInfo() = 0;
		virtual effectInfoItem getInfo() = 0;
		virtual IEffect * clone() = 0;
		// загрузка и сохранение
		virtual void loadFromStream(QDataStream *stream) = 0;
		virtual void saveToStream(QDataStream *stream) = 0;
	signals:
		void callCardSelect();
		void done();
		void sendMsg(QString msg);
};

class EffectChainlink
{
	private:
		IEffect *effect;
		EffectChainlink *next;
	public:
		EffectChainlink(IEffect *effect, EffectChainlink *next = nullptr);
		void act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src);
		~EffectChainlink();
};

// атака на другую карту (урон другой и трата "энергии" у своей)
class AttackEffect : public IEffect
{
	Q_OBJECT
	private:
		QString name;	// назавние
		int power;		// сила
		int cost;		// затраты
	public:
		AttackEffect(QObject *parent = 0);
		QString getName();
		void setName(QString effectName);
		int getStat(QString statName);
		void setStat(QString statName, int statVal);
		void act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src);
		QString getFullInfo();
		effectInfoItem getInfo();
		IEffect * clone();
		void loadFromStream(QDataStream *stream);
		void saveToStream(QDataStream *stream);
};

// помощь "своей" карте
class HelpEffect : public IEffect
{
	Q_OBJECT
	private:
		QString name;
		int amount;
		int helpType;
		int cardsLimit;
	public:
		HelpEffect(QObject *parent = 0);
		QString getName();
		void setName(QString effectName);
		int getStat(QString statName);
		void setStat(QString statName, int statVal);
		void act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src);
		QString getFullInfo();
		effectInfoItem getInfo();
		IEffect * clone();
		void loadFromStream(QDataStream *stream);
		void saveToStream(QDataStream *stream);
};

// дестабилизатор
// после срабатывания основного действия докидывает еще несколько очков
class EffectDestabilizer : public IEffect
{
	Q_OBJECT
	private:
		IEffect *coreEffect;
		QString name;
		int amount;
	public:
		EffectDestabilizer(QObject *parent = 0);
		EffectDestabilizer(IEffect *core, QObject *parent = 0);
		QString getName();
		void setName(QString effectName);
		int getStat(QString statName);
		void setStat(QString statName, int statVal);
		void act(QVector<StatsTransmitter *> cardsToAffect, StatsTransmitter *src);
		QString getFullInfo();
		effectInfoItem getInfo();
		IEffect * clone();
		void loadFromStream(QDataStream *stream);
		void saveToStream(QDataStream *stream);
};

#endif // IEFFECT_H
