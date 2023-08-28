#include "Runner.h"

Runner* init()
{
	Runner* runner;

	char name[50];
	std::cin.getline(name, 50);

	runner->name = new char[strlen(name) + 1];
	if (!runner->name)
	{
		return nullptr;
	}

	strcpy(runner->name, name);

	for (size_t i = 0; i < 12; i++)
	{
		std::cin >> runner->runTimes[i];
	}

	return runner;
}

double getAverage(Runner* runner)
{
	double avg = 0;

	for (size_t i = 0; i < 12; i++)
	{
		avg += runner->runTimes[i];
	}

	return avg / 12;
}

void printLowestTempo(Runner* runners, size_t count)
{
	double min = 100;
	int ind = 0;
	for (size_t i = 0; i < count; i++)
	{
		double curr = getAverage(&runners[i]) / 42;
		if (curr < min)
		{
			min = curr;
			ind = i;
		}
	}

	std::cout << runners[ind].name << ' ' << min << std::endl;
}

size_t Runner::bearNtimes(Runner*& other)
{
	size_t cnt = 0;
	for (size_t i = 0; i < 12; i++)
	{
		if (runTimes[i] > other->runTimes[i])
		{
			cnt++;
		}
	}
	return cnt;
}
