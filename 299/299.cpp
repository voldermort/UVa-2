/* Alex Velazquez
 * Start: Mon Jan  2 18:01:30 EST 2012
 * End  : Mon Jan  2 18:07:40 EST 2012
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

int bubbleSort( vector<int> &nums )
{
	int s = nums.size();
	int counter = 0;
	for( int i=0; i<s-1; ++i )
	{
		for( int j=i+1; j<s; ++j )
		{
			if( nums[i] >= nums[j] )
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				++counter;
			}
		}
	}
	return counter;
}

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
		int numSwaps = bubbleSort( nums );
		cout << "Optimal train swapping takes ";
		cout << numSwaps << " swaps." << endl; 
	}
}
