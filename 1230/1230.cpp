/* Name: Alex Velazquez
 * Start Date: September 20, 2011 @ 7:45PM
 * End Date:   September 20, 2011 @ 9:32PM
 * Purpose: To solve the UVa problem 1230 - MODEX
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=247&page=show_problem&problem=3671
 * */

#include <iostream>

using namespace std;

int power (int x, int const &y)
{
	int k=1;
	for (int i=0;i<y;++i)
		k *= x;
	return k;
}

/* We know that (x*y)%n = ((x%n)*(y%n))%n
 * Hence, (x^2)%n = (x*x)%n = ((x%n)*(x%n))%n
 *                          = ((x%n)^2)%n
 * So, for example:
 *   (5^127)%13 = (((5^63)^2)%13*(5^1)%13)%13
 *   then apply the same algorithm to 5^63
 *   (5^63)%13 = (((5^31)^2)%13*(5^1)%13)%13
 *   then apply algorithm to 5^31 .. and so
 *   on and so forth ...
 */   
int calc2 (int &x, int y, int &n)
{
	if (y <= 2)
		return power(x,y)%n;
	else
	{
		if (y%2==0)
			return power(calc2(x,y/2,n)%n,2)%n;
		else
			return power(calc2(x,y/2,n)%n,2)%n*x%n;
	}	
}

/* earlier attempt */
int calc (int x, int y, int n)
{
	if (y <= 2)
	{
		return power(x,y)%n;
	}
	else
	{
		return (calc(x,y/2,n)*calc(x,y-y/2,n))%n;
	}
} 

int main ()
{
	int T, x, y, n;
	cin >> T;
	for (int i=0;i<T;++i)
	{
		cin >> x >> y >> n;
		cout << calc2(x,y,n) << endl;
	}
}
