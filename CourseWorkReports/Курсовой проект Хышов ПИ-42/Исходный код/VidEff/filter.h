#ifndef FILTER_H
#define FILTER_H

#include "defs.h"
#include "frame.h"
#include "util.h"

const vector<EntryDisp> fltAvailable =
		vector<EntryDisp>({
							  EntryDisp(L"invert", L"Negative"),
							  EntryDisp(L"blur", L"Box blur")
						  });

struct PropertyInfo
{
		wstring name, displayName;
		float minValue, maxValue, defValue, valStep;
		PropertyInfo()
		{
			name = displayName = L"";
			minValue = maxValue = defValue = valStep = 0.0f;
		}
		PropertyInfo(wstring name,
					 wstring displayName,
					 float minValue,
					 float maxValue,
					 float defValue,
					 float valStep)
		{
			this->name = name;
			this->displayName = displayName;
			this->minValue = minValue;
			this->maxValue = maxValue;
			this->defValue = defValue;
			this->valStep = valStep;
		}
};

struct Property
{
		wstring name;
		float value;
		Property()
		{
			name = L"";
			value = 0.0f;
		}
		Property(wstring name, float value)
		{
			this->name = name;
			this->value = value;
		}
};

class Filter
{
	public:
		Filter();
		virtual wstring getName() = 0;
		virtual Frame * use(Frame *inp) = 0;
		virtual Frame * use(Frame *inp, vector<Property> props) = 0;
		//virtual Frame *use(Frame *inp);
		virtual vector<PropertyInfo> getPropertiesInfo() = 0;
};

class FltInvert : public Filter
{
	public:
		FltInvert();
		wstring getName();
		Frame * use(Frame *inp);
		Frame * use(Frame *inp, vector<Property> props);
		vector<PropertyInfo> getPropertiesInfo();
};

class FltBlur : public Filter
{
	public:
		FltBlur();
		wstring getName();
		Frame * use(Frame *inp);
		Frame * use(Frame *inp, vector<Property> props);
		vector<PropertyInfo> getPropertiesInfo();
};

#endif // FILTER_H
