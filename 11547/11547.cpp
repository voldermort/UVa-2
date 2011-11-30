/* Alex Velazquez
 * Start: Tue Nov 29 19:42:10 EST 2011
 * End  : Tue Nov 29 19:46:23 EST 2011
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
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int N;
		cin >> N;
		int answer = ((((((N*567)/9)+7492)*235/47)-498)/10)%10; 
		cout << (( answer < 0 ) ? -answer : answer ) << endl;
	}
}
