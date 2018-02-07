#ifndef CARDPOOL_H
#define CARDPOOL_H

#include <QObject>
#include "defs.h"
#include "card.h"

class CardPool : public QObject
{
		Q_OBJECT
	public:
		static CardPool * getInstance();
		// добавление в пул и извлечение из него
		void putCard(ICard *card);
		ICard * getCard();
		// перетасовка "колоды"
		void shuffle();
		void clear();
		bool isEmpty();
	private:
		static CardPool *instance;
		QList<ICard *> cards;
		explicit CardPool(QObject *parent = 0);
	signals:

	public slots:
};

#endif // CARDPOOL_H
