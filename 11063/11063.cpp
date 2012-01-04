/* Alex Velazquez
 * Start: Tue Jan  3 23:49:37 EST 2012
 * End  : Wed Jan  4 00:10:27 EST 2012
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
	int c = 1;
	while( cin >> N )
	{
		vector<int> nums( N );
		for( int i=0; i<N; ++i )
			cin >> nums[i];
		set<int> seq;
		for( int i=0; i<N; ++i )
			for( int j=i; j<N; ++j )
				seq.insert( nums[i]+nums[j] );
		bool isIncreasing = ( nums[0]>=1 );
		for( int i=0; i<N-1; ++i )
			if( nums[i] >= nums[i+1] )
				isIncreasing = false;
			
		bool isB2 = ((int)seq.size() == N*(N+1)/2 && isIncreasing);
		cout << "Case #" << c++ << ": It is " << ((!isB2)?"not ":"") << "a B2-Sequence.";
		cout << "\n\n";
	}
}
