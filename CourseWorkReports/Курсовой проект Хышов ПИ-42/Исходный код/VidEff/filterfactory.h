#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H

#include "defs.h"
#include "filter.h"

class FilterFactory
{
	private:
		map<wstring, Filter*> fltReady;
	public:
		FilterFactory();
		Filter * getFilter(wstring fltName);
		vector<EntryDisp> getAvailableFilters();
		vector<PropertyInfo> getFilterPropsInfo(wstring fltName);
};

#endif // FILTERFACTORY_H
