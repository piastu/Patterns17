#ifndef UTIL_H
#define UTIL_H

#include "defs.h"

template <class T> class ICollection
{
	public:
		ICollection();
		ICollection(QList<T> _data);
		virtual T at(int id) = 0;
		virtual void removeAt(int id) = 0;
		virtual void replaceAt(int id, T src) = 0;
		virtual int count() = 0;
};

template <class T> class IIterator
{
	public:
		IIterator();
		virtual T getNext() = 0;
		virtual void removeCurrentElement() = 0;
		virtual bool hasNext() = 0;
};

#endif // UTIL_H
