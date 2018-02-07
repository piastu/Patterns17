#ifndef TRANSMITTERS_H
#define TRANSMITTERS_H

#include <QObject>
#include "defs.h"

// "одноразовый" переходник
// призван спасти код от циклической зависимости
// передает карте параметры
class StatsTransmitter : public QObject
{
		Q_OBJECT
	public:
		explicit StatsTransmitter(QObject *parent = 0);
	signals:
		void sendStat(QString statName, int statVal, bool isInc);
	public slots:
		void setStat(QString statName, int statVal, bool isInc);

};

// передатчик сообщений
// полезен для сбора "логов"
class InfoTransmitter : public QObject
{
		Q_OBJECT
	public:
		explicit InfoTransmitter(QObject *parent = 0);
	signals:
		void sendMsg(QString msg);
	public slots:
		void receiveMsg(QString msg);
};

#endif // STATSTRANSMITTER_H
