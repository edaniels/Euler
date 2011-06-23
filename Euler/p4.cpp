#include <iostream>
#include <math.h>
#include <string>
#include "p4.h"

using namespace std;

int P4 ()
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

	delete test;

	return largest;
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