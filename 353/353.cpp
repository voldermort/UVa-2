/* Alex Velazquez
 * Start: Sat Dec 10 21:59:26 EST 2011
 * End  : Sat Dec 10 22:30:54 EST 2011
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
	string S;
	while( cin >> S )
	{
		int size = S.size();
		set<string> palindromes;
		// count odd size palindromes
		for( int i=0; i<size; ++i )
		{
			string X = S.substr( i, 1 );
			palindromes.insert( X );
			for( int j=1; j<=min(i,size-i-1); ++j )
			{
				if( S[i-j] == S[i+j] )
				{
					X.insert( 0, 1, S[i-j] );
					X.append( 1, S[i+j] );
					palindromes.insert( X );
					//cout << "i: " << i << ". j: " << j;
					//cout << ". min: " << min(i,size-i-1);
					//cout << ". X: " << X << endl;
				}
				else
					break;
			}
		}
		// count even size palindromes
		for( int i=0; i<size-1; ++i )
		{
			string X = S.substr( i, 2 );
			if( X[0] == X[1] )
				palindromes.insert( X );
			else
				continue;
			for( int j=1; j<=min(i,size-i-2); ++j )
			{
				if( S[i-j] == S[i+j+1] )
				{
					X.insert( 0, 1, S[i-j] );
					X.append( 1, S[i+j+1] );
					palindromes.insert( X );
					//cout << "i: " << i << ". j: " << j;
					//cout << ". min: " << min(i,size-i-1);
					//cout << ". X: " << X << endl;
				}
				else
					break;
			}
		}
		cout << "The string \'" << S << "\' contains " << palindromes.size() << " palindromes." << endl;
	}
}
