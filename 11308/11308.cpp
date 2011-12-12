/* Alex Velazquez
 * Start: Sun Dec 11 21:45:47 EST 2011
 * End  : Sun Dec 11 22:29:54 EST 2011
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

struct Cake {
	string name;
	int cost;
	Cake( string s, int c ) : name( s ), cost( c ) {}
};

bool operator < (Cake const& A, Cake const& B )
{
	if( A.cost < B.cost )
		return true;
	else if (A.cost > B.cost )
		return false;
	else
	{
		if( A.name.compare( B.name ) < 0 )
			return true;
		else
			return false;
	}
}

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		if( i == 0 )
			cin.ignore();
		string recipeName;
		getline( cin, recipeName );
		string info;
		getline( cin, info );
		#if DEBUG
			cout << "recipeName: " << recipeName << endl;
			//cout << "info: " << info << endl;
		#endif
		stringstream ss( info );
		int m, n, b;
		ss >> m >> n >> b;
		#if DEBUG
			cout << "m: " << m << ". n: " << n << ". b: " << b << endl;
		#endif
		
		map<string, int> ingredient_cost;
		set<Cake> allowed_recipes;
		string s;
		int c;
		string line;
		for( int j=0; j<m; ++j )
		{
			getline( cin, line );
			stringstream sLine( line );
			sLine >> s >> c;
			#if DEBUG
				cout << "s: " << s << ". c: " << c << endl;
			#endif
			ingredient_cost[s] = c;
		}
		
		for( int j=0; j<n; ++j )
		{
			string cakeName, iLine;
			getline( cin, cakeName );
			int numIngredients;
			getline( cin, iLine );
			stringstream siLine( iLine );
			siLine >> numIngredients;
			int totalCost = 0;
			#if DEBUG
				cout << "cakeName: " << cakeName << endl;
				cout << "numIngredients: " << numIngredients << endl;
			#endif
			for( int k=0; k<numIngredients; ++k )
			{
				getline( cin, line );
				stringstream ssLine( line );
				ssLine >> s >> c;
				totalCost += c*ingredient_cost[s];
			}
			#if DEBUG
				cout << "totalCost: " << totalCost << endl;
			#endif
			if( totalCost <= b )
				allowed_recipes.insert( Cake( cakeName, totalCost ) );
		}
		int size = recipeName.size();
		for( int l=0; l<size; ++l )
		{
			if( recipeName[l] >= 97 && recipeName[l] <= 122 )
				cout << char(recipeName[l]-32);
			else
				cout << recipeName[l];
		}
		cout << endl;
		if( allowed_recipes.size() == 0 )
		{
			cout << "Too expensive!" << endl << endl;
			continue;
		}
		for( set<Cake>::iterator it = allowed_recipes.begin();
								 it != allowed_recipes.end();
								 ++it )
		{
			cout << it->name << endl;
		}
		cout << endl;
	}
}
