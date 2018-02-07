#include "transitionfactory.h"

TransitionFactory::TransitionFactory()
{
	int sizeint = transAvailable.size();
	for (int i = 0; i < sizeint; i++)
	{
		transReady[transAvailable[i].name] = nullptr;
	}
}

Transition *TransitionFactory::getTransition(wstring name)
{
	if (transReady[name] == nullptr)
	{
		if (name == L"fade")
			transReady[name] = new TransitionFade();
	}
	return transReady[name];
}

vector<EntryDisp> TransitionFactory::getAvailableTransitions()
{
	return transAvailable;
}
