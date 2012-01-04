/* Alex Velazquez
 * Start: Tue Jan  3 23:17:24 EST 2012
 * End  : Tue Jan  3 23:34:56 EST 2012
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

int main ()
{
	int N;
	int c = 1;
	while( cin >> N )
	{
		vector<LL> nums( N );
		LL maxx = 0LL;
		for( int i=0; i<N; ++i )
			cin >> nums[i];
		LL t = 0LL;
		for( int i=0; i<N; ++i )
		{
			t = nums[i];
			maxx = (t>maxx)?t:maxx;
			for( int j=i+1; j<N; ++j )
			{
				t *= nums[j];
				maxx = (t>maxx)?t:maxx;
			}
		}
		cout << "Case #" << c++ << ": The maximum product is " << maxx << "." << endl;
		cout << endl;
	}
}
