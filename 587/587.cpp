/* Name: Alex Velazquez
 * Start Date: September 26, 2011 @ 09:00PM
 * End Date:   September 26, 2011 @ 09:31PM
 * Purpose: To solve the UVa problem 587 - "There's treasure everywhere!"
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int main ()
{
	string line, token;
	int d;
	int i=1;
	char dir[2];
	while (getline(cin,line))
	{
		double x=0.0,y=0.0;
		if (line.compare("END") == 0)
			break;
		stringstream ss(line);
		while (getline(ss,token,','))
		{
			sscanf(token.c_str(),"%d%s",&d,dir);
			//cout << "token: " << token << " " << d << " " << dir << endl;
			if (strcmp(dir,"N") == 0 || strcmp(dir,"N.") == 0) y += d;
			if (strcmp(dir,"S") == 0 || strcmp(dir,"S.") == 0) y -= d;
			if (strcmp(dir,"E") == 0 || strcmp(dir,"E.") == 0) x += d;
			if (strcmp(dir,"W") == 0 || strcmp(dir,"W.") == 0) x -= d;
			if (strcmp(dir,"NW") == 0 || strcmp(dir,"NW.") == 0)
			{
				x -= sqrt(d*d/(double)2);
				y += sqrt(d*d/(double)2);
			} 
			if (strcmp(dir,"NE") == 0 || strcmp(dir,"NE.") == 0)
			{
				x += sqrt(d*d/(double)2);
				y += sqrt(d*d/(double)2);
			}
			if (strcmp(dir,"SE") == 0 || strcmp(dir,"SE.") == 0)
			{
				x += sqrt(d*d/(double)2);
				y -= sqrt(d*d/(double)2);
			}
			if (strcmp(dir,"SW") == 0 || strcmp(dir,"SW.") == 0) 
			{
				x -= sqrt(d*d/(double)2);
				y -= sqrt(d*d/(double)2);
			}
		}
		cout << "Map #" << i++ << endl;
		cout << "The treasure is located at (" << setprecision(3) << fixed << x << "," << y << ")." << endl;
		cout << "The distance to the treasure is " << sqrt(x*x+y*y) << "." << endl;
		cout << endl;
	}
}

