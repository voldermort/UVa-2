/* Alex Velazquez
 * Start: Wed Dec 7 23:19:11 EST 2011
 * End  : Wed Dec  7 23:35:51 EST 2011
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
	int N;
	while( cin >> N )
	{
		if( N == 2 )
		{
			cout << "00" << endl;
			cout << "01" << endl;
			cout << "81" << endl;
		}
		else if( N == 4 )
		{
			cout << "0000" << endl;
			cout << "0001" << endl;
			cout << "2025" << endl;
			cout << "3025" << endl;
			cout << "9801" << endl;
		}
		else if( N == 6 )
		{
			cout << "000000" << endl;
			cout << "000001" << endl;
			cout << "088209" << endl;
			cout << "494209" << endl;
			cout << "998001" << endl;
		}
		else
		{
			cout << "00000000" << endl;
			cout << "00000001" << endl;
			cout << "04941729" << endl;
			cout << "07441984" << endl;
			cout << "24502500" << endl;
			cout << "25502500" << endl;
			cout << "52881984" << endl;
			cout << "60481729" << endl;
			cout << "99980001" << endl;			
		}
		/*
		map<int,int> maxx;
		maxx[2] = 10; maxx[4] = 100; maxx[6] = 1000; maxx[8] = 10000;
		cout << N << "!!!!" << endl;
		for( int i=0; i<maxx[N]; ++i )
		{
			for( int j=0; j<maxx[N]; ++j )
			{
				if( (i+j)*(i+j) == i*maxx[N]+j )
				{
					cout << i << j << endl;
				}
			}
		}
		*/
	}
}
