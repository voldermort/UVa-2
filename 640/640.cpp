/* Alex Velazquez
 * Start: Wed Nov 30 20:47:06 EST 2011
 * End  : Wed Nov 30 22:10:47 EST 2011 Wed Nov 30 22:10:44 EST 2011 Wed Nov 30 21:45:04 EST 2011
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

using namespace std;

int d( int N )
{
	int S = N;
	while( N >= 10 )
	{
		S += N%10;
		N /= 10;
	}
	return S+N;	
}

int main ()
{
	int limit = 1000010;
	vector<bool> M( limit, false);
	int c = 0;
	for( int i=1; i<=limit; ++i )
	{
		if( M[i] == false )
		{
			printf( "%d\n", i );
			// produce non-self-numbers
			int N = i;
			while( N <= limit )
			{
				N = d( N );
				if( N <= limit && M[N] == false )
					M[N] = true;
				else
					break;
			}
		}
	}
}
