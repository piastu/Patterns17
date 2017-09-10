#ifndef UTIL
#define UTIL

#include <QCoreApplication>
#include <QList>
#include <QPoint>
#include <QTime>
#include <cmath>

using namespace std;

#define point_fail QPoint(-1, -1)
#define at_north - QPoint(0, 1)
#define at_west - QPoint(1, 0)
#define at_south + QPoint(0, 1)
#define at_east + QPoint(1, 0)

void doDelay(int msec);
int manhattan(QPoint src, QPoint dest);
int getRandomWeighted(QList<int> weights);

template <typename T> void fillList(QList<T> *container, T src, int size)
{
	container->clear();
	for (int i = 0; i < size; i++)
		container->push_back(src);
}

#endif // UTIL

