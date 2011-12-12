/* Alex Velazquez
 * Start: Sun Dec 11 22:41:05 EST 2011
 * End  : Sun Dec 11 22:44:54 EST 2011
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
	int i = 1;
	while( cin >> line )
	{
		if( line[0] == '#' )
			break;
		cout << "Case " << i++ << ": ";
		if( line.compare( "HELLO" ) == 0 )
		{
			cout << "ENGLISH" << endl;
		} 
		else if ( line.compare( "HOLA" ) == 0  )
		{
			cout << "SPANISH" << endl;
		}
		else if ( line.compare( "HALLO" ) == 0  )
		{
			cout << "GERMAN" << endl;
		}
		else if ( line.compare( "BONJOUR" ) == 0  )
		{
			cout << "FRENCH" << endl;
		}
		else if ( line.compare( "CIAO" ) == 0  )
		{
			cout << "ITALIAN" << endl;
		}
		else if ( line.compare( "ZDRAVSTVUJTE" ) == 0  )
		{
			cout << "RUSSIAN" << endl;
		}
		else
		{
			cout << "UNKNOWN" << endl;
		}
	}
}
