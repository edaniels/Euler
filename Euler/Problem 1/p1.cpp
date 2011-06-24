int P1 ()
{
	
	int sum = 0;

	for (int i = 3; i < 1000; i++)
		if ( !(i % 3) || !(i % 5) )
			sum += i;

	return sum;
}