/* Alex Velazquez
 * Start: Mon Jan  2 20:17:46 EST 2012
 * End  : Mon Jan  2 20:29:39 EST 2012
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
		int N;
		cin >> N;
		vector<int> nums( N );
		for( int j=0; j<N; ++j )
			cin >> nums[j];
		sort( nums.begin(), nums.end() );
		cout << "Case " << i+1 << ": " << nums[N/2] << endl;
	}
}
