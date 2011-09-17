/* Name: Alex Velazquez
 * Start Date: September 16, 2011 @ 10:59PM
 * End Date:   September 16, 2011 @ 11:05PM
 * Purpose: To solve the UVa problem "621 - Secret Research"
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=99&page=show_problem&problem=562
 * */
#include <iostream>
#include <string>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	string num;
	for (int i=0;i<T;++i)
	{
		cin >> num;
		if (num.compare("1") == 0 || num.compare("4") == 0 || num.compare("78") == 0) 
			cout << "+" << endl;
		else if (num.substr((int)num.size()-2,2).compare("35") == 0)
			cout << "-" << endl;
		else if (num.substr(0,1).compare("9") == 0 && num.substr((int)num.size()-1,1).compare("4") == 0)
			cout << "*" << endl;
		else if (num.substr(0,3).compare("190") == 0)
			cout << "?" << endl;
	}
}
