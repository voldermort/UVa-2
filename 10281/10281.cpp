/* Alex Velazquez
 * Start: Mon Nov 28 21:03:36 EST 2011
 * End  : Mon Nov 28 21:46:53 EST 2011
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

int toSecs( string time )
{
	int hours, min, sec;
	stringstream t( time );
	t >> hours;
	t.ignore();
	t >>  min; 
	t.ignore();
	t >> sec;
	return 3600*hours+60*min+sec; 
}

int main ()
{
	string line;
	double distanceTravelled = 0;
	double speed;
	int currTime = 0;
	int prevTime = -1;
	while( getline( cin, line ) )
	{
		if( line.find( ' ' ) != string::npos ) // two tokens
		{
			string time;
			stringstream ss( line );
			ss >> time; 
			currTime = toSecs( time );
			//cout << "currTime: " << currTime << endl;
			if( prevTime != -1 )
			{
				distanceTravelled += speed*(currTime-prevTime)/3600;
			}
			ss >> speed;
			prevTime = currTime;
		}
		else
		{
			cout << line << " ";
			currTime = toSecs( line );
			//cout << "currTime: " << currTime << endl;
			distanceTravelled += speed*(currTime-prevTime)/3600;
			printf( "%.2lf km\n", distanceTravelled );
			//cout << distanceTravelled << " " << "km" << endl;
			prevTime = currTime;
		}
		//cout << "CURRENT TOTAL: " << distanceTravelled << endl;
	}
}
