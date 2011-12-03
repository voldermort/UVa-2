/* Alex Velazquez
 * Start: Fri Dec  2 23:19:22 EST 2011
 * End  : Fri Dec  2 23:43:13 EST 2011
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

int sumOddToN( int n )
{
	if( n == 2 ) return 1;
	if( n%2 == 0 ) --n;
	return (n+1)*(n+1)/4;
}

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int a, b;
		cin >> a >> b;
		cout << "Case " << i+1 << ": " << sumOddToN(b)-sumOddToN(a)+((a%2==1)?a:0) << endl;
		#if DEBUG
			cout << sumOddToN(b) << " " << sumOddToN(a) << " " << ((a%2==1)?a:0) << endl;
		#endif
	}
}
