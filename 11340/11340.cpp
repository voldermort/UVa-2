/* Alex Velazquez
 * Start: Tue Dec 27 14:24:34 EST 2011
 * End  : Tue Dec 27 14:34:41 EST 2011
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
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int K;
		cin >> K;
		map<char,int> M;
		for( int j=0; j<K; ++j )
		{
			char l;
			int v;
			cin >> l >> v;
			M[l] = v;
		}
		int N;
		cin >> N;
		string S;
		int total = 0;
		for( int j=0; j<N; ++j )
		{
			if( j == 0 )
				cin.ignore();
			getline( cin, S );
			//cout << S << endl;
			int s = S.size();
			for( int k=0; k<s; ++k )
			{
				total += M[S[k]];
			}
		}
		cout << total/100 << "." << ((total%100 < 10 )?"0":"") << total%100;
		cout << "$" << endl;
	}
}
