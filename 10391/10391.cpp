/* Name: Alex Velazquez
 * Start Date: September 25, 2011 @ 12:54PM
 * End Date:   September 25, 2011 @ ????
 * Purpose: To solve the UVa problem 10391 - Compound Words
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=99&page=show_problem&problem=1660
 * */
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	set<string> words;
	set<string> compounds;
	string s;
	while (cin >> s)
		words.insert(s);
	set<string>::iterator w = words.begin(), wEnd = words.end(), wNext, wCompound;
	--wEnd;
	string wFound;
	int wSize;
	for(;w!=wEnd;++w)
	{
		//cout << "w: " << *w << endl;
		wNext = w;
		++wNext;
		wSize = (int)w->size();
		while (1)
		{
			if (wNext == words.end())
				break;
			//cout << "wNext: " << *wNext << endl;
			int foundAt = wNext->find(*w);
			//cout << "foundAt: " << foundAt << endl;
			if (foundAt == 0) // if found at beginning of string
			{
				wFound = wNext->substr(wSize);
				//cout << "wFound: " << wFound << endl;
				wCompound = words.find(wFound);
				if ( wCompound != words.end())
				{
					compounds.insert(*w+wFound);
					++wNext;
				}
				else
				{
					++wNext;
				}
			}
			else
			{
				break;
			}	
		}
	}
	for (set<string>::iterator it=compounds.begin();it!=compounds.end();++it)
		cout << *it << endl;
}
