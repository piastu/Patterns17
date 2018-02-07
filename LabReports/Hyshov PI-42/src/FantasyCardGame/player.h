#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "defs.h"
#include "card.h"

class Player;
class PlayerMediator;

// интерфейс классов состояний
class IPlayerState : public QObject
{
	Q_OBJECT
	public:
		IPlayerState(QObject *parent = 0);
		IPlayerState(Player *plr, QObject *parent = 0);
		virtual void setContext(Player *plr) = 0;
		virtual Player * getContext() = 0;
		virtual void run() = 0;
};

// начальное состояние
class PlayerStateInitial : public IPlayerState
{
	Q_OBJECT
	private:
		Player *context;
	public:
		PlayerStateInitial(QObject *parent = 0);
		PlayerStateInitial(Player *plr, QObject *parent = 0);
		void setContext(Player *plr);
		Player * getContext();
		void run();
};

// состояние выбора карты
class PlayerStateCardSelect : public IPlayerState
{
	Q_OBJECT
	private:
		Player *context;
	public:
		PlayerStateCardSelect(QObject *parent = 0);
		PlayerStateCardSelect(Player *plr, QObject *parent = 0);
		void setContext(Player *plr);
		Player * getContext();
		void run();
};

// состояние задействования карты
class PlayerStateCardActivation : public IPlayerState
{
	Q_OBJECT
	private:
		Player *context;
	public:
		PlayerStateCardActivation(QObject *parent = 0);
		PlayerStateCardActivation(Player *plr, QObject *parent = 0);
		void setContext(Player *plr);
		Player * getContext();
		void run();
};

// состояние выбора цели
class PlayerStateTargetSelect : public IPlayerState
{
	Q_OBJECT
	private:
		Player *context;
	public:
		PlayerStateTargetSelect(QObject *parent = 0);
		PlayerStateTargetSelect(Player *plr, QObject *parent = 0);
		void setContext(Player *plr);
		Player * getContext();
		void run();
};

// конечное состояние
class PlayerStateFinal : public IPlayerState
{
	Q_OBJECT
	private:
		Player *context;
	public:
		PlayerStateFinal(QObject *parent = 0);
		PlayerStateFinal(Player *plr, QObject *parent = 0);
		void setContext(Player *plr);
		Player * getContext();
		void run();
};

class CPUCardPickStrategy
{
	public:
		CPUCardPickStrategy();
		virtual int pickCard(QList<ICard *> cards) = 0;
};

class CPUPickRandom : public CPUCardPickStrategy
{
	public:
		CPUPickRandom();
		int pickCard(QList<ICard *> cards);
};

class CPUPickWeakestFirst : public CPUCardPickStrategy
{
	public:
		CPUPickWeakestFirst();
		int pickCard(QList<ICard *> cards);
};

// класс игрока
class Player : public QObject
{
	Q_OBJECT
	private:
		// карты
		QList<ICard *> cards;
		// карты на поле
		QList<ICard *> cardsInUse;
		// показатель того, компьютер это, или человек
		bool cpu;
		// состояние
		int actionID;
		QList<QString> actionPick;
		QVector<QString> selection;
		// выбранные для действия карты
		QList<ICard *> pickedCards;
		int currentCardAction;
		QString currentPick;
		// тред
		QThread *assignedThread;
		// текущее состояние
		IPlayerState *currentState;
		//
		bool needToRestartThread;
		effectInfoItem eInfo;
		CPUCardPickStrategy *pickStrategy, *pickStrategyUsed;
		PlayerMediator *mediator;
	public:
		// конструкторы
		Player(QObject *parent = 0);
		Player(bool isCPU, QObject *parent = 0);
		// получение карт
		QList <ICard *> getCards();
		QList <ICard *> getCardsInUse();
		QList <ICard *> getPickedCards();
		// отдача карт
		void giveCards(QList<ICard *> cardsToGive);
		void pickCards(QList<ICard *> cardsToPick);
		void pickCards(QVector<QString> cardsToPick);
		void setCards(QList<ICard *> cardsToSet);
		void setCardsInUse(QList<ICard *> cardsUsed);
		bool isCPU();
		// получение треда
		QThread* getThread();
		// установка состояния
		void setAction(int id, QList<QString> pick);
		void setState(IPlayerState *state);
		void setState(IPlayerState *state, QList<QString> pick);
		QList<QString> getActionPick();
		QString getCurrentPick();
		QVector<QString> getSelection();
		void setCurrentPick(QString pick);
		void chooseCardAction(int id);
		int getCardAction();
		QString getCardFullInfo(QString uid);
		void setRestartTask(bool ok);
		CPUCardPickStrategy * getStrategy(bool forActivation = false);
		void attachMediator(PlayerMediator *mediator);
		void detachMediator(PlayerMediator *mediator);
		QList <ICard *> lookForNextPlayerUsedCards();
		void tellSelectedEffectInfo(effectInfoItem e);
		effectInfoItem getSelectedEffectInfo();
	public slots:
		// выброс карты
		void disposeCard();
		// ход
		void makeTurn();
		// вызов выбора действия
		// (только для компьютера)
		void callActionSelect();
		void callTurnEnd();
	signals:
		void removeID(listItem);
		void addID(listItem item, int dest);
		void showPickedCardInfo(QList<effectInfoItem> effs);
		void showPickedCardInfoSingle(effectInfoItem eff);
		void showCardCount(int count);
		void callCardSelect();
		void turnEnd();
		void restart();
		void sendMsg(QString msg);
		sendActionSelect(int);
};

class PlayerMediator : public QObject
{
	Q_OBJECT
	private:
		QList<Player *> subscribers;
	public:
		PlayerMediator(QObject *parent = 0);
		QList<ICard *> showNextPlayerCards();
};

#endif // PLAYER_H
