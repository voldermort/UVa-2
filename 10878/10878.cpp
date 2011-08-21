/* Name: Alex Velazquez
 * Start Date: August 21, 2011 @ 06:00PM
 * End Date:   August 21, 2011 @ 06:17PM
 * Purpose: To solve the problem #10878 (Decode the Tape) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=96&page=show_problem&problem=1819
 * */

#include <iostream>
#include <cmath>

using namespace std;

int decode (string s)
{
	if (s == "___________") return -1;
	int letter=0;
	/* 01234567891 */
	/* | o   .  o| */
	int d=0;
	for (int i=9;i>=1;--i)
	{
		if (s[i] == '.') d = 1;
		if (s[i] == 'o')
		{
			//cout << pow(2,9-i-d) << endl;
			letter += pow(2,9-i-d);
		}
	}
	return letter;
}

int main ()
{
	string s;
	int l;
	while (getline(cin,s))
	{
		l = decode(s);
		if (l != -1)
		{
			cout << char(l) ;
		}
	}
}
