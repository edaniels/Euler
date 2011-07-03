#include "Problem 1/p1.h"
#include "Problem 2/p2.h"
#include "Problem 3/p3.h"
#include "Problem 4/p4.h"
#include "Problem 5/p5.h"
#include "Problem 6/p6.h"
#include "Problem 7/p7.h"
#include "Problem 8/p8.h"
#include "Problem 9/p9.h"
#include "Problem 10/p10.h"
#include "Problem 11/p11.h"
#include "Problem 12/p12.h"
#include "Problem 13/p13.h"
#include "Problem 14/p14.h"
#include "Problem 15/p15.h"
#include <iostream>
#include <ctime>
#include "BigInt.h"

using namespace std;


int main ( )
{
	unsigned int start = clock();

	cout << fixed;

	cout << "1: " << P1() << endl;

	cout << "2: " << P2() << endl;
	
	cout << "3: " << P3(600851475143) << endl;

	cout << "4: " << P4() << endl;

	cout << "5: " << P5(1,20) << endl;

	cout << "6: " << P6(100) << endl;

	cout << "7: " << P7(10001) << endl;

	cout << "8: " << P8() << endl;

	cout << "9: " << P9(1000) << endl;

	cout << "10: " << P10(2000000) << endl;

	cout << "11: " << P11() << endl;

	cout << "12: " << P12(500) << endl;

	cout << "13: " << P13() << endl;

	cout << "14: " << P14(1000000) << endl;

	cout << "15: " << P15(1000) << endl;

	cout << "Time elapsed (ms): " << clock() - start << endl;

	system("Pause");

	return EXIT_SUCCESS;
}