#include "../functions.h"

long long P10 (long long target)
{
	long long sum = 2;

	long long number = 3;

	while (number < target)
	{
		if (isPrime(number))
			sum += number;
		number+= 2;
	}

	return sum;
}