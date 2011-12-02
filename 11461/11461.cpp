/* Alex Velazquez
 * Start: Thu Dec  1 20:23:08 EST 2011
 * End  : Thu Dec  1 20:29:29 EST 2011
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
	// calculate all squares i^2 where
	// i < 317 (upper limit is 10000)
	vector<int> squares;
	for( int i=1; i<=316; ++i )
		squares.push_back( i*i );
	int size = squares.size();	
	int a, b;
	while( cin >> a >> b )
	{
		if( a == 0 && b == 0 )
			break;
		int counter = 0;
		for( int i=0; i<size; ++i )
		{
			if( squares[i] > b )
				break;
			if( squares[i] >= a && squares[i] <= b )
				++counter;
		}
		cout << counter << endl;
	}
}
