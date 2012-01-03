/* Alex Velazquez
 * Start: Mon Jan  2 19:16:29 EST 2012
 * End  : Mon Jan  2 19:22:47 EST 2012
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
	int numPeople, budget, numHotels, numWeeks;
	while( cin >> numPeople >> budget >> numHotels >> numWeeks )
	{
		int cost = 2147000000;
		int costPerson;
		vector<int> costWeek( numWeeks );
		for( int i=0; i<numHotels; ++i )
		{
			cin >> costPerson;
			for( int j=0; j<numWeeks; ++j )
			{	
				cin >> costWeek[j];
				if( costWeek[j] >= numPeople )
				{
					int totalCost = numPeople*costPerson;
					if( totalCost <= budget && totalCost < cost )
						cost = totalCost;
				}
			}
		}
		if( cost == 2147000000 )
			cout << "stay home" << endl;
		else
			cout << cost << endl;
	}
}
