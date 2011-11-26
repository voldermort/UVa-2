/* Alex Velazquez
 * Start: Sat Nov 26 18:24:16 EST 2011
 * End  : Sat Nov 26 18:59:34 EST 2011
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

using namespace std;

typedef long long LL;

int numDigits( LL X ) 
{
	int count = 1;
	while( X >= 10 )
	{
		X /= 10;
		++count;
	}
	return count;
}

LL power( int base, int exponent )
{
	LL t = 1LL;
	for( int i=0; i<exponent; ++i )
		t *= base;
	return t;
}


LL reverse( LL X, int numDigits ) 
{
	LL Y = 0LL;
	while( X >= 10 )
	{
		--numDigits;
		Y += power( 10, numDigits )*( X%10 );
		X /= 10;
	}
	return Y+X;
}

bool isPalindrome( LL X, int numDigits )
{
	int size = numDigits;
	for( int i=0; i<size/2; ++i )
	{
		//cout << (X/power(10,numDigits-1))%10 << " ";
		//cout << (X/power(10,i))%10 << endl; 
		if( (X/power(10,numDigits-1))%10 != (X/power(10,i))%10 )
			return false;
		--numDigits;
	}
	return true;
}

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		LL X;
		cin >> X;
		int iter = 0;
		int d;
		while( 1 )
		{
			
			d = numDigits( X );
			// add reverse
			X += reverse( X, d );
			++iter;
			d = numDigits( X );
			if( isPalindrome( X, d ) )
			{
				cout << iter << " " << X << endl;
				break;
			}
		}
	}
}
