#include "cardpool.h"

CardPool* CardPool::instance = NULL;

CardPool *CardPool::getInstance()
{
	if (instance == NULL)
		instance = new CardPool();
	return instance;
}

void CardPool::putCard(ICard *card)
{
	ICard *cardToPut = card;
	card->reset();
	cards.push_back(cardToPut);
}

ICard *CardPool::getCard()
{
	if (cards.empty())
		return NULL;
	ICard *cardToGet = cards.back();
	cards.pop_back();
	return cardToGet;
}

void CardPool::shuffle()
{
	QList<ICard *> srcCards = cards;
	cards.clear();
	while (!srcCards.empty())
		cards.push_back(srcCards.takeAt(Random::randInt(0, srcCards.size() - 1)));
}

void CardPool::clear()
{
	while (!cards.empty())
		delete cards.takeFirst();
}

bool CardPool::isEmpty()
{
	return (cards.size() == 0);
}

CardPool::CardPool(QObject *parent) : QObject(parent)
{

}
