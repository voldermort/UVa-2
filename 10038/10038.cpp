/* Alex Velazquez
 * Start: November 25, 2011 @ 08:07PM
 * End  : November 25, 2011 @ 08:13PM
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int N;
	while( cin >> N )
	{
		vector<int> diff;
		int t;
		int prev;
		for( int i=0; i<N; ++i )
		{
			cin >> t;
			if( i == 0 )
			{
				prev = t;
			}
			else
			{
				diff.push_back( (( prev>= t ) ? prev-t : t-prev ) );
				prev = t;
			}
		}
		sort( diff.begin(), diff.end() );
		bool isJolly = true;
		for( int i=1; i<=N-1; ++i )
		{
			if( i != diff[i-1] )
			{
				isJolly = false;
				break;
			}
		}
		cout << ( ( isJolly ) ? "Jolly" : "Not jolly" ) << endl;
	}
}
