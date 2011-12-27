/* Alex Velazquez
 * Start: Tue Dec 27 15:02:39 EST 2011
 * End  : Tue Dec 27 15:18:44 EST 2011
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

void isPerfect( int X )
{
	// count sum of factors
	int f = 1;
	int i=2;
	for( ; i*i<X; ++i )
	{
		if( X%i == 0 )
		{
			f += i;
			f += X/i;
		}
	}
	if( i*i == X )
		f += i;
	if( f == X )
		cout << "PERFECT" << endl;
	else if( f > X )
		cout << "ABUNDANT" << endl;
	else
		cout << "DEFICIENT" << endl;
}

int main ()
{
	int X;
	cout << "PERFECTION OUTPUT" << endl;
	while( cin >> X ) 
	{
		if( X == 0 )
		{
			cout << "END OF OUTPUT" << endl;
			break;
		}
		if( X < 10 )
			cout << "    ";
		else if( X < 100 )
			cout << "   ";
		else if( X < 1000 )
			cout << "  ";
		else if ( X < 10000 )
			cout << " ";
		cout << X;
		cout << "  ";
		if( X == 1 ) cout << "DEFICIENT" << endl;
		else isPerfect( X );
	}
}
