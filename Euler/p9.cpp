long long P9 (long long target)
{
	long long product = -1;
	
	for (int i = 3; i < target - i; i++)
		for (int j = 4; j < target - i - j; j++)
			for (int k = 5; k <= target - i - j; k++)
				if (i*i + j*j == k*k && i+j+k == target)
					return i*j*k;

	return product;
}