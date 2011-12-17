/* Alex Velazquez
 * Start: Fri Dec 16 19:28:32 EST 2011
 * End  : Fri Dec 16 19:41:56 EST 2011
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
string removeLeadingZeroes(string A)
{
	int start=(int)A.size()-1;
	for (int i=0;i<(int)A.size();++i)
	{
		if (A[i] != '0')
		{
			start = i;
			break;
		}
	}
	return A.substr(start);
}

void addLeadingZeroes (string& A, int i)
{
	if (i > 0)
	{
		A = "0" + A;
		addLeadingZeroes(A,i-1);
	}
}

string add(string A, string B)
{
	string C;
	
	int diff;
	int aSize = A.size(), bSize = B.size();
	if (aSize < bSize) // add zeroes to A
	{
		diff = bSize - aSize; // add $diff zeroes to A
		addLeadingZeroes(A,diff);
	}
	else if (A > B)
	{
		diff = aSize - bSize;
		addLeadingZeroes(B,diff);
	}
	int highDig = (aSize > bSize)? aSize:bSize;
	int carry=0;
	
	/* now add the strings bit by bit, starting from the rightmost bit */
	for (int i=highDig-1;i>=0;--i)
	{
		int summ = (int)A[i] + (int)B[i] - 2*48 + carry;
		carry = summ/10;
		stringstream out;
		out << summ%10; // last digit of summ
		C = out.str() + C;
	}
	/* add the leftover carry (if any!) */
	if (carry)
	{
		stringstream out;
		out << carry;
		C = out.str() + C;
	}
	return C;
}

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		string a, b;
		cin >> a >> b;
		reverse( a.begin(), a.end() );
		reverse( b.begin(), b.end() );
		string C = add( a, b );
		reverse( C.begin(), C.end() );
		cout << removeLeadingZeroes( C ) << endl;
	}
}
