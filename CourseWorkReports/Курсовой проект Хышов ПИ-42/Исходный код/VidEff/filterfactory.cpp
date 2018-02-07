#include "filterfactory.h"

FilterFactory::FilterFactory()
{
	int sizeint = fltAvailable.size();
	for (int i = 0; i < sizeint; i++)
	{
		fltReady[fltAvailable[i].name] = nullptr;
	}
}

Filter *FilterFactory::getFilter(wstring fltName)
{
	if (fltReady[fltName] == nullptr)
	{
		if (fltName == L"invert")
			fltReady[fltName] = new FltInvert();
		else if (fltName == L"blur")
			fltReady[fltName] = new FltBlur();
	}
	return fltReady[fltName];
}

vector<EntryDisp> FilterFactory::getAvailableFilters()
{
	return fltAvailable;
}

vector<PropertyInfo> FilterFactory::getFilterPropsInfo(wstring fltName)
{
	Filter *flt = getFilter(fltName);
	return flt->getPropertiesInfo();
}
