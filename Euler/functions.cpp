#include "functions.h"
#include <math.h>

bool isPrime (long long number)
{

	bool isPrime = true;
	
	for (int i = 2; i <= sqrt(static_cast<long double>(number)); i++)
		{
			if (number % 2 == 0)
			{
				isPrime = false;
				break;
			}
			if (!(number % i))
			{
				isPrime = false;
				break;
			}
		}
		
	return isPrime;
	
}