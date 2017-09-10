#include "dish.h"

Dish::Dish(QString _name, float _price, int _quantity, int _popularity, QList<bool> _reqUtensils, QObject *parent):QObject(parent)
{
	name = _name;
	price = _price;
	quantity = quantityToCook = _quantity;
	popularity = _popularity;
	requiredUtensils = _reqUtensils;
}

void Dish::cook()
{
	quantity++;
}

float Dish::getPrice()
{
	return price;
}

int Dish::getQuantity()
{
	return quantity;
}

int Dish::getQuantityToCook()
{
	return quantityToCook;
}

int Dish::getPopularity()
{
	return popularity;
}

QString Dish::getName()
{
	return name;
}

QList<bool> Dish::getReqUtensils()
{
	return requiredUtensils;
}

void Dish::replaceData(QString _name, float _price, int _quantity, int _popularity, QList<bool> _reqUtensils)
{
	name = _name;
	price = _price;
	quantity = quantityToCook = _quantity;
	popularity = _popularity;
	requiredUtensils = _reqUtensils;
}

bool Dish::take()
{
	if (quantity > 0)
	{
		quantity--;
		if (quantity == 0)
			emit needToCookMore();
		return true;
	}
	else
	{
		emit needToCookMore();
		return false;
	}
}
