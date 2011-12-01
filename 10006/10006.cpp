/* Alex Velazquez
 * Start: Wed Nov 30 21:48:56 EST 2011
 * End  : Wed Nov 30 22:56:13 EST 2011
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

#define DEBUG 0

typedef long long LL;

LL square( LL x )
{
	return x*x;
}

LL F( LL a, LL n, LL &N)
{
	if( n == 0LL )
		return 1;
	else if( n == 1LL )
		return a%N;
	if( n%2LL == 0LL )
	{
		LL A = F( a, n/2LL, N );
		A %= N;
		LL B = square( A );
		B %= N;
		#if DEBUG
			cout << "A: " << A << ". B: " << B << endl;
		#endif
		return B;
	}
	else
	{
		LL A =  F( a, n/2LL, N );
		A %= N;
		LL B = square( A );
		B %= N;
		LL C = B*a;
		C %= N;
		#if DEBUG
			cout << "A: " << A << ". B: " << B << ". C: " << C << endl;
		#endif
		return C;
	}
}

bool isCarmichael( LL N )
{
	for( LL i=1LL; i<N; ++i )
	{
		#if DEBUG
			cout << i << " " << F( i, N, N ) << endl;
		#endif
		if( i != F( i, N, N ) )
			return false;
	}
	return true;
}

bool isPrime( LL N )
{
	for( LL i=2LL; i*i<=N; ++i )
		if( N%i == 0 )
			return false;
	return true;
}

int main ()
{
	int N;
	while( cin >> N )
	{
		if( N == 0 )
			break;
		#if DEBUG
			if( !isPrime( N ) )
				cout << N << " is not prime" << endl;
		#endif
		if( !isPrime( N ) )
			if( isCarmichael( N ) )
				cout << "The number " << N << " is a Carmichael number." << endl;
			else
				cout << N << " is normal." << endl;
		else
			cout << N << " is normal." << endl;
	}
}
