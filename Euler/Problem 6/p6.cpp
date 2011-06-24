#include <math.h>

long long P6 (long long nums)
{
	long long sums_sq = 0LL;
	long long sum_sq;
	long long sum = 0LL;

	for (int i = 1; i <= nums; i++)
	{
		sums_sq += (i*i);
		sum += i;
	}

	sum_sq = sum*sum;

	return abs(static_cast<long double>(sum_sq - sums_sq));

}