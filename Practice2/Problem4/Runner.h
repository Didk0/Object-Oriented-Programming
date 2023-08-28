#pragma once
#include <iostream>

struct Runner
{
	char* name;
	double runTimes[12];

	size_t bearNtimes(Runner*& other);
};

Runner* init();

void printLowestTempo(Runner* runners, size_t count);
