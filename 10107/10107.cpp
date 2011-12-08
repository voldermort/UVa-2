/* Alex Velazquez
 * Start: Thu Dec  8 00:24:16 EST 2011
 * End  : Thu Dec  8 00:35:14 EST 2011
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
	vector<int> nums;
	while( cin >> N )
	{
		nums.push_back( N );
		sort( nums.begin(), nums.end() );
		int size = nums.size();
		if( size%2 == 0 )
		{
			cout << (nums[size/2]+nums[size/2-1])/2 << endl;
		}
		else
		{
			cout << nums[size/2] << endl;
		}
	}
}
