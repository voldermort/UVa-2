/* Alex Velazquez
 * Start: Mon Jan  2 18:40:03 EST 2012
 * End  : Mon Jan  2 18:56:16 EST 2012
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
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main ()
{
	int N;
	while( cin >> N )
	{
		stack<int> st;
		deque<int> qu;
		priority_queue<int> pq;
		bool isStack = true, isQueue = true, isPQ = true;
		for( int i=0; i<N; ++i )
		{
			int op, n;
			cin >> op >> n;
			if( op == 1 )
			{
				st.push( n );
				qu.push_back( n );
				pq.push( n );
			}
			else
			{
				if( st.size() == 0 )
				{
					isStack = false;
					isQueue = false;
					isPQ = false;
					continue;
				}
				int stR = st.top();
				int quR = qu.front();
				int pqR = pq.top();
				if( n != stR ) isStack = false;
				if( n != quR ) isQueue = false;
				if( n != pqR ) isPQ = false;
				st.pop();
				qu.pop_front();
				pq.pop();
			}
		}
		int summ = ((isStack)?1:0)+((isQueue)?1:0)+((isPQ)?1:0);
		if( summ == 0 )
			cout << "impossible" << endl;
		else if( summ > 1 )
			cout << "not sure" << endl;
		else
		{
			if( isStack ) cout << "stack" << endl;
			if( isQueue ) cout << "queue" << endl;
			if( isPQ 	) cout << "priority queue" << endl;
		}
	}
}
