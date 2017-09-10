#include "entity.h"

Entity::Entity(QPoint startCoord, QObject *parent):QObject(parent)
{
	coord = startCoord;
}

void Entity::Draw(QPainter *pntr, QRectF geom)
{
	pntr->drawLine(QPointF(geom.x(), geom.y()), QPointF(geom.x() + geom.width() - 1, geom.y() + geom.height() - 1));
}

QPoint Entity::getCoord()
{
	return coord;
}

Wall::Wall(QPoint startCoord, QObject *parent):Entity(startCoord, parent)
{

}

void Wall::Draw(QPainter *pntr, QRectF geom)
{
	pntr->fillRect(geom, QBrush(color_wall));
}

Table::Table(QPoint startCoord, QObject *parent):Entity(startCoord, parent)
{
	freeSides.fill(true, 4);
	occupiedSides.fill(false, 4);
}

int Table::getOccupiedState()
{
	// 0 - все места свободны
	// 1 - есть занятые места, но есть и свободные
	// 2 - свободных мест нет
	int _free = 0, _occ = 0;
	for (int i = 0; i < 4; i++)
	{
		if (freeSides[i])
		{
			_free++;
			if (occupiedSides[i])
				_occ++;
		}
	}
	if (_occ == 0)
		return 0;
	else if ( _occ < _free)
		return 1;
	else
		return 2;
}

void Table::Draw(QPainter *pntr, QRectF geom)
{
	pntr->fillRect(QRectF(geom.x() + geom.width() * 0.1, geom.y() + geom.height() * 0.1, geom.width() * 0.8, geom.height() * 0.8), QBrush(color_table));
}

int Table::determineSide(QPoint point)
{
	if ((coord - point).manhattanLength() == 1)
	{
		if (point == (coord at_north))
			return 0;
		else if (point == (coord at_west))
			return 1;
		else if (point == (coord at_south))
			return 2;
		else if (point == (coord at_east))
			return 3;
	}
	return -1;
}

QPoint Table::getFreeSide()
{
	for (int i = 0; i < 4; i++)
	{
		if (freeSides[i] && !occupiedSides[i])
		{
			switch (i)
			{
				case 0:
					return coord at_north;
				case 1:
					return coord at_west;
				case 2:
					return coord at_south;
				case 3:
					return coord at_east;
			}
		}
	}
	return point_fail;
}

void Table::setFreeSides(bool north, bool west, bool south, bool east)
{
	freeSides[0] = north;
	freeSides[1] = west;
	freeSides[2] = south;
	freeSides[3] = east;
}

bool Table::isSideFree(int side)
{
	if (side >= 0 && side <= 3)
		return freeSides[side];
	else
		return false;
}

void Table::setSideOccupied(int side, bool state)
{
	if (side >= 0 && side <= 3)
		occupiedSides[side] = state;
}

Counter::Counter(QPoint startCoord, int _type, QObject *parent):Entity(startCoord, parent)
{
	type = _type;
	locked = false;
}

void Counter::Draw(QPainter *pntr, QRectF geom)
{
	pntr->fillRect(geom, QBrush(color_counter));
	switch (type)
	{
		case 0:
			{
				// раздача посуды
				break;
			}
		case 1:
			{
				// касса
				pntr->fillRect(QRectF(geom.x() + geom.width() * 0.2, geom.y() + geom.height() * 0.2, geom.width() * 0.6, geom.height() * 0.6), QBrush(QColor(195, 195, 195)));
				break;
			}
		case 2:
			{
				// сброс посуды
				pntr->fillRect(QRectF(geom.x() + geom.width() * 0.2, geom.y() + geom.height() * 0.2, geom.width() * 0.6, geom.height() * 0.6), QBrush(QColor(80, 80, 10)));
				break;
			}
		case 3:
			{
				// раковина
				pntr->fillRect(QRectF(geom.x() + geom.width() * 0.2, geom.y() + geom.height() * 0.2, geom.width() * 0.6, geom.height() * 0.6), QBrush(QColor(128, 128, 128)));
				break;
			}
		case 4:
			{
				// плита
				pntr->setBrush(QBrush(QColor(128, 128, 128)));
				pntr->drawEllipse(QPointF(geom.x() + geom.width() * 0.25, geom.y() + geom.height() * 0.25), geom.width() * 0.2, geom.height() * 0.2);
				pntr->drawEllipse(QPointF(geom.x() + geom.width() * 0.25, geom.y() + geom.height() * 0.75), geom.width() * 0.2, geom.height() * 0.2);
				pntr->drawEllipse(QPointF(geom.x() + geom.width() * 0.75, geom.y() + geom.height() * 0.25), geom.width() * 0.2, geom.height() * 0.2);
				pntr->drawEllipse(QPointF(geom.x() + geom.width() * 0.75, geom.y() + geom.height() * 0.75), geom.width() * 0.2, geom.height() * 0.2);
				break;
			}
		case 5:
			{
				// витрина
				pntr->fillRect(QRectF(geom.x(), geom.y() + geom.height() * 0.1, geom.width(), geom.height() * 0.8), QBrush(QColor(153, 217, 234)));
				break;
			}
	}
}

void Counter::setEntry(QPoint point, bool forCustomers)
{
	if (forCustomers)
		customerEntry = point;
	else
		employeeEntry = point;
}

QPoint Counter::getEntry(bool forCustomers)
{
	return forCustomers ? customerEntry : employeeEntry;
}

int Counter::getType()
{
	return type;
}

QList<Item *> Counter::takeAllItems()
{
	QList<Item *> items;
	while (inventory.size() > 0)
	{
		items.push_back(inventory.takeAt(0));
	}
	return items;
}

Item * Counter::takeSingleItem(QString id)
{
	try
	{
	if (!locked)
	{
		locked = true;
		foreach (Item *item, inventory) {

			if (item->getID() == id)
			{
				locked = false;
				return inventory.takeAt(inventory.indexOf(item));
			}
		}
		locked = false;
	}
	}
	catch (...)
	{
		cout << QString("It seems like you got a SIGSEGV exception. Please close the app softly next time.").toStdString() << endl;
	}
	return NULL;
}

void Counter::putItem(Item *item)
{
	inventory.push_back(item);
}

bool Counter::isEmpty()
{
	return (inventory.size() == 0);
}

bool Counter::isLocked()
{
	return locked;
}

void Counter::setLocked(bool lock)
{
	if (locked != lock)
	locked = lock;
}

void Counter::destroy()
{
	while (inventory.size() > 0)
	{
		Item *i = inventory.takeAt(0);
		i->deleteLater();
	}
}
