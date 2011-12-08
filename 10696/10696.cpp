/* Alex Velazquez
 * Start: Wed Dec  7 22:30:24 EST 2011
 * End  : Wed Dec  7 22:41:25 EST 2011
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

int f91( int N, map<int,int> &M )
{
	if( N >= 101 )
		return N-10;
	else
	{
		if( M.find( N ) != M.end() )
		{
			return f91( f91( N+11, M ), M );
		}
		else
		{
			return M[N];
		}
	}
}

int main ()
{
	// precalculate all values < 101
	map<int,int> M;
	for( int i=100; i>=1; --i )
	{
		M[i] = f91( i, M );
	}
	int N;
	while( cin >> N )
	{
		if( N == 0 )
			break;
		cout << "f91(" << N << ") = ";
		if( N >= 101 )
			cout << f91( N, M ) << endl;
		else
			cout << M[N] << endl;
	}
}
