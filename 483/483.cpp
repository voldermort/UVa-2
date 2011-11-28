/* Alex Velazquez
 * Start: Sun Nov 27 20:39:14 EST 2011
 * End  : Sun Nov 27 20:45:51 EST 2011
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
	string line;
	while( getline( cin, line ) )
	{
		stringstream ss( line );
		string token;
		bool first = true;
		while( getline( ss, token, ' ' ) )
		{
			if( !first )
				cout << " ";
			first = false;
			// reverse each token
			int size = token.size();
			for( int i=size-1; i>=0; --i )
			{
				cout << token[i];
			}
		}
		cout << endl;
	}
}
