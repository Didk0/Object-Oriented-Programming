#include <iostream>
#include "Runner.h"
using namespace std;

int main()
{
	int n;
	cin >> n;
	Runner* runners = new Runner[n];
	for (int i = 0; i < n; i++)
	{
		Runner* runner = init();
		runners[i] = *runner;
	}

	printLowestTempo(runners, n);

	return 0;
}