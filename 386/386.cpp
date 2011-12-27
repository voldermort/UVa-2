/* Alex Velazquez
 * Start: Tue Dec 27 15:43:03 EST 2011
 * End  : Tue Dec 27 17:02:10 EST 2011
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

struct CubeTriples {
	int a;
	int b;
	int c;
	int d;
	CubeTriples( int A, int B, int C, int D ) : a(A), b(B), c(C), d(D) {}
};

bool operator < ( CubeTriples const& X, CubeTriples const& Y )
{
	if( X.a < Y.a )			return true;
	else if( X.a > Y.a ) 	return false;
	else
	{
		if( X.b < Y.b ) 	return true;
		else if( X.b > Y.b )return false;
		else
		{
			if( X.c < Y.c ) return true;
			else if( X.c > Y.c ) return false;
			else
			{
				if( X.d < Y.d ) return true;
				else return false;
			}
		} 
	}
}

int main ()
{
	vector<int> cubes( 201 );
	map<int,bool> isCube;
	for( int a=2; a<=200; ++a )
	{
		cubes[a] = a*a*a;
		isCube[cubes[a]] = true;
	}
	set<CubeTriples> S;
	for( int b=2; b<201; ++b )
	{
		for( int c=b; c<201; ++c )
		{
			if( cubes[b]+cubes[c]>cubes[200] )
				break;
			for( int d=c; d<201; ++d )
			{
				int R = cubes[b]+cubes[c]+cubes[d]; 
				if( R > cubes[200] )
					break;
				if( isCube[R] )
				{
					S.insert( CubeTriples( pow(R,1/3.0)+1, b, c, d ) ); 
				}
			}
		}
	}
	for( set<CubeTriples>::iterator it=S.begin(); it!=S.end(); ++it )
	{
		cout << "Cube = " << it->a;
		cout << ", Triple = (" << it->b << "," << it->c << ",";
		cout << it->d << ")" << endl;
	}
}
