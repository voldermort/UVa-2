/* Alex Velazquez
 * Start: Wed Dec  7 22:46:03 EST 2011
 * End  : Wed Dec  7 22:59:24 EST 2011
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
	for( int j=0; j<T; ++j )
	{
		int N, P, t;
		cin >> N;
		vector<bool> days(N+1);
		cin >> P;
		for( int i=0; i<P; ++i )
		{
			cin >> t;
			int m = 1;
			while( t*m <= N )
				days[t*m++] = true;
		}
		int dayMissed = 0;
		for( int i=1; i<=N; ++i )
		{
			if( days[i] && i%7 != 0 && i%7 != 6)
			{
				//cout << i << endl;
				++dayMissed;
			}
		}
		cout << dayMissed << endl;
	}
}
