/* Alex Velazquez
 * Start: Tue Nov 29 19:57:10 EST 2011
 * End  : Tue Nov 29 20:14:19 EST 2011
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
	int N, K;
	while( cin >> N >> K )
	{
		int A = N;
		int butts = N;
		while( butts >= K )
		{
			N = butts/K;
			A += N;
			butts = N + butts%K;
		}
		cout << A << endl;
	}
}
