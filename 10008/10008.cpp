/* Alex Velazquez
 * Start: Fri Dec  2 23:43:49 EST 2011
 * End  : Sat Dec  3 00:01:12 EST 2011
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

#define DEBUG 0

using namespace std;
struct Letter {
	int c;
	int o;
	Letter( int c_, char o_ ) : c( c_ ), o( o_ ) {}
};

bool operator < ( Letter const& A, Letter const& B )
{
	if( A.o > B.o )
		return true;
	else if( A.o < B.o )
		return false;
	else
	{
		if( A.c < B.c )
			return true;
		else
			return false;
	}
}
int main ()
{
	int T;
	cin >> T;
	map<int,int> M;
	for( int i=0; i<T; ++i )
	{
		string line;
		if( i == 0 )
			cin.ignore();
		getline( cin, line );
		#if DEBUG
			cout << "line: " << line << endl;
		#endif
		int size = line.size();
		for( int j=0; j<size; ++j )
		{
			int c = line[j];
			#if DEBUG
				cout << c << " " << line[j] << endl;
			#endif
			if( c >= 65 && c<=90 ) // uppercase letter!
				++M[c];
			else if( c >= 97 && c<=122 ) // lowercase letter!
			{
				#if DEBUG
					cout << c-32 << endl;
				#endif
				++M[c-32];
			}
		}
	}
	set<Letter> l;
	for( map<int,int>::iterator it=M.begin(); it!=M.end(); ++it )
	{
		l.insert( Letter( it->first, it->second ) );
	}
	for( set<Letter>::iterator it=l.begin(); it!=l.end(); ++it )
	{
		cout << char(it->c) << " " << it->o << endl;
	}
}
