long long P5 (long long a, long long b)
{
	long long result;

	bool found = true;

	int i = b;

	// Keep looping till found
	while (true)
	{
		found = true;
		
		for (int j = a; j < b; j++)
		{
			// Check if any i/j has a remainder
			if ( i % j )
			{
				found = false;
				break;
			}
		}

		if (found)
			break;
		else
			// Increment by b since b will have the largest multiples
			i += b;
	}

	result = i;

	return result;
}