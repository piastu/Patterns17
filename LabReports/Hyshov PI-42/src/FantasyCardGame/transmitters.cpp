#include "transmitters.h"

StatsTransmitter::StatsTransmitter(QObject *parent) : QObject(parent)
{

}

void StatsTransmitter::setStat(QString statName, int statVal, bool isInc)
{
	emit sendStat(statName, statVal, isInc);
}

InfoTransmitter::InfoTransmitter(QObject *parent) : QObject(parent)
{

}

void InfoTransmitter::receiveMsg(QString msg)
{
	sendMsg(msg);
}
