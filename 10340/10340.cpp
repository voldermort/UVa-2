/* Alex Velazquez
 * Start: Wed Dec 28 23:17:22 EST 2011
 * End  : Wed Dec 28 23:32:05 EST 2011
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
	string s, t;
	while( cin >> s >> t )
	{
		int sSize = s.size();
		int tSize = t.size();
		if( tSize < sSize )
		{
			cout << "No" << endl;
			continue;
		}
		else
		{
			int j = 0;
			bool found = true;
			int c = 0;
			for( int i=0; i<sSize && found; ++i )
			{
				while( 1 )
				{
					if( j >= tSize )
					{
						found = false;
						break;
					}
					if( s[i] != t[j] )
					{
						++j;
					}
					else
					{
						++c;
						++j;
						break;
					}
				}
			}
			if( c == sSize )
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}
