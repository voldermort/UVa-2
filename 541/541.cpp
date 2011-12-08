/* Alex Velazquez
 * Start: Wed Dec  7 23:03:53 EST 2011
 * End  : Wed Dec  7 23:11:59 EST 2011
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
	while( cin >> N )
	{
		if( N == 0 )
			break;
		vector<int> H( N ), V( N );
		int t;
		for( int i=0; i<N; ++i )
		{
			for( int j=0; j<N; ++j )
			{
				cin >> t;
				V[j] += t;
				H[i] += t;
			}
		}
		vector<int> changeBitV, changeBitH;
		for( int i=0; i<N; ++i )
		{
			if( H[i]%2 == 1 ) // odd row
				changeBitH.push_back( i+1 );
			if( V[i]%2 == 1 ) // odd row
				changeBitV.push_back( i+1 );
		}
		int sizeH = changeBitH.size();
		int sizeV = changeBitV.size();
		if( sizeH == 0 && sizeV == 0 )
			cout << "OK" << endl;
		else if( sizeH == 1 && sizeV == 1 )
			cout << "Change bit (" << changeBitH[0] << "," << changeBitV[0] << ")" << endl;
		else
			cout << "Corrupt" << endl;
	}
}
