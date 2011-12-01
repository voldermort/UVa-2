/* Alex Velazquez
 * Start: Wed Nov 30 20:29:45 EST 2011
 * End  : Wed Nov 30 20:44:13 EST 2011
*/
#include <iostream>
#include <vector>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <string>

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
	// 2 -> 32
	// 3 -> 20
	// 5 -> 14
	// 7 -> 12
	LL limit = 10000000000LL;
	vector<LL> nums;
	for( int i=0; i<33; ++i )
	{
		for( int j=0; j<21; ++j )
		{
			for( int k=0; k<15; ++k )
			{
				for( int l=0; l<13; ++l )
				{
					if( i+j+k <= 36 )
					{
						LL Y = power(2,i)*power(3,j);
						if( Y > 0LL )
						{
							LL X = Y*power(5,k);
							if( X > 0LL )
							{
								LL Z = X*power(7,l);
								if( Z > 0LL && Z <= limit )
									nums.push_back( Z );
							}
						}
					}
				}
			}
		}
	}
	sort( nums.begin(), nums.end() );
	unique( nums.begin(), nums.end() );
	int K;
	while( cin >> K )
	{
		if( K == 0 )
			break;
		cout << "The " << K;
		if( (K/10)%10 == 1 && ( K%10 == 1 || K%10 == 2 || K%10 == 3  ) )
			cout << "th";
		else if( K%10 == 1 )	cout << "st";
		else if( K%10 == 2 )	cout << "nd";
		else if( K%10 == 3 )	cout << "rd";
		else 					cout << "th";
		cout << " humble number is " << nums[K-1] << "." << endl;
	}
}

