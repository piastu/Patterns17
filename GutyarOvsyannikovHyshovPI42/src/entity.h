#ifndef ENTITY_H
#define ENTITY_H

#include <QBitArray>
#include <QObject>
#include <QPainter>
#include <item.h>
#include <util.h>
#include <iostream>

using namespace std;

#define color_wall QColor(40, 40, 40)
#define color_table QColor(128, 64, 0)
#define color_counter QColor(239, 228, 176)

// Класс "сущности"
// Сюда входят различные предметы, например, мебель.
class Entity : public QObject
{
	Q_OBJECT
	protected:
		QPoint coord;  // координата
	public:
		explicit Entity(QPoint startCoord, QObject *parent = 0);
		virtual void Draw(QPainter *pntr, QRectF geom);  // отрисовка
		QPoint getCoord();  // получение координаты
	signals:
	public slots:
};

// стена
// с ней ничего нельзя сделать, равно как и просто пройти сквозь нее
class Wall : public Entity
{
	Q_OBJECT
	protected:
	public:
		explicit Wall(QPoint startCoord, QObject *parent = 0);
		virtual void Draw(QPainter *pntr, QRectF geom);
	signals:
	public slots:
};

// стол
// за него садятся посетители, едят и уходят
class Table : public Entity
{
	Q_OBJECT
	protected:
		QBitArray freeSides, occupiedSides;  // свободные стороны
	public:
		explicit Table(QPoint startCoord, QObject *parent = 0);
		virtual void Draw(QPainter *pntr, QRectF geom);
		int getOccupiedState();
		void setFreeSides(bool north, bool west, bool south, bool east);  // обновление свободных сторон
		QPoint getFreeSide();  // получение координаты свободной стороны
		bool isSideFree(int side);  // проверка, свободна ли такая сторона
		int determineSide(QPoint point);  // определение стороны
		void setSideOccupied(int side, bool state);  // занять сторону
	signals:
	public slots:
};

// рабочая поверхность
// с ними работает персонал (а с некоторыми - и посетители)
class Counter : public Entity
{
	Q_OBJECT
	protected:
		int type;  // тип
		QPoint employeeEntry, customerEntry;  // координата, куда подходить персоналу/посетителям
		QList<Item *> inventory;  // инвентарь
		bool locked;
	public:
		explicit Counter(QPoint startCoord, int _type, QObject *parent = 0);
		virtual void Draw(QPainter *pntr, QRectF geom);
		void setEntry(QPoint point, bool forCustomers);  // установка точки входа
		QPoint getEntry(bool forCustomers);  // и ее получение
		int getType();  // получение типа
		QList<Item *> takeAllItems();  // взять все вещи
		Item * takeSingleItem(QString id);  // взять одну конкретную вещь
		void putItem(Item *item);  // положить вещь
		bool isEmpty();
		bool isLocked();
		void setLocked(bool lock);
		void destroy();
	signals:
	public slots:
};

#endif // ENTITY_H
