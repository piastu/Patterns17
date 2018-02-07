#ifndef TRANSITIONFACTORY_H
#define TRANSITIONFACTORY_H

#include "defs.h"
#include "transition.h"

class TransitionFactory
{
	private:
		map<wstring, Transition *> transReady;
	public:
		TransitionFactory();
		Transition * getTransition(wstring name);
		vector<EntryDisp> getAvailableTransitions();
};

#endif // TRANSITIONFACTORY_H
