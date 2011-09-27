/* Name: Alex Velazquez
 * Start Date: September 26, 2011 @ 09:36PM
 * End Date:   September 26, 2011 @ 03:54PM
 * Purpose: To solve the UVa problem 583 - "Prime Factors"
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main ()
{
	int LIMIT = 50000;
    vector<int>primes;
    bool numbers[LIMIT];
    numbers[0] = true;
    numbers[1] = true;
    int i=2;
    for (int i=2;i<LIMIT;++i)
        numbers[i] = false;
    while (i <= int(sqrt(LIMIT)))
    {
          for (int j=i+i;j<=LIMIT;j+=i)
              numbers[j] = true;    
          i++;
          while (numbers[i] == true)
                i++;
    }
    for (int i=0;i<LIMIT;++i)
    {
        if (numbers[i] == false)
           primes.push_back(i);
    }

	int num;
	while (cin >> num)
	{
		if (num == 0)
			break;
		vector<int> factors;
		cout << num << " = ";
		if (num < 0)
		{
			factors.push_back(-1);
			num *= -1;
		}
		bool hadFactor = false;
		for (vector<int>::iterator it=primes.begin();it!=primes.end();++it)
		{
			if (num == 1)
				break;
			while (num%*it==0)
			{
				num /= *it;
				hadFactor = true;
				factors.push_back(*it);
			}
		}
		if (hadFactor == false)
			factors.push_back(num);
		cout << *factors.begin();
		vector<int>::iterator it = factors.begin();
		++it;
		for (;it!=factors.end();++it)
		{
			cout << " x " << *it;
		}
		cout << endl;
	}
}
