/* Name: Alex Velazquez
 * Start Date: September 24, 2011 @ 10:10PM
 * End Date:   September 23, 2011 @ 11:29PM
 * Purpose: To solve the UVa problem 10719 - Quotient Polynomial
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=99&page=show_problem&problem=1660
 * */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main ()
{
	int k, r;
	string line, token;
	//bool negativeNum;
	while (cin >> k)
	{
		vector<int> p;
		cin.ignore();
		getline(cin,line);
		if (line == "")
			getline(cin,line);
		stringstream ss (line);
		while (getline(ss,token,' '))
		{
			istringstream stream(token);
			int val;
			stream >> val;
			//if (negativeNum) val *= -1;
			//cout << "val: " << val << endl;
			p.push_back(val);
		}

		if ((int)p.size() == 1) // constant
		{
			cout << "q(x):" << endl;
			cout << "r = " << p[0] << endl;
			cout << endl;
			continue;
		}
		vector<int> q;
		q.push_back(p[0]);
		int i=0;
		for (;i<(int)p.size()-2;++i)
		{
			q.push_back(k*q[i]+p[i+1]);
		}
		r = k*q[i]+p[i+1];

		cout << "q(x):";
		for (vector<int>::iterator it=q.begin();it!=q.end();++it)
			cout << " " << *it;
		cout << endl;
		cout << "r = " << r << endl;
		cout << endl;
	}
}
