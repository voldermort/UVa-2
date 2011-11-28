/* Alex Velazquez
 * Start: Sun Nov 27 20:58:50 EST 2011
 * End  : Sun Nov 27 22:56:37 EST 2011
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
	int D, O, C;
	int seq = 1;
	while( cin >> D >> O >> C )
	{
		if( D == C && C == O && O == 0 )
			break;
		cout << "Sequence "<< seq++ << endl;
		vector<int> devices, operations;
		int t;
		for( int i=0; i<D; ++i )
		{
			cin >> t;
			devices.push_back( t );
		}
		for( int i=0; i<O; ++i )
		{
			cin >> t;
			operations.push_back( t );
		}
		int powerC = 0;
		vector<bool> dState( D, false );
		bool fuseBlown = false;
		int maximal = 0;
		for( int i=0; i<O; ++i )
		{
			if( dState[operations[i]-1] ) //if device is on
			{
				powerC -= devices[operations[i]-1];
				if( powerC > maximal ) maximal = powerC;
				dState[operations[i]-1] = false;
			}
			else // if device is off
			{
				powerC += devices[operations[i]-1];
				if( powerC > maximal ) maximal = powerC;
				if( powerC > C )
				{
					cout << "Fuse was blown." << endl;
					fuseBlown = true;
					break;
				}
				dState[operations[i]-1] = true;
			}
		}
		if( !fuseBlown )
		{
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << maximal;
			cout << " amperes." << endl;
		}
		cout << endl;
	}
}
