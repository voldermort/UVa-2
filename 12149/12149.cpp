/* Alex Velazquez
 * Start: Sat Dec 10 20:42:30 EST 2011
 * End  : Sat Dec 10 20:46:12 EST 2011
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
		if( N == 0 )
			break;
		int t = 0;
		for( int i=1; i<=N; ++i )
			t += i*i;
		cout << t << endl;
	}
}
