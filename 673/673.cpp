/* Name: Alex Velazquez
 * Start Date: August 21, 2011 @ 06:58PM
 * End Date:   August 21, 2011 @ 10:40PM
 * Purpose: To solve the problem #673 (Parentheses Balance) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=103&page=show_problem&problem=614
 * */

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	cin.get();
	for (int i=0;i<T;++i)
	{
		string S;
		getline(cin,S);

		if (S == "")
		{
			cout << "Yes" << endl;
			continue;
		}

		stack<char> exp;
		stack<char> exp2;
		bool yesOrNo;

		for (string::iterator it = S.begin();it!=S.end();++it)
		{
			if (*it == '(' || *it == '[')
			{
				exp.push(*it);
			}
			else
			{
				exp2.push(*it);
				if (exp.empty())
				{
					yesOrNo=false;
					break;
				}
				char tp = exp.top();
				if (tp == '(' && *it == ')')
				{
					exp.pop();
					exp2.pop();
				}
				else if (tp == '[' && *it == ']')
				{
					exp.pop();
					exp2.pop();
				}
				else
				{
					yesOrNo=false;
					break;
				}
			}
		} 
		if (exp.empty() && exp2.empty())
			yesOrNo=true;
		else
			yesOrNo=false;
		
		cout << ((yesOrNo)?"Yes":"No") << endl;
	}
}
