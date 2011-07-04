#include <fstream>
#include "../BigInt.h"
#include <iostream>

using namespace std;

void calcMaxTriangleRow (BigInt top[], BigInt bottom[], int bottomSize)
{
	BigInt left, right;
	int topSize = bottomSize - 1;

	if (bottomSize == 1)
	{
		left = bottom[0];
		right = bottom[1];

		(left > right) ? top[0] = left + top[0] : top[0] = right + top[0];
	}

	for (int i = 0; i < topSize; i++)
	{
		left = bottom[i];
		right = bottom[i+1];

		(left > right) ? top[i] = left + top[i] : top[i] = right + top[i];
			
	}
}

BigInt P67 ()
{
	fstream triangleTxt = fstream("triangle.txt",ios::in);

	BigInt triangle[100][100];

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < (i+1); j++)
			triangleTxt >> triangle[i][j];
	}

	int size = 100;

	int i = 1;

	while (size > 1)
	{
		calcMaxTriangleRow(triangle[100-i-1], triangle[100-i], size--);

		i++;
	}

	return triangle[0][0];
}