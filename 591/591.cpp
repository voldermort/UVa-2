/* Name: Alex Velazquez
 * Start Date: September 16, 2011 @ 11:16PM
 * End Date:   September 16, 2011 @ 11:26PM
 * Purpose: To solve the UVa problem "591 - Box of Bricks"
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=99&page=show_problem&problem=532
 * */
#include <iostream>

using namespace std;

int main ()
{
	int N;
	int k=1;
	while (cin >> N)
	{
		if (N == 0)
			break;
		int A[N];
		int total=0;
		int minMoves=0;
		for (int i=0;i<N;++i)
		{
			cin >> A[i];
			total += A[i];
		}
		for (int i=0;i<N;++i)
			if (A[i] > total/N)
				minMoves += A[i]-total/N;
		cout << "Set #" << k << endl;
		cout << "The minimum number of moves is " << minMoves << "." << endl << endl;
		++k;
	}
}
