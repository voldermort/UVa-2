/* Alex Velazquez
 * Start: Sat Dec  3 18:38:59 EST 2011
 * End  : Sat Dec  3 19:00:22 EST 2011
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

typedef long long LL;

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
	// precalculate all almost prime numbers
	vector<LL> almost_prime;
	for( int i=2; i<1000000; ++i )
	{
		if( isPrime( i ) )
		{
			// calculate all values i^n less than 10^12
			LL curr = (LL)i;
			while( 1 )
			{
				curr *= i;
				if( curr < 1000000000000LL  )
					almost_prime.push_back( curr );
				else
					break;
			}
		}
	}
	sort( almost_prime.begin(), almost_prime.end() );
	int size = almost_prime.size();
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		LL low, high;
		cin >> low >> high;
		int c = 0;
		for( int j=0; j<size; ++j )
		{
			if( almost_prime[j] > high )
				break;
			if( almost_prime[j] >= low && almost_prime[j] <= high )
				++c;
		}
		cout << c << endl;
	}
}
