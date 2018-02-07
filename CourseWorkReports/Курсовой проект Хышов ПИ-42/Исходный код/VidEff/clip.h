#ifndef CLIP_H
#define CLIP_H

#include "defs.h"
#include "effectlib.h"
#include "filter.h"
#include "clipsource.h"

enum ClipType
{
	CLIP_SG = 0,
	CLIP_COMBO
};

struct ClipOffsets
{
		int offsetStart, offsetEnd, initOffset;
};

struct Keyframe
{
		int frame;
		vector<Property> props;
};

struct FilterEntry
{
		wstring flt;
		vector<Keyframe> keyframes;
};

class Clip
{
	public:
		Clip();
		virtual ~Clip();
		virtual int getFramesLength() = 0;
		virtual Frame * renderFrame(int pos) = 0;
		virtual Frame * getSrcFrame(int pos) = 0;
		virtual void addFilter(wstring fltName) = 0;
		virtual void removeFilter(int id) = 0;
		virtual void setFilterProp(int id, wstring propName, float value, int frameId = 0) = 0;
		virtual float getFilterProp(int id, wstring propName, int frameId = 0) = 0;
		virtual vector<FilterEntry> getUsedFilters() = 0;
		virtual ClipType getType() = 0;
		virtual bool usesSource(ClipSource *src) = 0;
};

class ClipSingle : public Clip
{
	private:
		int frameOffsetStart, frameOffsetEnd;
		vector<FilterEntry> usedFilters;
		ClipSource *src;
	public:
		ClipSingle();
		ClipSingle(ClipSource *src, int frameOffsetStart = 0, int frameOffsetEnd = 0);
		Frame * renderFrame(int pos);
		Frame * getSrcFrame(int pos);
		void addFilter(wstring fltName);
		void removeFilter(int id);
		void setFilterProp(int id, wstring propName, float value, int frameId = 0);
		float getFilterProp(int id, wstring propName, int frameId = 0);
		vector<FilterEntry> getUsedFilters();
		ClipType getType();
		int getFramesLength();
		bool usesSource(ClipSource *src);
};

class ClipCombo : public Clip
{
	private:
		Clip *clipA, *clipB;
		vector<FilterEntry> usedFilters;
		wstring usedTransition;
		int transFrames;
	public:
		ClipCombo();
		ClipCombo(Clip *clipA, Clip *clipB, int transitionFrames);
		Frame * renderFrame(int pos);
		Frame * getSrcFrame(int pos);
		void addFilter(wstring fltName);
		void removeFilter(int id);
		void setFilterProp(int id, wstring propName, float value, int frameId = 0);
		float getFilterProp(int id, wstring propName, int frameId = 0);
		vector<FilterEntry> getUsedFilters();
		ClipType getType();
		int getFramesLength();
		bool usesSource(ClipSource *src);
		void setTransition(wstring transName, int frames);
};

#endif // CLIP_H
