#include "clipsource.h"

ClipSource::ClipSource()
{

}

Picture::Picture() : ClipSource()
{
	w = h = 0;
	uid = genRandUID();
}

Picture::Picture(Frame *data) : Picture()
{
	this->frame = data;
	w = frame->width();
	h = frame->height();
}

int Picture::getLength()
{
	return 1;
}

bool Picture::isConstant()
{
	return true;
}

Frame *Picture::getFrame(int pos)
{
	// здесь кадр - единственный
	return frame->clone();
}

Frame *Picture::getFrame(int pos, int w, int h)
{
	Frame *result = new Frame(w, h, nullptr);
	int oldW = frame->width(), oldH = frame->height();
	float kx = (float)oldW / (float)w;
	float ky = (float)oldH / (float)h;
	uint32_t *data = result->getData(), *src = frame->getData();
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			data[i * w + j] = src[(int)(i * ky) * oldW + (int)(j * kx)];
		}
	}
	return result;
}

int Picture::width()
{
	return frame->width();
}

int Picture::height()
{
	return frame->height();
}

int Picture::getUID()
{
	return uid;
}

void Picture::setUID(int id)
{
	uid = id;
}

wstring Picture::getName()
{
	return name;
}

void Picture::setName(wstring name)
{
	this->name = name;
}

ClipSrcType Picture::getType()
{
	return CLIP_PICT;
}
