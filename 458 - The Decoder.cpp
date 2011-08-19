/* Name: Alex Velazquez
 * Date: August 18, 2011
 * Purpose: To solve the problem #458 (The Decoder) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=399
 * */

#include <iostream>

using namespace std;

int main ()
{
	string encodedString;
	while (1)
	{
		string decodedString="";
		if (cin >> encodedString)
		{
			for (int i=0;i<(int)encodedString.size();++i)
			{
				decodedString += char((int)encodedString[i]-7);
			}
			cout << decodedString << endl;
		}
		else
		{
			break;
		}
	}
}

