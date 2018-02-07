#ifndef UTIL_H
#define UTIL_H

#include "defs.h"

struct Color
{
		uint32_t rgba;
		Color()
		{
			rgba = 0;
		}
		Color(int r, int g, int b, int a = 255)
		{
			rgba = 0;
			uint32_t result = 0;
			result |= r;
			result = result << 4;
			result |= g;
			result = result << 4;
			result |= b;
			result = result << 4;
			result |= a;
			rgba = result;
		}
		int r()
		{
			unsigned int result = rgba;
			result &= 0xff000000;
			result = result >> 24;
			return result;
		}
		int g()
		{
			unsigned int result = rgba;
			result &= 0x00ff0000;
			result = result >> 16;
			return result;
		}
		int b()
		{
			unsigned int result = rgba;
			result &= 0x0000ff00;
			result = result >> 8;
			return result;
		}
		int a()
		{
			int result = rgba;
			result &= 0x000000ff;
			return result;
		}
		void setR(int r)
		{
			rgba &= 0x00ffffff;
			int newR = r << 24;
			rgba |= newR;
		}
		void setG(int g)
		{
			rgba &= 0xff00ffff;
			int newG = g << 16;
			rgba |= newG;
		}
		void setB(int b)
		{
			rgba &= 0xffff00ff;
			int newB = b << 8;
			rgba |= newB;
		}
		void setA(int a)
		{
			rgba &= 0xffffff00;
			int newA = a;
			rgba |= newA;
		}
};

int genRandUID();

template <typename t> t clamp(t x, t a, t b)
{
	return (x >= a ? (x <= b ? x : b) : a);
}

#endif // UTIL_H
