#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "p6.h"
#include "p7.h"
#include "p8.h"
#include <iostream>
#include <ctime>

using namespace std;


int main ( )
{
	cout << fixed;

	cout << "1: " << P1() << endl;

	cout << "2: " << P2() << endl;
	
	cout << "3: " << P3(600851475143) << endl;

	/*cout << "4: "; P4(); cout << endl;

	cout << "5: " << P5(1,20) << endl;

	cout << "6: " << P6(100) << endl;*/

	cout << "7: " << P7(10001) << endl;

	cout << "8: " << P8() << endl;

	system("Pause");

	return EXIT_SUCCESS;
}