#ifndef FRAME_H
#define FRAME_H

#include "defs.h"

using namespace std;

class Frame
{
	private:
		int w, h;
		uint32_t *rgbaData;
		bool isTmp;
	public:
		Frame();
		Frame(int w, int h, uint32_t *data);
		~Frame();
		int width();
		int height();
		uint32_t * getData();
		void setData(uint32_t *data);
		bool isTemporary();
		void setTemporary(bool tmp);
		Frame * clone();
};

#endif // FRAME_H
