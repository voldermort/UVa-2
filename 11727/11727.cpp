/* Alex Velazquez
 * Start: Tue Nov 29 19:48:27 EST 2011
 * End  : Tue Nov 29 19:52:38 EST 2011
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
	for( int i=1; i<=T; ++i )
	{
		int A, B, C;
		vector<int> nums;
		cin >> A >> B >> C;
		nums.push_back( A );
		nums.push_back( B );
		nums.push_back( C );
		sort( nums.begin(), nums.end() );
		cout << "Case " << i << ": ";
		cout << nums[1] << endl;
	}
}
