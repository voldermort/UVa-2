/* Alex Velazquez
 * Start: Sun Dec 11 22:47:09 EST 2011
 * End  : Sun Dec 11 22:53:26 EST 2011
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
		if( line[0] == '*' )
			break;
		stringstream ss( line );
		string token;
		bool tautogram = true;
		ss >> token;
		char firstChar = ( token[0] >=65 && token[0] <= 90 )?char(token[0]+32):token[0];
		while( ss >> token )
		{
			if( !(token[0] == firstChar || char(token[0]+32) == firstChar) )
			{
				tautogram = false;
				break;
			}
		}
		if( tautogram )
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}
