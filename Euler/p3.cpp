#include <math.h>
#include <iostream>
#include "functions.h"

using namespace std;

long long P3 (long long target)
{
	long long lastFactor;

	long long factor = 3;
	
	if (target % 2 == 0)
	{
		target /= 2;

		lastFactor = 2;

		while (target % 2 == 0)
			target /= 2;
	}
	else
		lastFactor = 1;

	long long maxFactor = sqrt(static_cast<long double>(target));

	while ( target > 1 && lastFactor <= maxFactor)
	{
		if (target % factor == 0)
		{
			target /= factor;

			lastFactor = factor;

			while (target % factor == 0)
				target /= factor;
		}

		maxFactor = sqrt(static_cast<long double>(target));
		
		factor += 2;
	}

	if (target == 1)
		return lastFactor;
	else
		return target;
}