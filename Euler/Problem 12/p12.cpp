#include <cmath>

long long P12 (long long target)
{
	long long divisors = 0;
	long long n = 1;
	long long number = 1;
	long long maxDiv = 0;
	long double upperLim;
	

	do
	{
		divisors = 0;
		n++;
		number = (n*(n+1)) / 2;

		upperLim = sqrt((long double)number);

		for (long long i = 1; i < upperLim; i++)
		{
			if (number % i == 0)
				divisors++;
		}

		divisors *=2;

	} while ( divisors <= target );

	return number;
}