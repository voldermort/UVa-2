/* Alex Velazquez
 * Start: Fri Dec  2 23:10:22 EST 2011
 * End  : Fri Dec  2 23:20:13 EST 2011
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
#include <iomanip>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int N;
		cin >> N;
		vector<double> scores;
		int s;
		double total = 0;
		for( int j=0; j<N; ++j )
		{
			cin >> s;
			total += s;
			scores.push_back( s );
		}
		double avg = total/(double)N;
		double c = 0.0;
		for( vector<double>::iterator it=scores.begin(); it!=scores.end(); ++it )
		{
			if( *it > avg )
				c += 1.0;
		}
		double percentage = c/N*100.0;
		printf( "%.3f\%\n" , percentage );
	}
}
