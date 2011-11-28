/* Alex Velazquez
 * Start: Sun Nov 27 20:28:09 EST 2011
 * End  : Sun Nov 27 20:37:20 EST 2011
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
	string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string line;
	while( getline( cin, line ) )
	{
		int size = line.size();
		for( int i=0; i<size; ++i )
		{
			if( line[i] == ' ' )
				cout << ' ';
			else
			{
				cout << keyboard[(int)keyboard.find(line[i])-1];
			}
		}
		cout << endl;
	}
}
