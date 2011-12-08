/* Alex Velazquez
 * Start: Wed Dec  7 22:11:43 EST 2011
 * End  : Wed Dec  7 22:15:00 EST 2011
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
	for( int i=0; i<T; ++i )
	{
		int a, b;
		cin >> a >> b;
		if( a < b ) cout << "<" << endl;
		else if ( a > b ) cout << ">" << endl;
		else cout << "=" << endl;
	}

}
