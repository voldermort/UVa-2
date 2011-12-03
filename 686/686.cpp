/* Alex Velazquez
 * Start: Sat Dec  3 18:17:46 EST 2011
 * End  : Sat Dec  3 18:21:05 EST 2011
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

bool isPrime( int n )
{
	if( n <= 1 )
		return false;
	for( int i=2; i*i<=n; ++i )
		if( n%i == 0 )
			return false;
	return true;
}

int main ()
{
	int N;
	while( cin >> N )
	{
		if( N == 0 )
			break;
		bool found = false;
		int c = 0;
		for( int a=2; a<=N/2; ++a )
		{
			if( isPrime(a) && isPrime(N-a) )
				++c;
		}
		cout << c << endl;
	}
}
