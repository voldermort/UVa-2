/* Alex Velazquez
 * Start: Tue Jan  3 23:37:59 EST 2012
 * End  : Tue Jan  3 23:47:37 EST 2012
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
	int N;
	while( cin >> N )
	{
		vector<int> books( N );
		for( int i=0; i<N; ++i )
			cin >> books[i];
		int M;
		cin >> M;
		sort( books.begin(), books.end() );
		int a, b;
		vector<int>::iterator it;
		for( int i=0; i<N; ++i )
		{
			if( books[i] > M/2 )
				break;
			it = find( books.begin(), books.end(), M-books[i] );
			if( it != books.end() )
			{
				a = books[i];
				b = M-books[i];
			}
		}
		cout << "Peter should buy books whose prices are " << a << " and " << b << ".";
		cout << "\n\n";
	}
}
