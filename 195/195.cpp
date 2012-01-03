/* Alex Velazquez
 * Start: Mon Jan  2 19:30:13 EST 2012
 * End  : Mon Jan  2 19:45:45 EST 2012
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

int F( char x )
{
	int X = x;
	if( X >= 65 && X <= 90 ) //uppercase letter
		return 2*(X-65);
	else
		return 2*(X-97)+1;
}

bool compareFunction( char a, char b )
{
	return (F(a)<F(b));
}

int main ()
{
	int N;
	cin >> N;
	for( int i=0; i<N; ++i )
	{
		string S;
		cin >> S;
		sort( S.begin(), S.end(), compareFunction );
		do
		{
			cout << S << endl;
		} while( next_permutation( S.begin(), S.end(), compareFunction ) );
	}
}
