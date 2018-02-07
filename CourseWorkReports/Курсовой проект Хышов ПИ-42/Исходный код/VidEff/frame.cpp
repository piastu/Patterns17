#include "frame.h"

Frame::Frame()
{
	isTmp = false;
	w = h = 0;
}

Frame::Frame(int w, int h, uint32_t *data) : Frame()
{
	this->w = w;
	this->h = h;
	if (data != nullptr)
	{
		this->rgbaData = data;
	}
	else
	{
		int sizeInt = w * h;
		this->rgbaData = new uint32_t[sizeInt];
		for (int i = 0; i < sizeInt; i++)
			rgbaData[i] = 0x00000000;
	}
}

Frame::~Frame()
{
	delete rgbaData;
}

int Frame::width()
{
	return w;
}

int Frame::height()
{
	return h;
}

uint32_t *Frame::getData()
{
	return rgbaData;
}

void Frame::setData(uint32_t *data)
{
	rgbaData = data;
}

bool Frame::isTemporary()
{
	return isTmp;
}

void Frame::setTemporary(bool tmp)
{
	isTmp = tmp;
}

Frame *Frame::clone()
{
	int sizeInt = w * h;
	Frame *result = new Frame(w, h, nullptr);
	uint32_t *data = result->getData();
	for (int i = 0; i < sizeInt; i++)
		data[i] = rgbaData[i];
	return result;
}
