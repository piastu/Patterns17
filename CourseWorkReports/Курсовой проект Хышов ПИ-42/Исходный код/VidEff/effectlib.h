#ifndef EFFECTLIB_H
#define EFFECTLIB_H

#include "filter.h"
#include "filterfactory.h"
#include "transition.h"
#include "transitionfactory.h"

class EffectLib
{
	private:
		EffectLib();
		static EffectLib *instance;
		FilterFactory *fltFact;
		TransitionFactory *transFact;
	public:
		static EffectLib * getInstance();
		void reset();
		vector<EntryDisp> getAvailableFilters();
		vector<EntryDisp> getAvailableTransitions();
		Filter * getFilter(wstring name);
		Transition * getTransition(wstring name);
		vector<PropertyInfo> getFilterPropsInfo(wstring name);
};

#endif // EFFECTLIB_H
