#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{
	isDesignMode = false;
	placementID = 0;
	placementIDSub = 0;
	countersShortcuts = QList<int>({-1, -1, -1, -1, -1, -1});
}

Model::~Model()
{

}

Model& Model::getInstance()
{
	static Model modelInstance;
	return modelInstance;
}

void Model::Draw(QPainter *pntr, QRectF geom)
{
	pntr->setPen(color_grid);
	pntr->fillRect(geom, QBrush(Qt::white));
	float cellW = geom.width() / (float)roomSize.first, cellH = geom.height() / (float)roomSize.second;
	pntr->drawRect(geom);
	for (int i = 1; i < roomSize.first; i++)
		pntr->drawLine(QPointF((float)i * geom.width() / (float)roomSize.first, 0.0), QPointF((float)i * geom.width() / (float)roomSize.first, geom.height()));
	for (int i = 1; i < roomSize.second; i++)
		pntr->drawLine(QPointF(0.0, (float)i * geom.height() / (float)roomSize.second), QPointF(geom.width(), (float)i * geom.height() / (float)roomSize.second));
	// точка входа
	pntr->setBrush(QBrush(color_entrance));
	pntr->drawEllipse(QPointF(entrance.x() * cellW + cellW / 2.0, entrance.y() * cellH + cellH / 2.0), 0.1 * cellW, 0.1 * cellH);
	// отрисовка объектов
	foreach (Entity *ent, entities) {
		ent->Draw(pntr, QRectF((float)ent->getCoord().x() * cellW, (float)ent->getCoord().y() * cellH, cellW, cellH));
	}
	// отрисовка людей
	foreach (Person *p, employees) {
		p->Draw(pntr, QRectF((float)p->getCoord().x() * cellW, (float)p->getCoord().y() * cellH, cellW, cellH));
	}
	foreach (Person *p, customers) {
		p->Draw(pntr, QRectF((float)p->getCoord().x() * cellW, (float)p->getCoord().y() * cellH, cellW, cellH));
	}
}

void Model::clickAtCoord(QPointF pos, QRectF geom)
{
	float cellW = geom.width() / (float)roomSize.first, cellH = geom.height() / (float)roomSize.second;
	clickCoord = QPointF(floor(pos.x() / cellW), floor(pos.y() / cellH));
	QPoint clickPoint = QPoint((int)clickCoord.x(), (int)clickCoord.y());
	if (isDesignMode)
	{
		switch (placementID)
		{
			case 1:
				{
					bool done = false;
					for (int i = 0; i < entities.size(); i++)
						if (entities.at(i)->getCoord() == clickPoint)
						{
							Entity *e = entities.at(i);
							for (int k = 0; k < countersShortcuts.size(); k++)
							{
								if (countersShortcuts[k] > i)
									countersShortcuts[k]--;
								else if (countersShortcuts[k] == i)
									countersShortcuts[k] = -1;
							}
							delete e;
							entities.removeAt(i);
							freeCells[clickPoint.y() * roomSize.first + clickPoint.x()] = true;
							done = true;
							break;
						}
					if (done) break;
					for (int i = 0; i < employees.size(); i++)
						if (employees.at(i)->getCoord() == clickPoint)
						{
							Person *e = employees.at(i);
							delete e;
							employees.removeAt(i);
							freeCells[clickPoint.y() * roomSize.first + clickPoint.x()] = true;
							break;
						}
					break;
				}
			case 2:
				{
					if (freeCells.at((int)clickCoord.y() * roomSize.first + (int)clickCoord.x()))
						entrance = clickPoint;
					break;
				}
			case 3:
				{
					if (freeCells.at((int)clickCoord.y() * roomSize.first + (int)clickCoord.x()))
					{
						Wall *e = new Wall(clickPoint);
						entities.push_back(e);
						freeCells[(int)clickCoord.y() * roomSize.first + (int)clickCoord.x()] = false;
					}
					break;
				}
			case 4:
				{
					if (freeCells.at(clickPoint.y() * roomSize.first + clickPoint.x()))
					{
						Table *e = new Table(clickPoint);
						entities.push_back(e);
						freeCells[clickPoint.y() * roomSize.first + clickPoint.x()] = false;
						e->setFreeSides(getCellState(e->getCoord() at_north), getCellState(e->getCoord() at_west), getCellState(e->getCoord() at_south), getCellState(e->getCoord() at_east));
					}
					break;
				}
			case 5:
				{
					if (freeCells.at((int)clickCoord.y() * roomSize.first + (int)clickCoord.x()))
					{
						Counter *e = new Counter(clickPoint, placementIDSub);
						entities.push_back(e);
						countersShortcuts[placementIDSub] = entities.size() - 1;
						freeCells[(int)clickCoord.y() * roomSize.first + (int)clickCoord.x()] = false;
					}
					break;
				}
			case 6:
				{
					if (freeCells.at((int)clickCoord.y() * roomSize.first + (int)clickCoord.x()))
					{
						Employee *p = new Employee(clickPoint, placementIDSub);
						employees.push_back(p);
						freeCells[(int)clickCoord.y() * roomSize.first + (int)clickCoord.x()] = false;
					}
					break;
				}
		}
	}
	emit message("Готово");
	emit needsRepaint();
}

void Model::setRoomSize(int width, int height)
{
	roomSize = QPair<int, int>(width, height);
	fillList(&freeCells, true, width * height);
}

void Model::setPlacementID(int id)
{
	placementID = id;
}

void Model::setPlacementIDSub(int id)
{
	placementIDSub = id;
}

void Model::setDesignMode(bool mode)
{
	isDesignMode = mode;
}

void Model::addCustomer(float pocketMoney)
{
	Customer *c = new Customer(entrance, pocketMoney);
	QThread *newthread = new QThread(c);
	c->moveToThread(newthread);
	threadPool.push_back(newthread);
	connect(c, SIGNAL(needsRepaint()), this, SLOT(onRepaintRequest()));
	connect(c, SIGNAL(moveMe()), this, SLOT(customerMovement()));
	connect(c, SIGNAL(readyToAct()), this, SLOT(customerAction()));
	connect(c, SIGNAL(pickDishToOrder()), this, SLOT(pickDish()));
	connect(c, SIGNAL(needTable()), this, SLOT(pickFreeTable()));
	connect(c, SIGNAL(deleteMe()), this, SLOT(deletePerson()));
	connect(newthread, SIGNAL(started()), c, SLOT(Act()));
	connect(c, SIGNAL(deleteMe()), newthread, SLOT(terminate()));
	connect(c, SIGNAL(message(QString)), this, SLOT(getMessage(QString)));
	customers.push_back(c);
	message("Вошел посетитель #" + QString::number(c->getId()) + " (денег: " + QString::number(c->getMoney()) + ")");
	emit needsRepaint();
	newthread->start(QThread::LowestPriority);
}

void Model::addCustomerGroup(float pocketMoney, int group)
{
		Customer *c = new Customer(entrance, group, pocketMoney);
		QThread *newthread = new QThread(c);
		c->moveToThread(newthread);
		threadPool.push_back(newthread);
		connect(c, SIGNAL(needsRepaint()), this, SLOT(onRepaintRequest()));
		connect(c, SIGNAL(moveMe()), this, SLOT(customerMovement()));
		connect(c, SIGNAL(readyToAct()), this, SLOT(customerAction()));
		connect(c, SIGNAL(pickDishToOrder()), this, SLOT(pickDish()));
		connect(c, SIGNAL(needTable()), this, SLOT(pickFreeTable()));
		connect(c, SIGNAL(deleteMe()), this, SLOT(deletePerson()));
		connect(newthread, SIGNAL(started()), c, SLOT(Act()));
		connect(c, SIGNAL(deleteMe()), newthread, SLOT(terminate()));
		connect(c, SIGNAL(message(QString)), this, SLOT(getMessage(QString)));
		customers.push_back(c);
		message("Вошел посетитель #" + QString::number(c->getId()) + " группы #" + QString::number(group) + " (денег: " + QString::number(c->getMoney()) + ")");
		emit needsRepaint();
		newthread->start();
}

void Model::onRepaintRequest()
{
	emit needsRepaint();
}

void Model::customerMovement()
{
	if (customers.indexOf(dynamic_cast<Person *>(sender())) == -1)
		return;
	Person *p = dynamic_cast<Person *>(sender());
	QPoint src = p->getCoord();
	switch (p->getActionStep())
	{
		case 0:
			{
				p->setPath(findPath(src, queuePath.first()));
				break;
			}
		case 2:
			{
				int queueNr = customerQueue.indexOf(p);
				QList<QPoint> path;
				if (queueNr >= 0)
				{
					if (queueNr >= queuePath.size())
						path = findPath(src, queuePath.first());
					else
						path = findPath(src, queuePath[queuePath.size() - 1 - queueNr]);
				}
				else
					p->setPath(QList<QPoint>());
				if (path.first() == point_fail)
					path = QList<QPoint>({src});
				p->setPath(path);
				break;
			}
		case 5:
			{
				Counter *ent = dynamic_cast<Counter *>(entities.at(countersShortcuts.at(2)));
				p->setPath(findPath(src, ent->getEntry(true)));
				break;
			}
		case 10:
			{
				p->setPath(findPath(src, entrance));
				break;
			}
	}
}

void Model::employeeMovement()
{
	if (QString(sender()->metaObject()->className()) != "Employee")
		return;
	Employee *empl = dynamic_cast<Employee *>(sender());
	QPoint src = empl->getCoord();
	switch (empl->getType())
	{
		case 1:
			{
				switch (empl->getActionStep())
				{
					case 0:
						{
							empl->setPath(findPath(src, dynamic_cast<Counter *>(entities.at(countersShortcuts.at(4)))->getEntry(false)));
							break;
						}
					case 1:
						{
							empl->setPath(findPath(src, dynamic_cast<Counter *>(entities.at(countersShortcuts.at(5)))->getEntry(false)));
							break;
						}
				}

				break;
			}
		case 2:
			{
				switch (empl->getActionStep())
				{
					case 0:
						{
							empl->setPath(findPath(src, dynamic_cast<Counter *>(entities.at(countersShortcuts.at(2)))->getEntry(false)));
							break;
						}
					case 1:
						{
							empl->setPath(findPath(src, dynamic_cast<Counter *>(entities.at(countersShortcuts.at(3)))->getEntry(false)));
							break;
						}
					case 2:
						{
							empl->setPath(findPath(src, dynamic_cast<Counter *>(entities.at(countersShortcuts.at(0)))->getEntry(false)));
							break;
						}
				}
				break;
			}
	}
}

QList<QPoint> Model::findPath(QPoint src, QPoint dest)
{
	QPoint a = src;
	QList<QPoint> openedList, closedList, parents;
	QList<QPoint> path;
	QList<int> f, g, h;
	fillList(&f, 0, roomSize.first * roomSize.second);
	fillList(&g, 0, roomSize.first * roomSize.second);
	fillList(&h, 0, roomSize.first * roomSize.second);
	for (int i = 0; i < roomSize.second; i++)
		for (int j = 0; j < roomSize.first; j++)
			parents.push_back(QPoint(j, i));
	openedList.push_back(a);
	f[a.y() * roomSize.first + a.x()] = h[a.y() * roomSize.first + a.x()] = (dest - src).manhattanLength();
	while(!openedList.isEmpty())
	{
		a = openedList.front();
		int fMin = f[openedList.front().y() * roomSize.first + openedList.front().y()];
		for (int i = 1; i < openedList.size(); i++)
			if (f[openedList.front().y() * roomSize.first + openedList.front().y()] < fMin)
			{
				a = openedList[i];
				fMin = f[openedList.front().y() * roomSize.first + openedList.front().y()];
			}
		closedList.push_back(a);
		openedList.removeAt(openedList.indexOf(a));
		QList<QPoint> neighbors = findFreeNeighbors(a);
		foreach (QPoint neighbor, neighbors) {
			if (closedList.indexOf(neighbor) == -1)
			{
				if (openedList.indexOf(neighbor) == -1)
				{
					openedList.push_back(neighbor);
					g[neighbor.x() + neighbor.y() * roomSize.first] = g[a.x() + roomSize.first * a.y()] + 1;
					h[neighbor.x() + neighbor.y() * roomSize.first] = (dest - neighbor).manhattanLength();
					f[neighbor.x() + neighbor.y() * roomSize.first] = g[neighbor.x() + neighbor.y() * roomSize.first] + h[neighbor.x() + neighbor.y() * roomSize.first];
					parents[neighbor.x() + neighbor.y() * roomSize.first] = a;
					if (neighbor == dest)
					{
						QPoint currPoint = neighbor;
						while (currPoint != src)
						{
							path.push_front(currPoint);
							currPoint = parents[currPoint.x() + roomSize.first * currPoint.y()];
						}
						return path;
					}
				}
				else
				{
					if ((g[a.x() + roomSize.first * a.y()] + 1) < g[neighbor.x() + neighbor.y() * roomSize.first])
						{
							g[neighbor.x() + neighbor.y() * roomSize.first] = g[a.x() + roomSize.first * a.y()] + 1;
							f[neighbor.x() + neighbor.y() * roomSize.first] = g[neighbor.x() + neighbor.y() * roomSize.first] + h[neighbor.x() + neighbor.y() * roomSize.first];
							parents[neighbor.x() + neighbor.y() * roomSize.first] = a;
						}
				}
			}
		}
	}
	QList<QPoint> failPath;
	failPath.push_back(point_fail);
	return failPath;
}

QList<QPoint> Model::findFreeNeighbors(QPoint src)
{
	QList<QPoint> neighbors;
	for (int i = src.y() - (src.y() > 0 ? 1 : 0); i <= src.y() + (src.y() < roomSize.second - 1 ? 1 : 0); i++)
		for (int j = src.x() - (src.x() > 0 ? 1 : 0); j <= src.x() + (src.x() < roomSize.first - 1 ? 1 : 0); j++)
			if (freeCells.at(i * roomSize.first + j) && QPoint(j, i) != src)
				neighbors.push_back(QPoint(j, i));
	return neighbors;
}

QPoint Model::findEntryPoint(QPoint src, QPoint dest)
{
	QList<QPoint> pointsToCheck({dest at_north, dest at_west, dest at_south, dest at_east});
	for (int i = 0; i < pointsToCheck.size(); i++)
	{
		if (getCellState(pointsToCheck[i]))
		{
			if (findPath(src, pointsToCheck[i]).first() != point_fail || src == pointsToCheck[i])
				return pointsToCheck[i];
		}
	}
	return point_fail;
}

int Model::getTablesCount()
{
	int cnt = 0;
	foreach (Entity *ent, entities)
	{
		if (QString(ent->metaObject()->className()) == "Table")
			cnt++;
	}
	return cnt;
}

void Model::pickDish()
{
	if (customers.indexOf(dynamic_cast<Person *>(sender())) == -1)
		return;
	Customer *c = dynamic_cast<Customer *>(sender());
	float money = c->getMoney();
	QList<Dish *> affordableDishes;
	for (int i = 0; i < dishesAvailable.size(); i++)
		if (dishesAvailable.at(i)->getPrice() <= money && dishesAvailable.at(i)->getQuantity() > 0)
			affordableDishes.push_back(dishesAvailable.at(i));
	if (affordableDishes.size() == 0)
	{
		message("Посетитель #" + QString::number(c->getId()) + " не может позволить себе ничего и решил уйти.");
		c->setActionStep(10);
		return;
	}
	QList<int> popularityWeights;
	for (int i = 0; i < affordableDishes.size(); i++)
		popularityWeights.push_back(affordableDishes.at(i)->getPopularity());
	c->setDish(affordableDishes.at(getRandomWeighted(popularityWeights)));
}

void Model::pickFreeTable()
{
	if (customers.indexOf(dynamic_cast<Person *>(sender())) == -1)
		return;
	Person *p = dynamic_cast<Person *>(sender());
	QList<Table *> tableList;
	Table *tbl = NULL;
	for (int i = 0; i < entities.size(); i++)
	{
		if (QString(entities.at(i)->metaObject()->className()) == "Table")
		{
			if (dynamic_cast<Table *>(entities.at(i))->getOccupiedState() == 0)
			{
				tableList.push_back(dynamic_cast<Table *>(entities.at(i)));
			}
		}
	}
	if (tableList.size() > 0)
		tbl = tableList[qrand()%tableList.size()];
	tableList.clear();
	// полностью свободные столы не найдены? ищем, к кому можно подсесть...
	if (tbl == NULL)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			if (QString(entities.at(i)->metaObject()->className()) == "Table")
			{
				if (dynamic_cast<Table *>(entities.at(i))->getOccupiedState() == 1)
				{
					tableList.push_back(dynamic_cast<Table *>(entities.at(i)));
				}
			}
		}
		if (tableList.size() > 0)
			tbl = tableList[qrand()%tableList.size()];
		tableList.clear();
	}
	// стол найден
	if (tbl != NULL && tbl->getOccupiedState() != 2)
	{
		QPoint src = p->getCoord();
		QPoint dest = tbl->getFreeSide();
		QList<QPoint> path = findPath(src, dest);
		dynamic_cast<Customer *>(p)->occupyTable(tbl);
		tbl->setSideOccupied(tbl->determineSide(dest), true);
		p->setPath(path);
		message("Посетитель #" + QString::number(p->getId()) + " нашел стол.");
	}
	else
	{
		// если нет, будем ходить, пока не найдется
		QPoint src = p->getCoord();
		QPoint dest;
		QList<QPoint> path;
		do
		{
			dest = QPoint(qrand()%roomSize.first, qrand()%roomSize.second);
			path = findPath(src, dest);
		} while (path.first() == point_fail);
		message("Посетитель #" + QString::number(p->getId()) + " не нашел стола и будет ходить по помещению.");
		p->setPath(path);
	}
}

void Model::customerAction()
{
	if (customers.indexOf(dynamic_cast<Person *>(sender())) == -1)
		return;
	Customer *c = dynamic_cast<Customer *>(sender());
	switch (c->getActionStep())
	{
		case 1:
			{
				c->interactWith(dynamic_cast<Counter *>(entities.at(countersShortcuts.at(0))));
				break;
			}
		case 2:
			{
				if (c->isServed())
					break;
				if (customerQueue.indexOf(c) == -1)
					customerQueue.push_back(c);
				else
				{
					if (c == customerQueue.first())
						if (c->getCoord() == queuePath.last())
							for (int i = 0; i < employees.size(); i++)
								if (dynamic_cast<Employee *>(employees.at(i))->getType() == 0)
								{
									dynamic_cast<Employee *>(employees.at(i))->interactWith(c);
									break;
								}
				}
				break;
			}
		case 5:
			{
				c->interactWith(dynamic_cast<Counter *>(entities.at(countersShortcuts.at(2))));
				break;
			}
		default:
			break;
	}
}

void Model::employeeAction()
{
	if (QString(sender()->metaObject()->className()) != "Employee")
		return;
	Employee *empl = dynamic_cast<Employee *>(sender());
	switch (empl->getType())
	{
		case 0:
			{
				customerQueue.pop_front();
				break;
			}
		case 1:
			{
				switch (empl->getActionStep())
				{
					case 0:
						{
							QList<Dish *> dishesToCook;
							foreach (Dish *dish, dishesAvailable) {
								if (dish->getQuantity() == 0)
									dishesToCook.push_back(dish);
							}
							empl->setDishList(dishesToCook);
							break;
						}
				}
				break;
			}
		case 2:
			{
				switch (empl->getActionStep()) {
					case 0:
						{
							Counter *cntr = dynamic_cast<Counter *>(entities.at(countersShortcuts.at(2)));
							if (!cntr->isEmpty())
								empl->interactWith(cntr);
							break;
						}
					case 2:
						{
							empl->interactWith(dynamic_cast<Counter *>(entities.at(countersShortcuts.at(0))));
							break;
						}
				}
				break;
			}
	}
}

void Model::deletePerson()
{
	if (customers.indexOf(dynamic_cast<Person *>(sender())) == -1)
		return;
	Person *p = dynamic_cast<Person *>(sender());
	if (customers.indexOf(p) != -1)
	{
		message("Посетитель #" + QString::number(p->getId()) + " ушел");
		QThread *newthread = threadPool.takeAt(threadPool.indexOf(p->thread()));
		newthread->deleteLater();
		customers.removeAt(customers.indexOf(p));
		p->deleteLater();
	}
	emit needsRepaint();
}

bool Model::getCellState(QPoint cell)
{
	if (cell.x() >= 0 && cell.x() < roomSize.first && cell.y() >= 0 && cell.y() < roomSize.second)
		return freeCells[cell.x() + cell.y() * roomSize.first];
	else
		return false;
}

void Model::setEmployeeCellsState(bool state)
{
	foreach (Person *e, employees) {
		freeCells[e->getCoord().x() + e->getCoord().y() * roomSize.first] = state;
	}
}

bool Model::verifyPaths()
{
	setEmployeeCellsState(true);
	message("Проверка доступности столов...");
	QPair<QPoint, QPoint> queuePathEdges;
	foreach (Entity *ent, entities) {
		if (QString(ent->metaObject()->className()) == "Table")
		{
			QList<bool> freesides({false, false, false, false});
			QPoint coord = ent->getCoord();
			QList<QPoint> sides({coord at_north, coord at_west, coord at_south, coord at_east});
			for (int i = 0; i < sides.size(); i++)
			{
				freesides[i] = (getCellState(sides[i]) && (findPath(entrance, sides[i]).first() != point_fail));
			}
			dynamic_cast<Table *>(ent)->setFreeSides(freesides[0], freesides[1], freesides[2], freesides[3]);
			if (findPath(entrance, dynamic_cast<Table *>(ent)->getFreeSide()).first() == point_fail)
				return false;
		}
	}
	for (int i = 0; i < countersShortcuts.size(); i++)
	{
		if (countersShortcuts[i] != -1)
		{
			Entity *ent = entities[countersShortcuts[i]];
			if (i >= 0 && i <= 2)
			{
				QPoint entry = findEntryPoint(entrance, ent->getCoord());
				if (entry == point_fail)
					return false;
				dynamic_cast<Counter *>(ent)->setEntry(entry, true);
				if (dynamic_cast<Counter *>(ent)->getType() == 0)
					queuePathEdges.first = entry;
				else if (dynamic_cast<Counter *>(ent)->getType() == 1)
					queuePathEdges.second = entry;
			}
			foreach (Person *p, employees)
			{
				QPoint entry = findEntryPoint(p->getCoord(), ent->getCoord());
				if (entry != point_fail)
					dynamic_cast<Counter *>(ent)->setEntry(entry, false);
				else
					return false;
			}
		}
		else
			return false;
	}
	setEmployeeCellsState(false);
	queuePath = findPath(queuePathEdges.first, queuePathEdges.second);
	queuePath.push_front(queuePathEdges.first);
	message("Ошибок не найдено");
	return true;
}

void Model::resetModel(bool fullReset)
{
	while (threadPool.size() > 0) {
		QThread *newthread = threadPool.takeAt(0);
		newthread->terminate();
		newthread->quit();
		newthread->deleteLater();
	}
	while (employees.size() > 0)
	{
		Person *p = employees.takeAt(0);
		p->setActionStep(-1);
		Counter *nptr = NULL;
		p->interactWith(nptr);
		p->thread()->quit();
		p->deleteLater();
	}
	while (customers.size() > 0)
	{
		Person *p = customers.takeAt(0);
		p->setActionStep(-1);
		Counter *nptr = NULL;
		p->interactWith(nptr);
		p->thread()->quit();
		p->deleteLater();
	}
	customerQueue.clear();
	while (entities.size() > 0)
	{
		Entity *e = entities.takeAt(0);
		if (QString(e->metaObject()->className()) == "Counter")
			dynamic_cast<Counter *>(e)->destroy();
		e->deleteLater();
	}
	countersShortcuts = QList<int>({-1, -1, -1, -1, -1, -1});
	while (dishesAvailable.size() > 0)
	{
		Dish *d = dishesAvailable.takeAt(0);
		d->deleteLater();
	}
	fillList(&freeCells, true, freeCells.size());
	if (fullReset)
	{
		placementID = 0;
		placementIDSub = 0;
	}
}

bool Model::readFromStream(QDataStream &inp)
{
	int q;
	QList<Entity *> _entities;
	QList<Person *> _employees;
	QList<Dish *> _dishes;
	QPair<int, int> _roomSize;
	QPoint _entrance;
	QList<int> _shortcuts = QList<int>({-1, -1, -1, -1, -1, -1});
	try
	{
		inp >> _roomSize;
		inp >> q;
		for (int i = 0; i < q; i++)
		{
			int t;
			inp >> t;
			QPoint coord;
			inp >> coord;
			switch (t)
			{
				case 0:
					{
						_entities.push_back(new Wall(coord));
						break;
					}
				case 1:
					{
						_entities.push_back(new Table(coord));
						break;
					}
				case 2:
					{
						QPoint emplCoord, custCoord;
						int type;
						inp >> type;
						inp >> emplCoord;
						inp >> custCoord;
						Counter *c = new Counter(coord, type);
						c->setEntry(emplCoord, false);
						c->setEntry(custCoord, true);
						_entities.push_back(c);
						_shortcuts[type] = _entities.indexOf(c);
					}
			}
		}
		inp >> q;
		for (int i = 0; i < q; i++)
		{
			QPoint coord;
			int role;
			inp >> coord;
			inp >> role;
			_employees.push_back(new Employee(coord, role));
		}
		inp >> q;
		for (int i = 0; i < q; i++)
		{
			QString _name;
			int _quantity, _popularity;
			float _price;
			inp >> _name;
			inp >> _price;
			inp >> _quantity;
			inp >> _popularity;
			QList<bool> _reqUtensils;
			bool _req;
			for (int i = 0; i < 3; i++)
			{
				inp >> _req;
				_reqUtensils.push_back(_req);
			}
			_dishes.push_back(new Dish(_name, _price, _quantity, _popularity, _reqUtensils));
		}
		inp >> _entrance;
	}
	catch(...)
	{
		return false;
	}
	this->resetModel(false);
	roomSize = _roomSize;
	entities = _entities;
	employees = _employees;
	dishesAvailable = _dishes;
	countersShortcuts = _shortcuts;
	fillList(&freeCells, true, roomSize.first * roomSize.second);
	for (int i = 0; i < entities.size(); i++)
	{
		freeCells[entities.at(i)->getCoord().x() + entities.at(i)->getCoord().y() * roomSize.first] = false;
	}
	entrance = _entrance;
	emit message("Данные загружены");
	return true;
}

bool Model::writeToStream(QDataStream &outp)
{
	try
	{
		outp << roomSize;
		outp << entities.size();
		for (int i = 0; i < entities.size(); i++)
		{
			QString cName(entities.at(i)->metaObject()->className());
			if (cName == "Wall")
			{
				outp << 0;
				outp << entities.at(i)->getCoord();
			}
			else if (cName == "Table")
			{
				outp << 1;
				outp << entities.at(i)->getCoord();
			}
			else if (cName == "Counter")
			{
				outp << 2;
				Counter *c = dynamic_cast<Counter *>(entities.at(i));
				outp << entities.at(i)->getCoord();
				outp << c->getType();
				outp << c->getEntry(false);
				outp << c->getEntry(true);
			}
		}
		outp << employees.size();
		for (int i = 0; i < employees.size(); i++)
		{
			outp << employees.at(i)->getCoord();
			outp << dynamic_cast<Employee *>(employees.at(i))->getType();
		}
		outp << dishesAvailable.size();
		for (int i = 0; i < dishesAvailable.size(); i++)
		{
			Dish *d = dishesAvailable.at(i);
			outp << d->getName();
			outp << d->getPrice();
			outp << d->getQuantity();
			outp << d->getPopularity();
			for (int i = 0; i < d->getReqUtensils().size(); i++)
				outp << d->getReqUtensils().at(i);
		}
		outp << entrance;
	}
	catch(...)
	{
		return false;
	}
	emit message("Данные сохранены");
	return true;
}

void Model::addDish(Dish *dish)
{
	dishesAvailable.push_back(dish);
}

Dish * Model::getDish(int id)
{
	if (id < 0 || id >= dishesAvailable.size())
		return NULL;
	return (dishesAvailable.at(id));
}

void Model::deleteDish(int id)
{
	if (id < 0 || id >= dishesAvailable.size())
		return;
	Dish *dish = dishesAvailable.takeAt(id);
	delete dish;
}

void Model::putItems(int trays, int towels, int forks, int spoons, int knives)
{
			Counter *c = dynamic_cast<Counter *>(entities[countersShortcuts[0]]);
				for (int i = 0; i < trays; i++)
				{
					c->putItem(new Item("Tray"));
					c->putItem(new Plate());
				}
				for (int i = 0; i < towels; i++)
					c->putItem(new Item("Towel"));
				for (int i = 0; i < forks; i++)
					c->putItem(new Item("Fork"));
				for (int i = 0; i < spoons; i++)
					c->putItem(new Item("Spoon"));
				for (int i = 0; i < knives; i++)
					c->putItem(new Item("Knife"));
				message("Посуда разложена...");
}

void Model::activateEmployees()
{
	foreach (Person *p, employees) {
		QThread *thread = new QThread(p);
		connect(p, SIGNAL(moveMe()), this, SLOT(employeeMovement()));
		connect(p, SIGNAL(readyToAct()), this, SLOT(employeeAction()));
		connect(thread, SIGNAL(started()), p, SLOT(Act()));
		connect(p, SIGNAL(deleteMe()), thread, SLOT(terminate()));
		connect(p, SIGNAL(message(QString)), this, SLOT(getMessage(QString)));
		p->moveToThread(thread);
		threadPool.push_back(thread);
		thread->start(QThread::LowestPriority);
	}
}

void Model::getMessage(QString msg)
{
	// перенаправляем сообщение от объекта
	message(msg);
}
/*
void Model::cookDishes()
{
	needToCookMore = true;
}
*/
