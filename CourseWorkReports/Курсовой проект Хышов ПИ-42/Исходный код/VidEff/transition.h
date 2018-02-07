#ifndef TRANSITION_H
#define TRANSITION_H

#include "string"
#include "frame.h"
#include "util.h"

using namespace std;

const vector<EntryDisp> transAvailable =
		vector<EntryDisp>({
							  EntryDisp(L"fade", L"Fade")
						  });

class Transition
{
	public:
		Transition();
		virtual wstring getName() = 0;
		virtual wstring getDisplayName() = 0;
		virtual Frame * use(Frame *inpA, Frame *inpB, float pos) = 0;
};

class TransitionFade : public Transition
{
	private:
	public:
		TransitionFade();
		wstring getName();
		wstring getDisplayName();
		Frame * use(Frame *inpA, Frame *inpB, float pos);
};

#endif // TRANSITION_H
