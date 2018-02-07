#ifndef CLIPSOURCE_H
#define CLIPSOURCE_H

#include "frame.h"
#include "defs.h"
#include "util.h"

using namespace std;

enum ClipSrcType
{
	CLIP_PICT = 0
};

class ClipSource
{
	public:
		ClipSource();
		virtual int getLength() = 0;
		virtual bool isConstant() = 0;
		virtual Frame * getFrame(int pos) = 0;
		virtual Frame * getFrame(int pos, int w, int h) = 0;
		virtual int width() = 0;
		virtual int height() = 0;
		virtual int getUID() = 0;
		virtual void setUID(int id) = 0;
		virtual wstring getName() = 0;
		virtual void setName(wstring name) = 0;
		virtual ClipSrcType getType() = 0;
};

class Picture : public ClipSource
{
	private:
		Frame *frame;
		int w, h;
		int uid;
		wstring name;
	public:
		Picture();
		Picture(Frame * data);
		int getLength();
		bool isConstant();
		Frame * getFrame(int pos);
		Frame * getFrame(int pos, int w, int h);
		int width();
		int height();
		int getUID();
		void setUID(int id);
		wstring getName();
		void setName(wstring name);
		ClipSrcType getType();
};

#endif // CLIPSOURCE_H
