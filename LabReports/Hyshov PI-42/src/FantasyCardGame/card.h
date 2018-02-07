#pragma once
#ifndef ICARD_H
#define ICARD_H

#include <QObject>
#include "defs.h"
#include "effect.h"
#include "effectselector.h"
#include "namegen.h"
#include "transmitters.h"
#include "util.h"
#include "gamesession.h"

class CardInfoObserver;
class CardVisitor;

// интерфейс карты
class ICard : public QObject
{
	Q_OBJECT
	public:
		ICard(QObject *parent = 0);
		// действие
		virtual void act(QList<ICard *> cardsToAffect) = 0;
		// get и set для имени
		virtual QString getName() = 0;
		virtual void setName(QString cardName) = 0;
		virtual QString getUID() = 0;
		virtual void setUID(QString id) = 0;
		virtual QColor getBG() = 0;
		virtual void setBG(QColor bg) = 0;
		// get и set для некоторых числовых данных
		virtual int getStat(QString statName) = 0;
		virtual void setStat(QString statName, int statVal, bool isInc = false) = 0;
		// get и set для списка действий
		virtual void setEffects(QList<IEffect *> effects) = 0;
		virtual QList<IEffect *> getEffects() = 0;
		// обновление статистики
		virtual void updateStats() = 0;
		// получение картинки
		virtual QImage getDrawable(int height = 128) = 0;
		virtual QString getPseudoDrawable() = 0;
		// получение информации (в виде текста)
		virtual QString getFullInfo() = 0;
		// получение информации о действиях
		virtual QList<effectInfoItem> getEffectsInfo() = 0;
		virtual void reset() = 0;
		// работа с наблюдателем
		virtual void attachObserver(CardInfoObserver *observer) = 0;
		virtual void detachObserver(CardInfoObserver *observer) = 0;
		// загрузка и сохранение
		virtual void loadFromStream(QDataStream *stream) = 0;
		virtual void saveToStream(QDataStream *stream) = 0;
		// работа с "посетителями"
		virtual void acceptVisitor(CardVisitor *visitor) = 0;
	public slots:
		virtual void makeActionSelection(int id) = 0;
		virtual void acceptStat(QString statName, int statVal, bool isInc = false) = 0;
	signals:
		void disposeMe();
		void updateDrawable(listItem);
		void callActionSelect();
		void sendMsg(QString msg);
};

class Iterator : public IIterator<ICard *>
{
	private:
		ICollection<ICard *> *data;
		int currID;
	public:
		Iterator();
		Iterator(ICollection<ICard *> *coll);
		ICard * getNext();
		void removeCurrentElement();
		bool hasNext();
};

class Collection : public ICollection<ICard *>
{
	private:
		QList<ICard *> data;
	public:
		friend class Iterator;
		Collection();
		Collection(QList<ICard *> _data);
		ICard * at(int id);
		void removeAt(int id);
		void replaceAt(int id, ICard *src);
		int count();
		Iterator * getIterator();
};

class CardInfoObserver : public QObject
{
	Q_OBJECT
	private:
	public:
		CardInfoObserver(QObject *parent = 0);
		void notify(listItem litem);
		void dispose(ICard *me);
};

// карта-персонаж
// пока позволяют "здоровье" и "энергия", может действовать сколько угодно раз
// может иметь несколько действий
class ActorCard : public ICard
{
	Q_OBJECT
	private:
		QString name, uid;
		int health, healthInit;
		int energy, energyInit;
		int selectedAction;
		QColor bg;
		QList<IEffect *> actionEffect;
		IEffectSelector *defaultSelector;
		CardInfoObserver *cio;
	public:
		ActorCard(QObject *parent = 0);
		void act(QList<ICard *> cardsToAffect);
		QString getName();
		void setName(QString cardName);
		QString getUID();
		void setUID(QString id);
		QColor getBG();
		void setBG(QColor bg);
		int getStat(QString statName);
		void setStat(QString statName, int statVal, bool isInc = false);
		void setEffects(QList<IEffect *> effects);
		QList<IEffect *> getEffects();
		void setEffectSelector(IEffectSelector *selector);
		IEffectSelector * getEffectSelector();
		void updateStats();
		QImage getDrawable(int height = 128);
		QString getPseudoDrawable();
		QString getFullInfo();
		QList<effectInfoItem> getEffectsInfo();
		void reset();
		void attachObserver(CardInfoObserver *observer);
		void detachObserver(CardInfoObserver *observer);
		void loadFromStream(QDataStream *stream);
		void saveToStream(QDataStream *stream);
		void acceptVisitor(CardVisitor *visitor);
	public slots:
		void makeActionSelection(int id);
		void acceptStat(QString statName, int statVal, bool isInc = false);
};

// карта-действие
// имеет только одно действие
// действует только один раз, после чего уходит с поля
// зато неуязвима
class ActionCard : public ICard
{
	Q_OBJECT
	private:
		QString name, uid;
		QColor bg;
		IEffect *actionEffect;
		CardInfoObserver *cio;
	public:
		ActionCard(QObject *parent = 0);
		void act(QList<ICard *> cardsToAffect);
		QString getName();
		void setName(QString cardName);
		QString getUID();
		void setUID(QString id);
		QColor getBG();
		void setBG(QColor bg);
		int getStat(QString statName);
		void setStat(QString statName, int statVal, bool isInc = false);
		void setEffects(QList<IEffect *> effects);
		QList<IEffect *> getEffects();
		void updateStats();
		QImage getDrawable(int height = 128);
		QString getPseudoDrawable();
		QString getFullInfo();
		QList<effectInfoItem> getEffectsInfo();
		void reset();
		void attachObserver(CardInfoObserver *observer);
		void detachObserver(CardInfoObserver *observer);
		void loadFromStream(QDataStream *stream);
		void saveToStream(QDataStream *stream);
		void acceptVisitor(CardVisitor *visitor);
	public slots:
		void makeActionSelection(int id);
		void acceptStat(QString statName, int statVal, bool isInc = false);
};

// карта-команда
// объединяет в себе несколько карт
class TeamCard : public ICard
{
	Q_OBJECT
	private:
		QString name, uid;
		QColor bg;
		QList<ICard *> members, membersBeaten;
		CardInfoObserver *cio;
	public:
		TeamCard(QObject *parent = 0);
		void act(QList<ICard *> cardsToAffect);
		QString getName();
		void setName(QString cardName);
		QString getUID();
		void setUID(QString id);
		QColor getBG();
		void setBG(QColor bg);
		int getStat(QString statName);
		void setStat(QString statName, int statVal, bool isInc = false);
		void setEffects(QList<IEffect *> effects);
		QList<IEffect *> getEffects();
		void updateStats();
		QImage getDrawable(int height = 128);
		QString getPseudoDrawable();
		QString getFullInfo();
		QList<effectInfoItem> getEffectsInfo();
		void setMembers(QList<ICard *> _members, bool beaten = false);
		QList<ICard *> getMembers(bool beaten = false);
		void reset();
		void attachObserver(CardInfoObserver *observer);
		void detachObserver(CardInfoObserver *observer);
		void loadFromStream(QDataStream *stream);
		void saveToStream(QDataStream *stream);
		void acceptVisitor(CardVisitor *visitor);
	public slots:
		void makeActionSelection(int id);
		void acceptStat(QString statName, int statVal, bool isInc = false);
		void cardDispose();
};

class CardVisitor
{
	public:
		CardVisitor();
		virtual void visitActorCard(ActorCard *card) = 0;
		virtual void visitActionCard(ActionCard *card) = 0;
		virtual void visitTeamCard(TeamCard *card) = 0;
};

ICard * matchCardPointer(char cardType);

class CardStreamWriter : public CardVisitor
{
	private:
		QDataStream *stream;
	public:
		CardStreamWriter();
		void setupStream(QDataStream *stream);
		void writeCard(ICard *card);
		void visitActorCard(ActorCard *card);
		void visitActionCard(ActionCard *card);
		void visitTeamCard(TeamCard *card);
};

class CardStreamReader : public CardVisitor
{
	private:
		QDataStream *stream;
	public:
		CardStreamReader();
		void setupStream(QDataStream *stream);
		void readCard(ICard *card);
		void visitActorCard(ActorCard *card);
		void visitActionCard(ActionCard *card);
		void visitTeamCard(TeamCard *card);
};

listItem getCardListItem(ICard *card);

#endif // ICARD_H
