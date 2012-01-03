/* Alex Velazquez
 * Start: Mon Jan  2 20:30:01 EST 2012
 * End  : Mon Jan  2 21:16:47 EST 2012
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
	/*
		oxoxoxoxoxox
		xoxoxoxoxoxo
		oxoxoxoxoxox
		xoxoxoxoxoxo
		oxoxoxoxoxox
		xoxoxoxoxoxo
		oxoxoxoxoxox
		xoxoxox|oxoxo
		oxoxoxo|xoxox
		xoxoxox|oxoxo
		oxoxoxo|xoxox
		xoxoxox|oxoxo
		oxoxoxo|xoxox
		=> 13 12 0
		=> result: 15
		12-7=5 columns we need to check
		   lastCol = 5/2     = 2 valid chessboards 
		2ndlastCol = (5+1)/2 = 3 valid chessboards
		How many    lastCols are there? => ceil((13-7)/2)  = 3
		How many 2ndlastCols are there? => ceil((12-7)/2)  = 3 
		THen 2*3 + 3*3 = 6+9 = 15
	 */
	int m, n, c;
	while( cin >> m >> n >> c )
	{
		if( m+n+c == 0 )
			break;
		int cols = n-7;
		int lastCol = (cols+((c==1)?1:0))/2;
		int sLastCol= (cols+((c==1)?0:1))/2;
		cout << ((((m-7)%2==0)?(m-7)/2:(m-7)/2+1))*lastCol+((((m-8)%2==0)?(m-8)/2:(m-8)/2+1))*sLastCol << endl;
	}
}
