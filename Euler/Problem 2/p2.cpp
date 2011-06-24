int P2 ()
{
	int n = 1;

	int n2 = 2;

	int sum = 2;

	int val = 0;

	while (val <= 4000000)
	{
		val = n + n2;
		
		if (!(static_cast<int>(val) % 2))
			sum += val;

		n = n2;

		n2 = val;
	}

	return sum;

}