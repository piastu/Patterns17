#ifndef DEFS_H
#define DEFS_H

#define CARD_POOL_SIZE 200

#include <QList>
#include <QString>
#include <QThread>
#include <QImage>
#include <QPainter>
#include <QColor>
#include <QMap>
#include <QFile>
#include <QStringList>
#include <QDataStream>
#include "randomizer.h"

struct listItem
{
		QImage drawable;
		QString pseudoDrawable;
		QString name, uid;
		listItem()
		{

		}
		listItem(QImage _drawable, QString _name, QString _uid)
		{
			drawable = _drawable;
			name = _name;
			uid = _uid;
		}
		listItem(QImage _drawable, QString _pDrawable, QString _name, QString _uid)
		{
			drawable = _drawable;
			pseudoDrawable = _pDrawable;
			name = _name;
			uid = _uid;
		}
};

struct effectInfoItem
{
		QString info;
		bool canAffectEnemy, canAffectPlayer;
		int effectType;
		effectInfoItem()
		{

		}
		effectInfoItem(QString _info, bool affectEnemy, bool affectPlayer, int _type)
		{
			info = _info;
			canAffectEnemy = affectEnemy;
			canAffectPlayer = affectPlayer;
			effectType = _type;
		}
};


#endif // DEFS_H
