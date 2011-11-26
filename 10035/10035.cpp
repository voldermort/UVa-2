/* Alex Velazquez
 * Start: Fri Nov 25 20:50:10 EST 2011
 * End  : Fri Nov 25 21:05:27 EST 2011
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

void addLeadingZeros( string &A, string &B )
{
	int aSize = A.size();
	int bSize = B.size();
	if( aSize == bSize )
		return;
	else
	{
		if( aSize > bSize ) // add zeroes to B
		{
			for( int i=0; i<aSize-bSize; ++i )
				B = "0" + B;
		}
		else
		{
			for( int i=0; i<bSize-aSize; ++i )
				A = "0" + A;
		}
	}
}

int main ()
{
	string A, B;
	while( cin >> A >> B )
	{
		if( A == "0" && B == "0" )
			break;
		addLeadingZeros( A, B );
		int size = A.size();
		int numCarry = 0;
		int carry = 0;
		for( int i=size-1; i>=0; --i )
		{
			int a = A[i]-48;
			int b = B[i]-48;
			if( a+b+carry > 9 )
			{
				++numCarry;
				carry = 1;
			}
			else
				carry = 0;
		}
		if( numCarry == 0 )
			cout << "No carry operation." << endl;
		else if( numCarry == 1 )
			cout << "1 carry operation." << endl;
		else
			cout << numCarry << " carry operations." << endl;
	}
}
