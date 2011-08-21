/* Name: Alex Velazquez
 * Start Date: August 21, 2011 @ 12:56PM
 * End Date: August 21, 2011 @ 1:15PM
 * Purpose: To solve the problem #489 (Hangman Judge) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=430
 * */

#include <iostream>
#include <set>

using namespace std;

int main ()
{
	int round;
	while (1)
	{
		cin >> round;
		if (round == -1)
		{
			break;
		}
		cout << "Round " << round << endl;
		string word;
		string guesses;
		set<char> letters;
		set<char> letterGuesses;
		cin >> word >> guesses;
		
		/* insert all letters from the word to a set */
		for (string::iterator it=word.begin();it!=word.end();++it)
			letters.insert(*it);
			
		int NUM_GUESSES_NEEDED = (int)letters.size();
		int CORRECT_GUESSES = 0;
		int INCORRECT_GUESSES = 0;
		
		/* making guesses letter by letter */
		for (string::iterator it=guesses.begin();it!=guesses.end();++it)
		{
			if (letters.count(*it) > 0) // letter is found in word
			{
				if (letterGuesses.count(*it) > 0) // letter was already found!
				{
					//cout << "The letter " << *it << " was already found in the word " << word << endl;
				}
				else // first time we encounter this letter
				{
					++CORRECT_GUESSES;
					//cout << "The letter " << *it << " is in the word " << word << endl;
					letterGuesses.insert(*it);
				}
				
			}
			else // incorrect guess! keep track of it
			{
				if (letterGuesses.count(*it) > 0) // did we already incorrectly guesses this letter?
				{
					// don't count
				}
				else // first time we guess this letter wrong
				{
					++INCORRECT_GUESSES;
				}
			}
			
			/* check end of game */
			if (CORRECT_GUESSES == NUM_GUESSES_NEEDED)
			{
				cout << "You win." << endl;
				break;
			}
			else if (INCORRECT_GUESSES == 7)
			{
				cout << "You lose." << endl;
				break;
			}
			
		}
		if (CORRECT_GUESSES != NUM_GUESSES_NEEDED && INCORRECT_GUESSES != 7)
			cout << "You chickened out." << endl;
		
	}
}
