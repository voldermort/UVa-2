/* Alex Velazquez
 * Start: Wed Dec 28 22:51:00 EST 2011
 * End  : Wed Dec 28 22:56:34 EST 2011
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
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int R;
		cin >> R;
		vector<int> nums( R );
		for( int j=0; j<R; ++j )
		{
			int N; 
			cin >> nums[j];
		}
		sort( nums.begin(), nums.end() );
		// find median
		int size = nums.size();
		int m = size/2;
		int d = 0;
		for( int j=0; j<R; ++j )
			d += abs( nums[m]-nums[j] );
		cout << d << endl;
	}
}
