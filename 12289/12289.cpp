/* Name: Alex Velazquez
 * Start Date: October 01, 2011 @ 02:19AM
 * End Date:   October 01, 2011 @ 02:22AM
 * Purpose: To solve the UVa problem 12289 - "One-Two-Three"
 */

#include <iostream>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	string word;
	for (int i=0;i<T;++i)
	{
		cin >> word;
		if ((int)word.size() == 5)
			cout << 3 << endl;
		else
		{
			if ((word[0] == 'o' && word[1] == 'n') ||
				(word[0] == 'o' && word[2] == 'e') ||
				(word[1] == 'n' && word[2] == 'e'))
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}
	}
}
