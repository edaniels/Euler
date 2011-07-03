long long P14 (long long target)
{
	long long current = target;
	long long chainLength = 0;
	long long count = target;
	long long longestChain[2] = {count, chainLength};

	while (count > 1)
	{
		while (current > 1)
		{
			if (current % 2 == 0)
				current /= 2;
			else
				current = (current*3) + 1;

			chainLength++;
		}

		if (chainLength > longestChain[1])
		{
			longestChain[0] = count;
			longestChain[1] = chainLength;
		}

		count--;
		current = count;
		chainLength = 0;
	}

	return longestChain[0];
}