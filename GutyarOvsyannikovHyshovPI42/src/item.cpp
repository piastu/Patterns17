#include "item.h"

Item::Item(QObject *parent):QObject(parent)
{
	id = QString(this->metaObject()->className());
	status = 100.0;
}

Item::Item(QString _id, QObject *parent):QObject(parent)
{
	id = _id;
	status = 100.0;
}

void Item::Use()
{
	clean = false;
}

QString Item::getID()
{
	return id;
}

void Item::prepare()
{
	clean = true;
}

bool Item::isDisposeRequired()
{
	return (status == 0.0);
}

Plate::Plate(QObject *parent):Item(parent)
{
	id = QString(this->metaObject()->className());
	status = 0.0;
}

void Plate::Use()
{
	if (status > 0.0)
		status -= 1.0;
	if (status <= 0.0)
	{
		status = 0.0;
		emit isFinal();
	}
}

void Plate::fillWith(Dish *dish)
{
	status = 100.0;
	dishName = dish->getName();
	dish->take();
	clean = false;
}
