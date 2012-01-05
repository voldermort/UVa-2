/* Alex Velazquez
 * Start: Wed Jan  4 22:51:13 EST 2012
 * End  : Wed Jan  4 23:01:35 EST 2012
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
		vector<int> nums( 10 );
		for( int j=1; j<=N; ++j )
		{
			int X = j;
			while( X >= 10 )
			{
				++nums[X%10];
				X /= 10;
			}
			++nums[X];
		}
		cout << nums[0];
		for( int j=1; j<10; ++j )
			cout << " " << nums[j];
		cout << endl;
	}
}
