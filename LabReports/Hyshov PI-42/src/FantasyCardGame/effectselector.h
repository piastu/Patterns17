#ifndef EFFECTSELECTOR_H
#define EFFECTSELECTOR_H

#include <QObject>
#include "defs.h"
#include "effect.h"

// интерфейс "выборщика" действий
class IEffectSelector : public QObject
{
		Q_OBJECT
	public:
		explicit IEffectSelector(QObject *parent = 0);
		virtual QList<IEffect *> selectEffect(QList<IEffect *> effs) = 0;
		virtual int getType() = 0;
};

// берет одно случайное действие
class EffectSelectorRandom : public IEffectSelector
{
		Q_OBJECT
	public:
		explicit EffectSelectorRandom(QObject *parent = 0);
		QList<IEffect *> selectEffect(QList<IEffect *> effs);
		int getType();
};

// берет все и перемешивает их
class EffectSelectorAll : public IEffectSelector
{
		Q_OBJECT
	public:
		explicit EffectSelectorAll(QObject *parent = 0);
		QList<IEffect *> selectEffect(QList<IEffect *> effs);
		int getType();
};

#endif // EFFECTSELECTOR_H
