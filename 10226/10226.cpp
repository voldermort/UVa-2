/* Alex Velazquez
 * Start: Sun Dec 11 02:25:47 EST 2011
 * End  : Sun Dec 11 02:47:45 EST 2011
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
	string tree;
	int j = 0;
	for( int i=0; i<T; ++i )
	{
		if( i != 0 )
			cout << endl;
		map<string,int> M;
		double numTrees = 0.0;
		while( getline( cin, tree ) )
		{
			if( j == 0 )
			{
				cin.ignore();
			}
			++j;	
			if( tree == "" )
			{
				//cout << "WTF. j: " <<  j << endl;
				if( j > 1 )
				{	
					//cout << "breaking..." << endl;
					break;
				}
			}
			else
			{
				//cout << "tree: " << tree << endl;
				++M[tree];
				numTrees += 1.0;
			}
		}
		//cout << "numTrees: " << numTrees << endl;
		for( map<string,int>::iterator it=M.begin(); it!=M.end(); ++it )
		{
			cout << it->first << " "  << fixed << setprecision(4) << (it->second/numTrees)*100.0 << endl;
		}
	}
}
