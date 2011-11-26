/* Alex Velazquez
 * Start: November 25, 2011 @ 07:53PM
 * End  : November 25, 2011 @ 07:58PM
*/

#include <iostream>
#include <sstream>

using namespace std;

int main ()
{
	string line;
	int q = 0;
	while( getline( cin, line ) )
	{
		int size = line.size();
		for( int i=0; i<size; ++i )
		{
			if( line[i] == '"' )
			{
				cout << (( q%2 == 0 ) ? "``": "''");
				++q;
			}
			else
				cout << line[i];
		}
		cout << endl;
	}
}
