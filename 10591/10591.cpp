/* Alex Velazquez
 * Start: Thu Dec  1 19:40:58 EST 2011
 * End  : Thu Dec  1 20:19:04 EST 2011
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
#include <utility>

#define DEBUG 0

using namespace std;

int square( int N )
{
	return N*N;
}

int sumSquareDigits( int N )
{
	int S = 0;
	while( N >= 10 )
	{
		S += square((N%10));
		N /= 10;
	}
	return S+N*N;
}

int isHappy( int N, vector<int> &chain, map<int,int> &M )
{
	int s = N;
	#if DEBUG
		cout << N << endl;
	#endif
	chain.push_back( N );
	set<int> nums;
	nums.insert( N );
	N = sumSquareDigits( N );
	while( 1 )
	{
		pair<set<int>::iterator, bool> result = nums.insert( N );
		if( result.second == false )
			return 2;
		chain.push_back( N );
		#if DEBUG
			cout << N << " ";
		#endif
		if( M[N] == 1 )
			return 1;
		else if( M[N] == 2 )
			return 2;
		else
		{
			if( N == s )
				return 2;
			else if( N == 1 )
				return 1;
			else
				N = sumSquareDigits( N );
		}
	}
}

int main ()
{
	// calculate all happy/unhappy numbers less than
	// or equal to 729
	map<int,int> M;
	// M:
	// X -> 0 (not calculated yet)
	// X -> 1 (happy number)
	// X -> 2 (unhappy number)
	M[1] = 1;
	for( int i=2; i<=729; ++i )
	{
		if( M[i] == 0 ) 
		{
			vector<int> chain;
			int H = isHappy(i,chain,M);
			int size = chain.size(); 
			for( int k=0; k<size; ++k )
				M[chain[k]] = H;
		} 
	}
	int T;
	cin >> T;
	for( int i=1; i<=T; ++i )
	{
		int N;
		cin >> N;
		cout << "Case #" << i << ": " << N << " is a";
		int X = sumSquareDigits( N );
		if( M[X] == 1 )
			cout << " Happy number." << endl;
		else if( M[X] == 2 )
			cout << "n Unhappy number." << endl;
	}
}
