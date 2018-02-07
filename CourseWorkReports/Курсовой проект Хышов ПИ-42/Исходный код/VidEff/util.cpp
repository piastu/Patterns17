#include "util.h"

int genRandUID()
{
	int result = 0x00000000;
	for (int i = 0; i < 8; i++)
	{
		result = result << 4;
		int digit = rand() % 0xf;
		result |= digit;
	}
	return result;
}
