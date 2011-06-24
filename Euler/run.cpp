#include "Problem 1/p1.h"
#include "Problem 2/p2.h"
#include "Problem 3/p3.h"
#include "Problem 4/p4.h"
#include "Problem 5/p5.h"
#include "Problem 6/p6.h"
#include "Problem 7/p7.h"
#include "Problem 8/p8.h"
#include <iostream>
#include <ctime>

using namespace std;


int main ( )
{
	int count = 0;

	int N = 10;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cout << i << "*" << j << endl;
			count++;
		}

	cout << "Count: " << count << endl;

	count = 0;

	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
		{
			cout << i << "*" << j << endl;
			count++;
		}

	cout << "Count: " << count << endl;

	cout << fixed;

	cout << "1: " << P1() << endl;

	cout << "2: " << P2() << endl;
	
	cout << "3: " << P3(600851475143) << endl;

	cout << "4: " << P4() << endl;

	cout << "5: " << P5(1,20) << endl;

	cout << "6: " << P6(100) << endl;

	cout << "7: " << P7(10001) << endl;

	cout << "8: " << P8() << endl;

	system("Pause");

	return EXIT_SUCCESS;
}