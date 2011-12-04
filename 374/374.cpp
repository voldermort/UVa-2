/* Alex Velazquez
 * Start: Sat Dec  3 19:09:22 EST 2011
 * End  : Sat Dec  3 19:28:32 EST 2011
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

int square( int x )
{
	return x*x;
}

int bigMod( int B, int P, int M )
{
	if( P == 0 )
		return 1;
	else if( P == 1 )
		return B%M;
	else
	{
		if( P%2 == 0 )
			return square( bigMod( B, P/2, M )%M )%M;
		else
			return ((square( bigMod( B, P/2, M )%M )%M)*(B%M))%M;
	}
}

int main ()
{
	int B, P, M;
	while( cin >> B >> P >> M )
	{
		cout << bigMod( B, P, M ) << endl;
	}
}
