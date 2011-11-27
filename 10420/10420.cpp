/* Alex Velazquez
 * Start: Sun Nov 27 17:53:37 EST 2011
 * End  : Sun Nov 27 18:04:21 EST 2011
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
	map<string,int> M;
	for( int i=0; i<T; ++i )
	{
		string line;
		if( i == 0 )
			cin.ignore();
		getline( cin, line );
		int size = line.size();
		string country;
		for( int j=0; j<size; ++j )
		{
			if( line[j] == ' ' )
			{
				country = line.substr( 0, j );
				++M[country];
				break;
			}
		}
	}
	for( map<string,int>::iterator it=M.begin(); it!=M.end(); ++it )
		cout << it->first << " " << it->second << endl;
}
