/* Name: Alex Velazquez
 * Start Date: September 17, 2011 @ 12:58PM
 * End Date:   September 16, 2011 @ 01:25PM
 * Purpose: To solve the UVa problem "573 - The Snail"
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=99&page=show_problem&problem=514
 * */
#include <iostream>

using namespace std;

int main ()
{
	double H, U, D, F;
	double height, slide;
	int day;
	while (cin >> H >> U >> D >> F)
	{
		if (H == 0)
			break;
		height=0.0;
		day=1;
		slide = U*F/100.0;
		while (1)
		{
			if (U > 0.0)
				height += U;
			if (height > H)
			{
				cout << "success on day " << day << endl;
				break;
			}
			U -= slide;
			height -= D;
			if (height < 0.0)
			{
				cout << "failure on day " << day << endl;
				break;
			}
			++day;
		}
	}
}
