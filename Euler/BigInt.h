#ifndef BIGINT_H
#define BIGINT_H

#include <fstream>

using namespace std;

class BigInt
{
	friend ostream & operator<< (ostream &, const BigInt &);

	public:
		BigInt();
		BigInt(int);
		BigInt(char *);
		~BigInt();
		BigInt(const BigInt &);
		BigInt & operator= (const BigInt &);
		BigInt & operator= (const int &);
		BigInt operator+ (const BigInt &);
		BigInt operator+ (const int &);
		void operator+= (const BigInt &);
		void operator+= (const int &);
		bool operator< (const BigInt &);
		BigInt operator++(int);
		int getLength();
		BigInt sumDigits();

	private:
		char *number;
		int size;
		int length;
		bool negative;
		void resize (int);
};		

#endif