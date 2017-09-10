#ifndef DISH_H
#define DISH_H

#include <QDataStream>
#include <QObject>
#include <util.h>

// блюдо (не тарелка, а элемент меню)
class Dish : public QObject
{
	Q_OBJECT
	private:
		QString name;	// название
		float price;	// цена
		int quantity, quantityToCook;	// количество (и какой партией готовить)
		int popularity; // популярность
		QList<bool> requiredUtensils;  // требуемые приборы
	public:
		Dish(QString _name, float _price, int _quantity, int _popularity, QList<bool> _reqUtensils, QObject *parent = 0);
		// методы получения свойств
		float getPrice();
		int getQuantity();
		int getQuantityToCook();
		int getPopularity();
		QString getName();
		QList<bool> getReqUtensils();
		// замена данных
		void replaceData(QString _name, float _price, int _quantity, int _popularity, QList<bool> _reqUtensils);
		bool take();  // взять
	signals:
		needToCookMore();
	public slots:
		void cook();  // приготовить
};

#endif // DISH_H
