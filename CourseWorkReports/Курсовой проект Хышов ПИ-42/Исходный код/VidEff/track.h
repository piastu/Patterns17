#ifndef TRACK_H
#define TRACK_H

#include "defs.h"
#include "clip.h"

using namespace std;

struct ClipInfo
{
		int uid, frames, ctype;
};

struct ClipEntry
{
		Clip *clip;
		int offsetFrame;
		ClipEntry()
		{
			clip = nullptr;
			offsetFrame = 0;
		}
		ClipEntry(Clip *clip, int offsetFrame)
		{
			this->clip = clip;
			this->offsetFrame = offsetFrame;
		}
};

class Track
{
	private:
		vector<ClipEntry> clips;
	public:
		Track();
		~Track();
		Frame * getFrame(int pos);
		void addClip(Clip *clip, int offset);
		vector<ClipEntry> getClips();
		int getClipNum();
		ClipEntry getClip(int id);
		int getLength();
		void removeClip(int id);
		void makeTransition(int id_A, int id_B, wstring transName, int frames);
		void deleteClipsWith(ClipSource *src);
		vector<ClipInfo> getClipsInfo();
		bool isEmptyAt(int pos);
		void addFilter(int id, wstring fltName);
		void removeFilter(int id, int fltId);
		vector<FilterEntry> getUsedFilters(int id);
};

#endif // TRACK_H
