/* Alex Velazquez
 * Start: Sun Nov 27 18:06:56 EST 2011
 * End  : Sun Nov 27 18:23:58 EST 2011
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

using namespace std;

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int S, D;
		cin >> S >> D;
		// x+y = S && ( x-y = D || y-x = D )
		// Case 1: x+y=S && x-y=D
		//		x=S-y && x=D+y
		//		S-y=D+y => 2y = S-D => y=(S-D)/2
		// Case 2: x+y=S && y-x=D
		//		x=S-y && x=y-D
		//		S-y=y-D => 2y=S+D => y=(S+D)/2
		// ex. S=40, D=20
		//	y=20/2=10 or y=60/2=30
		//  => x=30 or x=10
		// ex2. S=20, D=40
		//  y=-20/2=-10 (impossible) or y=60/2=30 => x=20-30=-10 (impossible)
		if( S < D  || S < 0 || D < 0)
		{
			cout << "impossible" << endl;
		}
		else
		{
			int S1, S2;
			S1 = (S+D)/2;
			S2 = S-S1;
			if( S1+S2 == S && ( S1-S2 == D || S2-S1 == D ) )
			{
				if( S1 > S2 )
					cout << S1 << " " << S2 << endl;
				else
					cout << S2 << " " << S1 << endl;
			}
			else
				cout << "impossible" << endl;
		}
	}
}
