#pragma once
#ifndef ICARDPROXY_H
#define ICARDPROXY_H

#include "defs.h"
#include "card.h"

class ICardProxy : public QObject
{
	Q_OBJECT
	private:
		ICard *destinaton;
	public:
		ICardProxy(QObject *parent = 0);
};

#endif // ICARDPROXY_H
