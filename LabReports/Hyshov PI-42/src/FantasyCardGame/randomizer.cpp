#include "randomizer.h"

Random::Random()
{

}

int Random::randInt(int from, int to)
{
	if (from != to)
		return (qrand()%(to - from + 1)) + from;
	else
		return from;
}

int Random::randIntWeighted(QVector<int> weights)
{
	int weightsCount = weights.size();
	int sum = 0, totalsum = 0;
	for (int i = 0; i < weightsCount; i++)
		totalsum += weights[i];
	int randNum = randInt(0, totalsum - 1);
	for (int i = 0; i < weightsCount; i++)
	{
		sum += weights[i];
		if (randNum < sum)
			return i;
	}
}

double Random::randDbl()
{
	return ((double)qrand()) / (double)RAND_MAX;
}

double Random::randDbl(double from, double to)
{
	return from + (to - from) * randDbl();
}

bool Random::probability(double prob)
{
	return (randDbl() < prob);
}
