#include "effectlib.h"

EffectLib * EffectLib::instance = nullptr;

EffectLib::EffectLib()
{
	fltFact = new FilterFactory();
	transFact = new TransitionFactory();
}

EffectLib *EffectLib::getInstance()
{
	if (instance == nullptr)
		instance = new EffectLib();
	return instance;
}

void EffectLib::reset()
{

}

vector<EntryDisp> EffectLib::getAvailableFilters()
{
	return fltFact->getAvailableFilters();
}

vector<EntryDisp> EffectLib::getAvailableTransitions()
{
	return transFact->getAvailableTransitions();
}

Filter *EffectLib::getFilter(wstring name)
{
	return fltFact->getFilter(name);
}

Transition *EffectLib::getTransition(wstring name)
{
	return transFact->getTransition(name);
}

vector<PropertyInfo> EffectLib::getFilterPropsInfo(wstring name)
{
	return fltFact->getFilterPropsInfo(name);
}
