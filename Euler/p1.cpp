#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int P1 ();
int P2 ();
void P3 ();
string reverse (string);
void P4();
long long P5 (long long a, long long b);
long long P6 (long long);
long long P7 (long long);
int P8 ();
int C2I (char intStr);

int main ( )
{
	cout << fixed;

	/*cout << "1: " << P1() << endl;

	cout << "2: " << P2() << endl;

	cout << "4: "; P4(); cout << endl;*/

	cout << "5: " << P5(1,20) << endl;

	//cout << "6: " << P6(100) << endl;

	//cout << "7: " << P7(20) << endl;

	cout << "8: " << P8() << endl;

	system("Pause");

	return EXIT_SUCCESS;
}

int P1 ()
{
	
	int sum = 0;

	for (int i = 3; i < 1000; i++)
		if ( !(i % 3) || !(i % 5) )
			sum += i;

	return sum;
}

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

void P3 ()
{
	double target = 600851475143;
	
	for (double i = 0; i < target; i++)
	{
		if ( (fmod(target, i))  == 0)
			cout << i << " is a prime factor\n";

	}

	return;
}

void P4 ()
{
	char *test = new char[20];

	int largest = 0;

	int tempNum;

	for (int i = 100; i < 999; i++)
		for (int j = 100; j < 999; j++)
		{
			tempNum = i * j;
			if ( string(itoa(tempNum,test,10)).compare(reverse(string(itoa(tempNum,test,10)))) == 0 && (tempNum) > largest)
			{
				
				
				largest = tempNum;
			}

		}

		cout << largest << "\n";

	delete test;

	return;
}

long long P5 (long long a, long long b)
{
	long long result;

	bool found = true;

	int i = b;
	
	unsigned long long start = clock();

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
	
	cout << "Time taken (ms): " << (clock() - start) << endl;

	return result;
}

string reverse (string in)
{
	char temp;



	for (int i = 0; i < in.length()/2; i++)
	{
		temp = in[i];

		in[i] = in.at(in.length() - i - 1);

		in[in.length() - i - 1] = temp;
	}

	return in;
}

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

	return abs(sum_sq - sums_sq);

}

long long P7 (long long target)
{
	long long currPrime = 2;
	long long currPrimeNum = 1;
	bool isPrime;
	long long i = 2;
	
	while(true)
	{
		isPrime = true;
		for (int j = 2; j <= sqrt(static_cast<long double>(i)); j++)
		{
			if (i % 2 == 0)
			{
				isPrime = false;
				break;
			}
			if (!(i % j))
			{
				isPrime = false;
				break;a
			}
		}

		if (isPrime && i != 2)
		{
			currPrime = i;
			++currPrimeNum;

			cout << currPrimeNum << ": " << currPrime << endl;
		}
		
		i++;

		if (currPrimeNum == target)
			break;
	}

	return currPrime;
}

int P8 ()
{
	string sequence = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

		int maxProduct = 0;
		int tempProduct;
		int chars = sequence.length();
		unsigned __int64 start = clock();

		for (int i = 0; i + 5 < chars; i++)
		{
			tempProduct = C2I(sequence.at(i)) * C2I(sequence.at(i+1)) * C2I(sequence.at(i+2)) 
								* C2I(sequence.at(i+3)) * C2I(sequence.at(i+4));

			if (tempProduct > maxProduct)
				maxProduct = tempProduct;
		}

		cout << "Time: " << clock() - start << endl;

		return maxProduct;
}

int C2I (char intStr)
{
	return intStr - '0';
}