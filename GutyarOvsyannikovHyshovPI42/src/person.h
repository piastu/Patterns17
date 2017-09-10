#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QThread>
#include <entity.h>
#include <item.h>
#include <util.h>
#include <dish.h>

#define color_cashier QColor(255, 242, 0)
#define color_cashier_cap QColor(34, 177, 76)
#define color_cook QColor(195, 195, 195)
#define color_cook_cap QColor(255, 255, 255)
#define color_dishwasher QColor(0, 162, 232)
#define color_dishwasher_cap QColor(255, 255, 255)

// класс человека
class Person : public QObject
{
		Q_OBJECT
	public:
		explicit Person(QPoint startCoord, QObject *parent = 0);
		virtual void Draw(QPainter *pntr, QRectF geom);		// отрисовка
		QPoint getCoord();		// получить координату
		void setPath(QList<QPoint> path);		// установить путь
		void moveByPath(QList<QPoint> path);	// переместить по пути
		void giveItem(Item *item);		// дать вещь
		void giveItem(QList<Item *> items);		// дать вещи
		void interactWith(Person *otherPerson);		// связь с другим человеком
		void interactWith(Counter *counter);		// связь с контейнером
		int getActionStep();		// получить шаг
		void setActionStep(int step);		// задать шаг
		int getId();		// получить ID
	protected:
		QPoint coord;		// координата
		QList<QPoint> currPath;		// текущий путь
		int actionStep;		// шаг действий
		QList<Item *> inventory;		// инвентарь
		Person *personToInteract;		// связь с другим человеком
		Counter *counterToInteract;		// связь с контейнером
		int id;		// ID
	signals:
		void needsRepaint();
		void moveMe();
		void readyToAct();
		void deleteMe();
		void message(QString);
	public slots:
		virtual void Act();		// деятельность
};

// покупатель
class Customer : public Person
{
		Q_OBJECT
	public:
		explicit Customer(QPoint startCoord, float pocketMoney, QObject *parent = 0);
		explicit Customer(QPoint startCoord, int groupID, float pocketMoney, QObject *parent = 0);
		virtual void Draw(QPainter *pntr, QRectF geom);  // отрисовка
		void occupyTable(Table *tbl);		// занять стол
		void setDish(Dish *dish);		// задать блюдо
		float getMoney();		// узнать сумму денег
		void takeMoney(float sum);		// взять деньги
		void serve();		// обслужить
		bool isServed();	// обслужен ли
	protected:
		float money;		// деньги
		int groupid;		// ID группы
		QColor drawColor;	// цвет для отрисовки
		Table *tableToOccupy;	// занятый стол
		Dish *dishToOrder;	// блюдо для заказа
		bool served;		// обслужен ли
	signals:
		void needTable();
		void pickDishToOrder();
		void goneAway();
	public slots:
		virtual void Act();
};

// персонал
class Employee : public Person
{
		Q_OBJECT
	public:
		explicit Employee(QPoint startCoord, int type, QObject *parent = 0);
		virtual void Draw(QPainter *pntr, QRectF geom);
		int getType();		// получить тип
		void setDishList(QList<Dish *> lst);		// передать список блюд
	protected:
		int role;		// роль
		QList<Dish *> dishes;		// список блюд
		QPair<QColor, QColor> getDrawColor();		// цвета для отрисовки
	signals:
	public slots:
		virtual void Act();
};

#endif // PERSON_H
