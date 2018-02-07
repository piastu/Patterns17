#ifndef DEFS_H
#define DEFS_H

#include "list"
#include "vector"
#include "string"
#include "map"
#include "stdint.h"

using namespace std;

struct EntryDisp
{
		wstring name, displayName;
		EntryDisp()
		{
			name = L"";
			displayName = L"";
		}
		EntryDisp(wstring name, wstring displayName)
		{
			this->name = name;
			this->displayName = displayName;
		}
};

#endif // DEFS_H
