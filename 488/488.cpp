/* Name: Alex Velazquez
 * Start Date: August 21, 2011 @ 12:19PM
 * End Date: ???????
 * Purpose: To solve the problem #488 (Triangle Wave) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=429
 * */

#include <iostream>

using namespace std;

string createWave (int h)
{
	string S="";
	for (int i=0;i<h;++i)
		S += char(h+48);
	return S;
}

string triWave (int height)
{
	string S = createWave(height);
	for (int i=height-1;i>=1;--i)
	{
		S = createWave(i) + "\n" + S + "\n" + createWave(i);
	}
	return S;
} 

int main ()
{
	int T;
	cin >> T;
	int A, F;
	for (int i=0;i<T;++i)
	{
		cin >> A >> F;
		for (int j=0;j<F;++j)
		{
			cout << triWave(A) << endl << ((j != F-1)?"\n":"");
		}
		cout << ((i != T-1)?"\n":"");
	}
}
