/* Alex Velazquez
 * Start: Sun Dec 11 21:30:10 EST 2011
 * End  : Sun Dec 11 22:29:38 EST 2011
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

int main ()
{
	int N;
	while( scanf( "%d\n", &N ) )
	{
		if( N == 0 )
			break;
		vector<int> nums( N );
		for( int i=0; i<N; ++i )
			scanf( "%d", &nums[i] );
		sort( nums.begin(), nums.end() );
		printf( "%d", nums[0] );
		for( int i=1; i<N; ++i )
			printf( " %d", nums[i] );
		printf( "\n" );
	}
}
