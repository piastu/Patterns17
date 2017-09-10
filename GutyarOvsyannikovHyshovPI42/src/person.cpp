#include "person.h"

Person::Person(QPoint startCoord, QObject *parent) : QObject(parent)
{
	coord = startCoord;
	actionStep = 0;
	personToInteract = NULL;
	counterToInteract = NULL;
	id = qrand()%10000;
}

void Person::Draw(QPainter *pntr, QRectF geom)
{
	pntr->setBrush(QColor(Qt::gray));
	pntr->drawEllipse(QPointF(geom.x() + geom.width() * 0.5, geom.y() + geom.height() * 0.5), geom.width() * 0.3, geom.height() * 0.3);
}

QPoint Person::getCoord()
{
	return coord;
}

void Person::Act()
{

}

void Person::moveByPath(QList<QPoint> path)
{
	if (path.size() == 1)
		if (path.first() == coord)
			path.clear();
	while (!path.isEmpty())
	{
		this->thread()->msleep(200);
		coord = path.front();
		path.pop_front();
		needsRepaint();
	}
}

void Person::setPath(QList<QPoint> path)
{
	currPath = path;
}

void Person::giveItem(Item *item)
{
	inventory.push_back(item);
}

void Person::giveItem(QList<Item *> items)
{
	while (items.size() > 0)
	{
		inventory.push_back(items.takeAt(0));
	}
}

void Person::interactWith(Person *otherPerson)
{
	personToInteract = otherPerson;
}

void Person::interactWith(Counter *counter)
{
	counterToInteract = counter;
}

int Person::getActionStep()
{
	return actionStep;
}

void Person::setActionStep(int step)
{
	actionStep = step;
}

int Person::getId()
{
	return id;
}

Customer::Customer(QPoint startCoord, float pocketMoney, QObject *parent):Person(startCoord, parent)
{
	groupid = -1;
	money = pocketMoney;
	drawColor = QColor(qrand()%250, qrand()%250, qrand()%250);
	tableToOccupy = NULL;
	dishToOrder = NULL;
	served = false;
}

Customer::Customer(QPoint startCoord, int groupID, float pocketMoney, QObject *parent):Person(startCoord, parent)
{
	groupid = groupID;
	money = pocketMoney;
	drawColor = QColor(qrand()%250, qrand()%250, qrand()%250);
	dishToOrder = NULL;
	tableToOccupy = NULL;
	served = false;
}

void Customer::Draw(QPainter *pntr, QRectF geom)
{
	pntr->setBrush(drawColor);
	// рисуем со случайным отклонением, дабы в одной клетке не наслаивались друг на друга (типа, мимо друг друга идут)
	QRectF circle(geom.center() - QPointF(geom.width() * 0.3, geom.height() * 0.3) + QPointF(geom.width() * ((float)(qrand()%200 - 100) / 1000.0), geom.height() * ((float)(qrand()%200 - 100) / 1000.0)), QSizeF(geom.width() * 0.6, geom.height() * 0.6));
	//geom.center() + QPointF(geom.width() * 0.3, geom.height() * 0.3)
	pntr->drawEllipse(circle);
	if (groupid != -1)
	{
		QPen oldPen = pntr->pen();
		pntr->setPen(QColor(255 - drawColor.red(), 255 - drawColor.green(), 255 - drawColor.blue()));
		pntr->setFont(QFont(pntr->font().family(), -1, QFont::Bold));
		pntr->drawText(circle, QString::number(groupid));
		pntr->setPen(oldPen);
	}
}

void Customer::Act()
{
	do
	{
		switch (actionStep)
		{
			case 0:
				{
					// посетитель заходит в помещение
					emit moveMe();
					do
					{
						this->thread()->msleep(10);
					} while (currPath.size() == 0);
					moveByPath(currPath);
					actionStep = 1;
					break;
				}
			case 1:
				{
					// посетитель изучает меню
					emit pickDishToOrder();
					do
					{
						this->thread()->msleep(100);
						if (actionStep == 10)
							break;
					} while (dishToOrder == NULL);
					if (actionStep == 10)
						break;
					message("Посетитель #" + QString::number(id) + " решил выбрать *" + dishToOrder->getName() + "* за " + QString::number(dishToOrder->getPrice()));
					readyToAct();
					// и берет вещи
					do
					{
						this->thread()->msleep(200);
					} while (counterToInteract == NULL);
					Item *currItem = NULL;
					do
					{
						currItem = counterToInteract->takeSingleItem("Tray");
						if (currItem == NULL)
							this->thread()->msleep(100);
					} while (currItem == NULL);
					inventory.push_back(currItem);
					message("Посетитель #" + QString::number(id) + " берет поднос...");
					currItem = NULL;
					do
					{
						currItem = counterToInteract->takeSingleItem("Plate");
						if (currItem == NULL)
							this->thread()->msleep(100);
					} while (currItem == NULL);
					inventory.push_back(currItem);
					message("Посетитель #" + QString::number(id) + " берет тарелку...");
					currItem = NULL;
					QList<bool> reqUtensils = dishToOrder->getReqUtensils();
					if (reqUtensils[1])
					{
						do
						{
							currItem = counterToInteract->takeSingleItem("Spoon");
							if (currItem == NULL)
								this->thread()->msleep(100);
						} while (currItem == NULL);
						inventory.push_back(currItem);
						message("Посетитель #" + QString::number(id) + " берет ложку...");
						currItem = NULL;
					}
					if (reqUtensils[0])
					{
						currItem = counterToInteract->takeSingleItem("Fork");
						if (currItem != NULL)
						{
							message("Посетитель #" + QString::number(id) + " берет вилку...");
							inventory.push_back(currItem);
						}
						else
						{
							do
							{
								currItem = counterToInteract->takeSingleItem("Spoon");
								if (currItem == NULL)
									this->thread()->msleep(100);
							} while (currItem == NULL);
							message("Посетитель #" + QString::number(id) + " берет ложку (вместо вилки)...");
							inventory.push_back(currItem);
						}
					}
					currItem = NULL;
					if (reqUtensils[2])
					{
						currItem = counterToInteract->takeSingleItem("Knife");
						if (currItem != NULL)
						{
							message("Посетитель #" + QString::number(id) + " берет нож...");
							inventory.push_back(currItem);
						}
					}
					currItem = NULL;
					currItem = counterToInteract->takeSingleItem("Towel");
					if (currItem != NULL)
					{
						message("Посетитель #" + QString::number(id) + " берет салфетку...");
						inventory.push_back(currItem);
					}
					counterToInteract = NULL;
					actionStep = 2;
					break;
				}
			case 2:
				{
					// посетитель встает в очередь, потом делает заказ
					do
					{
						readyToAct();
						this->thread()->msleep(200);
						if (served)
							break;
						moveMe();
						this->thread()->msleep(200);
						if (!currPath.isEmpty() && currPath.first() != point_fail)
						{
							moveByPath(currPath);
						}
						this->thread()->msleep(200);
					} while (!served);
					message("Посетитель #" + QString::number(id) + " сделал заказ и ищет стол, чтобы сесть...");
					actionStep = 3;
					break;
				}
			case 3:
				{
					// посетитель выбирает стол и идет к нему
					needTable();
					do
					{
						this->thread()->msleep(100);
					} while (currPath.size() == 0);
					moveByPath(currPath);
					if (tableToOccupy == NULL)
						break;
					this->thread()->msleep(100);
					actionStep = 4;
					break;
				}
			case 4:
				{
					bool done = false;
					do
					{
						for (int i = 0; i < inventory.size(); i++)
						{
							inventory.at(i)->Use();
							done = done || inventory.at(i)->isDisposeRequired();
							if (done)
								break;
							this->thread()->msleep(100);
						}
					} while (!done);
					tableToOccupy->setSideOccupied(tableToOccupy->determineSide(coord), false);
					message("Посетитель #" + QString::number(id) + " наелся.");
					actionStep = 5;
					break;
				}
			case 5:
				{
					emit moveMe();
					do
					{
						this->thread()->msleep(100);
					} while (currPath.isEmpty());
					moveByPath(currPath);
					emit readyToAct();
					do
					{
						this->thread()->msleep(100);
					} while (counterToInteract == NULL);
					while (inventory.size() > 0)
					{
						counterToInteract->putItem(inventory.takeAt(0));
					}
					message("Посетитель #" + QString::number(id) + " сбросил посуду и идет на выход...");
					actionStep = 10;
					break;
				}
			case 10:
				{
					emit moveMe();
					do
					{
						this->thread()->msleep(100);
					} while (currPath.size() == 0);
					moveByPath(currPath);
					doDelay(200);
					actionStep = -1;
					emit deleteMe();
					break;
				}
		}
	} while (actionStep != -1);
	emit deleteMe();
}

void Customer::occupyTable(Table *tbl)
{
	tableToOccupy = tbl;
}

float Customer::getMoney()
{
	return money;
}

void Customer::setDish(Dish *dish)
{
	dishToOrder = dish;
}

void Customer::takeMoney(float sum)
{
	money -= sum;
}

void Customer::serve()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory.at(i)->getID() == "Plate")
		{
			do
			{
				this->thread()->msleep(800);
			} while (dishToOrder->getQuantity() <= 0);
			dynamic_cast<Plate *>(inventory.at(i))->fillWith(dishToOrder);
			money -= dishToOrder->getPrice();
			served = true;
			break;
		}
	}
}

bool Customer::isServed()
{
	return served;
}

Employee::Employee(QPoint startCoord, int type, QObject *parent):Person(startCoord, parent)
{
	role = type;
}

QPair<QColor, QColor> Employee::getDrawColor()
{
	switch (role)
	{
		case 0:
			return QPair<QColor, QColor>(color_cashier, color_cashier_cap);
		case 1:
			return QPair<QColor, QColor>(color_cook, color_cook_cap);
		case 2:
			return QPair<QColor, QColor>(color_dishwasher, color_dishwasher_cap);
	}
	return QPair<QColor, QColor>(QColor(255, 0, 0), QColor(0, 0, 255));
}

void Employee::Draw(QPainter *pntr, QRectF geom)
{
	pntr->setBrush(getDrawColor().first);
	pntr->drawEllipse(QPointF(geom.x() + geom.width() * 0.5, geom.y() + geom.height() * 0.5), geom.width() * 0.3, geom.height() * 0.3);
	pntr->setBrush(getDrawColor().second);
	pntr->drawEllipse(QPointF(geom.x() + geom.width() * 0.5, geom.y() + geom.height() * 0.5), geom.width() * 0.15, geom.height() * 0.15);
}

void Employee::Act()
{
	do
	{
		switch (role)
		{
			case 0:
				{
					switch (actionStep)
					{
						case 0:
							{
								if (personToInteract != NULL)
									if (!dynamic_cast<Customer *>(personToInteract)->isServed())
									{
										dynamic_cast<Customer *>(personToInteract)->serve();
										message("Кассир обслужил посетителя #" + QString::number(dynamic_cast<Customer *>(personToInteract)->getId()) + ".");
										personToInteract = NULL;
										readyToAct();
									}
								this->thread()->msleep(10);
								break;
							}
						default:
							break;
					}
					break;
				}
			case 1:
				{
					switch (actionStep)
					{
						case 0:
							{
								do
								{
									readyToAct();
									this->thread()->msleep(100);
								} while (dishes.size() == 0);
								message("Повар пошел готовить блюда...");
								moveMe();
								do
								{
									this->thread()->msleep(100);
								} while (currPath.isEmpty());
								moveByPath(currPath);
								while (dishes.size() > 0)
								{
									int quantity = dishes.at(0)->getQuantityToCook();
									for (int i = 0; i < quantity; i++)
									{
										this->thread()->msleep(600);
										dishes.at(0)->cook();
									}
									dishes.pop_front();
								}
								message("Повар все приготовил.");
								actionStep = 1;
								break;
							}
						case 1:
							{
								readyToAct();
								moveMe();
								do
								{
									this->thread()->msleep(100);
								} while (currPath.isEmpty());
								moveByPath(currPath);
								actionStep = 0;
								break;
							}
					}
					break;
				}
			case 2:
				{
					switch (actionStep)
					{
						case 0:
							{
								do
								{
									readyToAct();
									this->thread()->msleep(100);
								} while (counterToInteract == NULL);
								moveMe();
								do
								{
									this->thread()->msleep(100);
								} while (currPath.isEmpty());
								moveByPath(currPath);
								this->giveItem(counterToInteract->takeAllItems());
								message("Посудомойщик забрал грязную посуду.");
								counterToInteract = NULL;
								actionStep = 1;
								break;
							}
						case 1:
							{
								moveMe();
								do
								{
									this->thread()->msleep(100);
								} while (currPath.isEmpty());
								moveByPath(currPath);
								currPath.clear();
								foreach (Item *item, inventory)
								{
									this->thread()->msleep(500);
									if (item != NULL && item != nullptr)
										item->prepare();
								}
								message("Посудомойщик помыл посуду.");
								actionStep = 2;
								break;
							}
						case 2:
							{
								readyToAct();
								do
								{
									this->thread()->msleep(100);
								} while (counterToInteract == NULL);
								moveMe();
								do
								{
									this->thread()->msleep(100);
								} while (currPath.isEmpty());
								moveByPath(currPath);
								currPath.clear();
								while (inventory.size() > 0)
								{
									counterToInteract->putItem(inventory.takeAt(0));
								}
								message("Посудомойщик разложил чистую посуду на раздаче.");
								counterToInteract = NULL;
								actionStep = 0;
								break;
							}
					}
					break;
				}
			default:
				break;
		}
	}
	while (actionStep != -1);
}

int Employee::getType()
{
	return role;
}

void Employee::setDishList(QList<Dish *> lst)
{
	dishes = lst;
}
