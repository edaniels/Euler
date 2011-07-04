#include "BigInt.h"
#include <math.h>
#include <iostream>

using namespace std;

int power (int x, int y)
{
	if (y == 0)
		return 1;

	return x * power(x, y-1);
}

char * stripLeadingZeroes(char *number)
{
	int size = 0;
	int count = 0;

	char * tempPtr = number;

	while (*(tempPtr) == '0')
	{
		count++;
		tempPtr++;
	}

	while (*(tempPtr++) != '\0')
		size++;

	size++;

	number += count;

	char *newNumber = new char[size];

	for (int i = 0; i < size; i++)
		newNumber[i] = number[i];

	number -= count;

	return newNumber;
}

BigInt::BigInt()
{
	size = 6;
	length = size - 1;
	negative = false;

	number = new char[size];
	
	for (int i = 0; i < length; i++)
		*(number+i) = '0';
}

BigInt::BigInt(char *number)
{
	length = 0;

	while (*(number+length) != '\0')
		length++;

	this->size = length + 1;
	this->number = new char[size];

	for (int i = 0; i <= length; i++)
		this->number[i] = number[i];

	if (number[0] == '-')
		this->negative = true;
	else
		this->negative = false;
}

BigInt::BigInt(int number)
{
	int count = 0;
	negative = false;
	int tempNumber = number;

	if (number < 0)
		negative = true;

	while (tempNumber != 0)
	{
		tempNumber /= 10;
		count++;
	}

	size = count + 1;
	length = count;

	this->number = new char[size];

	for (int i = 0; i < length; i++)
	{
		if (negative)
			*(this->number+i) = '0' - (number / power(10,length-i-1));
		else
			*(this->number+i) = '0' + (number / power(10,length-i-1));

		number %= power(10,length-i-1);
	}

	this->number[size-1] = '\0';
}

BigInt::~BigInt()
{
	delete[] number;
}

ostream & operator<< (ostream & out, const BigInt & rightInt)
{
	if (rightInt.negative)
	{
		out << "-";
	}
	out << rightInt.number;
	
	return out;
}

istream & operator>> (istream & in, BigInt & rightInt)
{
	int temp;

	in >> temp;

	rightInt = BigInt(temp);
	
	return in;
}

BigInt BigInt::operator+ (const BigInt & right)
{
	int newSize = this->length + right.size;
	char *tempNumber = new char[newSize];
	int tempPlace;
	int leftCount = this->length;
	int rightCount = right.length;
	int newCount = newSize-1;

	for (int i = 0; i < newSize - 1; i++)
	{
		tempNumber[i] = '0';
	}

	tempNumber[newSize-1] = '\0';

	int carry = 0;

	while (leftCount > 0 || rightCount > 0 || carry > 0)
	{
		if (leftCount <= 0 && rightCount > 0)
			tempPlace = (right.number[rightCount-1] - '0') + carry;
		else if (rightCount <= 0 && leftCount > 0)
			tempPlace = (this->number[leftCount-1] - '0') + carry;
		else if (leftCount > 0 && rightCount > 0)
			tempPlace = (this->number[leftCount-1] - '0' + right.number[rightCount-1] - '0') + carry;
		else {

			int length = 1;
			int tempNum = carry;

			while (tempNum /= 10)
				length++;

			for (int i = 0; i < length; i++)
				tempNumber[newCount-i-1] = ((carry / power(10,i) % 10)) + '0';

			break;
		}

		if (tempPlace > 9)
		{
			carry = tempPlace/10;
			tempNumber[newCount-1] = (tempPlace % 10) + '0';
		}
		else
		{
			tempNumber[newCount-1] = tempPlace + '0';
			carry = 0;
		}

		leftCount--;
		rightCount--;
		newCount--;
	}

	BigInt tempInt((stripLeadingZeroes(tempNumber)));

	delete [] tempNumber;

	return tempInt;
}

BigInt BigInt::operator+(const int &number)
{
	return this->operator+(BigInt(number));
}

BigInt::BigInt(const BigInt & right)
{
	number = NULL;

	*this = right;
}

BigInt & BigInt::operator= (const BigInt & right)
{
	if (number != NULL)
		delete [] number;
	this->number = new char[right.size];
	this->length = right.length;
	this->size = right.size;
	this->negative = right.negative;

	for (int i = 0; i < right.size; i++)
		this->number[i] = right.number[i];

	return *this;
}

BigInt & BigInt::operator= (const int & right)
{
	return this->operator=(BigInt(right));
}

void BigInt::operator+= (const BigInt & right)
{
	*this = *this + right;
}

void BigInt::operator+= (const int & right)
{
	*this = *this + right;
}

bool BigInt::operator< (const BigInt & right)
{
	bool status = false;

	if (this->length < right.length)
		status = true;
	else if (this->length > right.length)
		status = false;
	else
	{
		for (int i=0; i < right.length; i++)
		{
			if (this->number[i] < right.number[i])
				status = true;
		}

	}

	return status;
}

BigInt BigInt::operator++(int)
{
	BigInt temp = *this;

	*this += 1;

	return temp;
}

int BigInt::getLength()
{
	return length;
}

BigInt BigInt::sumDigits()
{
	BigInt sum = 0;

	for (int i = 0; i < this->length; i++)
		sum += (this->number[i] - '0');

	return sum;
}

bool BigInt::operator> (const BigInt & right)
{
	bool status = false;

	if (this->length > right.length)
		status = true;
	else if (this->length < right.length)
		status = false;
	else
	{
		for (int i=0; i < right.length; i++)
		{
			if (this->number[i] > right.number[i])
			{
				status = true;
				break;
			}
			else if (this->number[i] < right.number[i])
			{
				status = false;
				break;
			}
		}

	}

	return status;
}