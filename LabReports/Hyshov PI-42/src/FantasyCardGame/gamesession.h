#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QObject>
#include "gamecontroller.h"
#include "defs.h"
#include "card.h"
#include "effect.h"
#include "namegen.h"
#include "player.h"
#include "effectfactory.h"
#include "cardfactory.h"
#include "cardpool.h"
#include "gamestatemanager.h"

class EffectFactory;
class CardFactory;
class CardFactoryTiered;
class CardInfoObserver;
class Player;
class PlayerMediator;
class GameStateManager;

// класс сеанса игры
class GameSession : public QObject
{
	Q_OBJECT
	private:
		static GameSession *instance;
		// интерфейс для взаимодействия
		GameController *controller;
		// игроки
		QList<Player *> players;
		// битые карты
		QList<ICard *> beatenCards;
		// выборка карт по UID
		QVector<QString> selection;
		// инфо по тому или иному действию
		effectInfoItem eInfo;
		// кто сейчас ходит
		int currentTurn;
		// победитель
		int winner;
		// текущее действие карты
		int curCardAction;
		// готовность
		bool ready;
		InfoTransmitter *infoTrans;
		// фабрики карт
		QList<CardFactory *> cardFactories;
		// с уровнем
		QList<CardFactoryTiered *> cardFactoriesTiered;
		// фабрика эффектов
		EffectFactory *effFactory;
		// наблюдатель информации о состоянии карт
		CardInfoObserver *cio;
		// менеджер состояний для загрузки и сохранения
		GameStateManager *gsm;
		// посредник между игроками
		PlayerMediator *pMed;
		// приватный конструктор
		GameSession(QObject *parent = 0);
		// генерация карт
		QList<ICard *> generateCards(int num, int ctype = -1, bool connections = true);
	public:
		static GameSession * getInstance(bool reset = false);
		void reset();
		void installController(GameController *gc);
		void initialize(int numCards);
		// получение всех картинок
		QList<listItem> getDrawables();
		// готовность
		bool isReady();
		InfoTransmitter * getInfoTrans();
		QString getCardFullInfo(QString uid);
		int saveState();
		int loadState();
		Player * getCurrentPlayer();
		Player * getNextPlayer();
	public slots:
		// когда карта бита
		void disposeCard();
		void disposeCard(ICard *card);
		// переход хода
		void nextTurn();
		void cardInfoRequest(int dest, QString id);
		// вызов выбора карты
		void cardSelectCall();
		// повторители для работы со списками
		// и отображением данных
		// используют контроллер
		void listItemRemoveRepeater(listItem item);
		void listItemAddRepeater(listItem item, int dest);
		void listItemUpdateRepeater(listItem item);
		void selectionModeRepeater(bool enable, bool owned);
		void cardCountRepeater(int count);
		void effectsInfoRepeater(QList<effectInfoItem> effs);
		// сброс треда игрока
		void restartPlayerThread();
		// отправка выборки карт
		void sendCardSelection(QVector<QString> ids, effectInfoItem eff);
		void setCurEffInfo(effectInfoItem eff);
		void setCurrentAction(int id);
		void msgRepeater(QString msg);
	signals:
		showCardCount(int count);
		getCardInfo(QString cardInfo, int dest);
		setCardSelectionMode(bool enable, bool isOwned);
		void showPickedCardInfo(QList<effectInfoItem> effs);
		// окончание игры
		endGame(int winner);
		initUI();
		sendMsg(QString msg);
};

#endif // GAMESESSION_H
