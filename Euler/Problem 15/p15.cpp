#include "..\BigInt.h"

BigInt P15 (int target)
{
	BigInt two = 2;
	int n = 2;

	while (n <= target)
	{
		two += two;
		n++;
	}

	return two.sumDigits();
}