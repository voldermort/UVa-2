/* Alex Velazquez
 * Start: Sat Dec  3 17:34:04 EST 2011
 * End  : Sat Dec  3 17:50:26 EST 2011
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

int GCD( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main ()
{
	int N, K;
	while( cin >> N >> K )
	{
		if( N == 0 && K == 0 )
			break;
		if( N == K )
		{
			cout << 1 << endl;
			continue;
		}
		if( N-K < K )
			K = N-K;
		vector<int> numerator, denominator;
		for( int i=N; i>=N-K+1; --i )
			numerator.push_back( i );
		for( int i=K; i>=2; --i )
			denominator.push_back( i );
		int sizeD = denominator.size(), sizeN = numerator.size();
		for( int i=0; i<sizeD; ++i )
		{
			for( int j=0; j<sizeN; ++j )
			{
				int div = GCD( denominator[i], numerator[j] );
				if( div > 1 )
				{
					denominator[i] /= div;
					numerator[j] /= div;
				}
				if( denominator[i] == 1 )
					break;
			}
		}
		int answer = 1;
		for( int i=0; i<sizeN; ++i )
			answer *= numerator[i];
		cout << answer << endl;
	}
}
