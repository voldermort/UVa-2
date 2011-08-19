/* Name: Alex Velazquez
 * Date: August 2, 2011
 * Purpose: To solve problem 138 - Street Numbers in UVa website
 * Link to problem: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=74 
 */
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ULL;

// Returns sum of 1 + 2 + ... + n
ULL S (ULL n)
{
	return n*(n+1)/2; 
}

bool binarySearch (ULL first, ULL last, ULL guess, int currGuesses, int numMaxGuesses, ULL N);

int main ()
{	
	int N=10; // Number of houses
	int numSolutions=0; // number of solutions currently found
	const int LIMIT = 10; // we must output only the first 10 solutions
	
	/*
	cout << 1     << " " << 57121 << " " << (int)float(    57121+1)/2 << endl;
	cout << 28561 << " " << 57121 << " " << (int)float(28561+57121)/2 << endl;
	cout << 28561 << " " << 42841 << " " << (int)float(28561+42841)/2 << endl;
	cout << 35701 << " " << 42841 << " " << (int)float(35701+42841)/2 << endl;
	cout << 39271 << " " << 42841 << " " << (int)float(39271+42841)/2 << endl;
	cout << 39271 << " " << 41056 << " " << (int)float(39271+41056)/2 << endl;
	cout << 40163 << " " << 41056 << " " << (int)float(40163+41056)/2 << endl;
	cout << 40163 << " " << 40609 << " " << (int)float(40163+40609)/2 << endl;
	cout << 40386 << " " << 40609 << " " << (int)float(40386+40609)/2 << endl;
	cout << 40386 << " " << 40497 << " " << (int)float(40386+40497)/2 << endl;
	cout << 40386 << " " << 40441 << " " << (int)float(40386+40441)/2 << endl;
	cout << 40386 << " " << 40413 << " " << (int)float(40386+40413)/2 << endl;
	cout << 40386 << " " << 40399 << " " << (int)float(40386+40399)/2 << endl;
	cout << 40386 << " " << 40392 << " " << (int)float(40386+40392)/2 << endl;
	cout << 40389 << " " << 40392 << " " << (int)float(40389+40392)/2 << endl;
	cout << 40390 << " " << 40392 << " " << (int)float(40390+40392)/2 << endl;
	*/
	
	
	while (numSolutions < LIMIT) // loop through N until we find the 10 solutions
	{
		// k represents the house number of the computer programmer
		bool result = binarySearch(1,N,(int)float(1+N)/2,0,(int)ceil(log2(N)),N);
		if (result)
			++numSolutions;
		++N;
	}
	
	/*
	for (int i=2;i<300000;++i)
	{
		binarySearch(1,i,(int)float(1+i)/2,0,(int)ceil(log2(i)),i);
	}
	*/
	
}

bool binarySearch (ULL first, ULL last, ULL guess, int currGuesses, int numMaxGuesses, ULL N)
{
	if (currGuesses > numMaxGuesses)
		return false;
	ULL leftSide  = S(guess-1);
	ULL rightSide = S(N)-leftSide-guess;
	if (leftSide == rightSide) // found solution
	{
		cout << guess << " " << N << endl;
		return true;
	}
	else if (leftSide < rightSide)
	{
		//cout << guess << " " << last << " " << (int)float(guess+last)/2 << endl;
		binarySearch(guess,last,(int)float(guess+last)/2,currGuesses+1,numMaxGuesses,N);
	}
	else
	{
		//cout << first << " " << guess << " " << (int)float(first+guess)/2 << endl;
		binarySearch(first,guess,(int)float(first+guess)/2,currGuesses+1,numMaxGuesses,N);
	}
}
