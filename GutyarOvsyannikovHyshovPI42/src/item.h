#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <dish.h>

// вещь
class Item : public QObject
{
	Q_OBJECT
	public:
		explicit Item(QObject *parent = 0);
		explicit Item(QString _id, QObject *parent = 0);
		virtual void Use();  // использовать
		QString getID();
		void prepare();  // подготовить к новому исп-ю
		bool isDisposeRequired();  // полностью ли исп-но
	protected:
		float status;  // состояние
		QString id;  // ID/Название
		bool clean;  // чистота
	signals:
		void isUsed();
		void isFinal();
	public slots:
};

class Plate : public Item
{
		Q_OBJECT
	public:
		explicit Plate(QObject *parent = 0);
		virtual void Use();
		void fillWith(Dish *dish);  // наложить блюдо
	protected:
		QString dishName; // какое блюдо лежит
	signals:
	public slots:
};

#endif // ITEM_H
