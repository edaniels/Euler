#include <math.h>
#include "functions.h"

long long P7 (long long target)
{
	long long currPrime = 2;
	long long currPrimeNum = 1;
	bool primeBool;
	long long i = 2;
	
	while(true)
	{
		primeBool = isPrime(i);

		if (primeBool && i != 2)
		{
			currPrime = i;
			++currPrimeNum;

		}
		
		i++;

		if (currPrimeNum == target)
			break;
	}

	return currPrime;
}