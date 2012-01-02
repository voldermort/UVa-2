/* Alex Velazquez
 * Start: Mon Jan  2 18:13:48 EST 2012
 * End  : Mon Jan  2 18:33:41 EST 2012
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
#include <queue>

using namespace std;

struct compare
{
	bool operator () ( const int& l, const int& r )
	{
		return l>r;
	}
};
int main ()
{
	int N;
	while( cin >> N )
	{
		if( N == 0 )
			break;
		priority_queue<int,vector<int>,compare> nums;
		int temp;
		for( int i=0; i<N; ++i )
		{
			cin >> temp;
			nums.push( temp );
		}
		int totalCost = 0;
		while( nums.size() >= 2 )
		{
			int a = nums.top();
			nums.pop();
			int b = nums.top();
			nums.pop();
			int c = a+b;
			totalCost += c;
			nums.push( c );
		}
		cout << totalCost << endl;
	}
}
