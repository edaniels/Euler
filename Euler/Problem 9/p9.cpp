long long P9 (long long target)
{
	long long product = -1;

	long long a = 3, b = 4, c = 5;

	while ( (a+b+c) != target && ((a*a) + (b*b) == (c*c)));

	return a*b*c;
}