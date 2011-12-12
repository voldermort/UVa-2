/* Alex Velazquez
 * Start: Sun Dec 11 23:00:49 EST 2011
 * End  : Sun Dec 11 23:08:21 EST 2011
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
	while( cin >> line )
	{
		if( line[0] == '*' )
			break;
		stringstream ss( line );
		string token;
		int correctDuration = 0;
		while( getline( ss, token, '/' ) )
		{
			int size = token.size();
			int c = 0;
			for( int i=0; i<size; ++i )
			{
				if(      token[i] == 'W' ) c += 64;
				else if( token[i] == 'H' ) c += 32;
				else if( token[i] == 'Q' ) c += 16;
				else if( token[i] == 'E' ) c += 8;
				else if( token[i] == 'S' ) c += 4;
				else if( token[i] == 'T' ) c += 2;
				else if( token[i] == 'X' ) c += 1;
			}
			if( c == 64 )
				correctDuration++;
		} 
		cout << correctDuration << endl;
	}
}
