/* Alex Velazquez
 * Start: Fri Nov 25 21:16:00 EST 2011
 * End  : Sat Nov 26 03:05:24 EST 2011
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

LL power( int base, int exponent )
{
	LL t = 1LL;
	for( int i=0; i<exponent; ++i )
		t *= base;
	return t;
}

int main ()
{
	// 2 -> 62
	// 3 -> 50
	// 5 -> 35
	LL limit = 1000000000000000000LL;
	set<LL> nums;
	for( int i=0; i<63; ++i )
	{
		for( int j=0; j<51; ++j )
		{
			for( int k=0; k<36; ++k )
			{
				if( i+j+k <= 36 )
				{
					LL Y = power(2,i)*power(3,j);
					if( Y > 0LL )
					{
						LL X = Y*power(5,k);
					//	cout << X << endl;
						if( X > 0LL && X <= limit )
							nums.insert(X);
					}
				}
			}
		}
	}
	int k = 0;
	//cout << nums.size() << endl;
	for( set<LL>::iterator it=nums.begin(); it!=nums.end(); ++it )
	{
		++k;
		if( k == 1500 )
		{
			cout << "The 1500'th ugly number is " << *it  << "." << endl;
			break;
		}
	}
}
