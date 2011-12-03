/* Alex Velazquez
 * Start: Sat Dec  3 17:10:58 EST 2011
 * End  : Sat Dec  3 17:25:38 EST 2011
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

#define DEBUG 0

using namespace std;

int GCD( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main ()
{
	int T;
	while( cin >> T )
	{
		if( T == 0 )
			break;
		vector<int> nums;
		int n;
		for( int i=0; i<T; ++i )
		{
			cin >> n;
			nums.push_back( n );
		}
		int size = nums.size();
		double totalPairs = 0;
		double totalCommonFactors = 0;
		for( int i=0; i<nums.size()-1; ++i )
		{
			for( int j=i+1; j<nums.size(); ++j )
			{
				if( GCD(nums[i],nums[j]) == 1 )
					totalCommonFactors += 1.0;
				totalPairs += 1.0;
			}
		}
		#if DEBUG
			cout << "totalCommonFactors: " << totalCommonFactors << endl;
			cout << "totalPairs: " << totalPairs << endl;
		#endif 
		if( totalCommonFactors == 0.0 )
			printf( "No estimate for this data set.\n" );
		else
			printf( "%.6f\n", sqrt((6.0*totalPairs)/totalCommonFactors) );
	}
}
