/* Alex Velazquez
 * Start: Sat Dec 10 20:58:22 EST 2011
 * End  : Sat Dec 10 21:51:04 EST 2011
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <string>

#define DEBUG 0

using namespace std;

int power10( int N )
{
	int t = 1;
	for( int i=0; i<N; ++i )
		t *= 10;
	return t;
}

vector<int> getDigits( int N )
{
	vector<int> digits(10);
	while( N >= 10 )
	{
		int d = N%10;
		N /= 10;
		++digits[d];
	}
	++digits[N];
	return digits;
}

int getDescDigits( int N ) 
{
	vector<int> digits = getDigits( N );
	int e = 0;
	int out = 0;
	for( int i=0; i<10; ++i )
	{
		#if DEBUG
			cout << "digits["<< i<<"]: " << digits[i] << endl;
		#endif
		for( int j=0; j<digits[i]; ++j )
		{
			out += i*power10( e );
			++e;
		}
	}
	return out;
}

int getAscDigits( int N )
{
	vector<int> digits = getDigits( N );
	int e = 0;
	int out = 0;
	for( int i=9; i>=0; --i )
	{
		for( int j=0; j<digits[i]; ++j )
		{
			out += i*power10( e );
			++e;
		}
	}
	return out;
}

int main ()
{
	int N;
	while( cin >> N )
	{
		if( N == 0 )
			break;
		int chainLength = 1;
		cout << "Original number was " << N << endl;
		set<int> chain;
		chain.insert( N );
		while( 1 ) 
		{
			int descDigits = getDescDigits( N );
			int ascDigits  = getAscDigits ( N );
			int newNumber = descDigits-ascDigits;
			pair<set<int>::iterator, bool> result = chain.insert( newNumber );
			cout << descDigits << " - " << ascDigits << " = " << newNumber << endl;
			if( result.second == false ) // duplicate
			{
				break;
			}
			++chainLength;
			N = newNumber;
		}
		cout << "Chain length " << chainLength << endl << endl;
	}
}
