#include <util.h>

void doDelay(int msec)
{
	QTime dieTime = QTime::currentTime().addMSecs(msec);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int manhattan(QPoint src, QPoint dest)
{
	return (abs(dest.x() - src.x()) + abs(dest.y() - src.y()));
}

// получение случайной величины с дискретным распределением
int getRandomWeighted(QList<int> weights)
{
	int weightSum = 0;
	foreach (int value, weights)
	{
		weightSum += value;
	}
	int rnd = qrand()%(weightSum) + 1;
	weightSum = 0;
	for (int i = 0; i < weights.size(); i++)
	{
		if (rnd > weightSum && rnd <= weightSum + weights[i])
			return i;
		weightSum += weights[i];
	}
	// в случае перевеса
	return -1;
}
