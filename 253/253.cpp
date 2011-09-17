/* Name: Alex Velazquez
 * Start Date: September 16, 2011 @ 10:13PM
 * End Date:   September 16, 2011 @ 10:37PM
 * Purpose: To solve the UVa problem "253 - Cube painting"
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=99&page=show_problem&problem=189
 * */
#include <iostream>
#include <string>
#include <set>

using namespace std;

string rotateDown (string x)
{
	string newX = "";
	newX += x[4]; newX += x[0]; newX += x[2]; 
	newX += x[3]; newX += x[5]; newX += x[1];
	return newX;
}

string rotateRight (string x)
{
	string newX = "";
	newX += x[0]; newX += x[2]; newX += x[4]; 
	newX += x[1]; newX += x[3]; newX += x[5];
	return newX;
}

string rotateSide (string x)
{
	string newX = "";
	newX += x[2]; newX += x[1]; newX += x[5]; 
	newX += x[0]; newX += x[4]; newX += x[3];
	return newX;
}

bool areEqual (string cube1, string cube2)
{
	int j = 0;
	/* generate all possible combinations of cube1 
	* and then check if any of them is equal to 
	* cube2 */
	do 
	{
		for (int i=0;i<4;++i)
		{
			string rotatedCube = rotateRight(cube1);
			if (rotatedCube.compare(cube2) == 0) // equal!
				return true;
			cube1 = rotatedCube;	
		}
		if (j%2==0)
			cube1 = rotateDown(cube1);
		else
			cube1 = rotateSide(cube1);
		++j;
	} while (j<6);
	return false;
}

int main ()
{
	string word;
	string cube1, cube2;
	while (cin >> word)
	{
		cube1 = word.substr(0,6);
		cube2 = word.substr(6,6);
		if (areEqual(cube1,cube2))
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
	}
}
