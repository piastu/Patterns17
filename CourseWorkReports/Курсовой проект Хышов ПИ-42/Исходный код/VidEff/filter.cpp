#include "filter.h"

Filter::Filter()
{

}

FltInvert::FltInvert() : Filter()
{

}

wstring FltInvert::getName()
{
	return L"invert";
}

Frame *FltInvert::use(Frame *inp)
{
	Frame *result = new Frame(inp->width(), inp->height(), nullptr);
	uint32_t *resData = result->getData(), *inpData = inp->getData();
	int sizeInt = result->width() * result->height();
	for (int i = 0; i < sizeInt; i++)
	{
		Color c;
		c.rgba = inpData[i];
		c.setR(255 - c.r());
		c.setG(255 - c.g());
		c.setB(255 - c.b());
		resData[i] = c.rgba;
	}
	if (inp->isTemporary())
		delete inp;
	return result;
}

Frame *FltInvert::use(Frame *inp, vector<Property> props)
{
	return this->use(inp);
}

vector<PropertyInfo> FltInvert::getPropertiesInfo()
{
	return vector<PropertyInfo>();
}

FltBlur::FltBlur() : Filter()
{

}

wstring FltBlur::getName()
{
	return L"blur";
}

Frame *FltBlur::use(Frame *inp)
{
	Frame *result = new Frame(inp->width(), inp->height(), nullptr);
	uint32_t *resData = result->getData();
	uint32_t *srcData = inp->getData();
	int w = result->width(),
			h = result->height();
	// по умолчанию - 3x3
	int convSize = 9;
	// вспомогательные структуры
	Color c, cCore;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			c.rgba = srcData[i * w + j];
			int r = 0,
					g = 0,
					b = 0;
			int kFrom = i - 1, kTo = i + 1, lFrom = j - 1, lTo = j + 1;
			for (int k = kFrom; k <= kTo; k++)
			{
				for (int l = lFrom; l <= lTo; l++)
				{
					int kCor = clamp(k, 0, h - 1);
					int lCor = clamp(l, 0, w - 1);
					cCore.rgba = srcData[kCor * w + lCor];
					r += cCore.r();
					g += cCore.g();
					b += cCore.b();
				}
			}
			r /= convSize;
			g /= convSize;
			b /= convSize;
			resData[i * w + j] = c.rgba;
		}
	}
	if (inp->isTemporary())
		delete inp;
	return result;
}

Frame *FltBlur::use(Frame *inp, vector<Property> props)
{
	Frame *result = new Frame(inp->width(), inp->height(), nullptr);
	uint32_t *resData = result->getData();
	uint32_t *srcData = inp->getData();
	int w = result->width(),
			h = result->height();
	int radX = 1, radY = 1;
	int sizeInt = props.size();
	for (int i = 0; i < sizeInt; i++)
	{
		Property prop = props[i];
		if (prop.name == L"radx")
		{
			radX = (int)prop.value;
		}
		else if (prop.name == L"rady")
		{
			radY = (int)prop.value;
		}
	}
	// по умолчанию - 3x3
	int convSize = 9;
	// вспомогательные структуры
	Color c, cCore;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			c.rgba = srcData[i * w + j];
			int r = 0,
					g = 0,
					b = 0;
			int kFrom = i - radY, kTo = i + radY, lFrom = j - radX, lTo = j + radX;
			for (int k = kFrom; k <= kTo; k++)
			{
				for (int l = lFrom; l <= lTo; l++)
				{
					int kCor = clamp(k, 0, h - 1);
					int lCor = clamp(l, 0, w - 1);
					cCore.rgba = srcData[kCor * w + lCor];
					r += cCore.r();
					g += cCore.g();
					b += cCore.b();
				}
			}
			r /= convSize;
			g /= convSize;
			b /= convSize;
			resData[i * w + j] = c.rgba;
		}
	}
	if (inp->isTemporary())
		delete inp;
	return result;
}

vector<PropertyInfo> FltBlur::getPropertiesInfo()
{
	vector<PropertyInfo> result;
	result.push_back(PropertyInfo(L"radx", L"X Radius", 1.0f, 100.0f, 1.0f, 1.0f));
	result.push_back(PropertyInfo(L"rady", L"Y Radius", 1.0f, 100.0f, 1.0f, 1.0f));
	return result;
}
