/* Name: Alex Velazquez
 * Date: August 19, 2011
 * Purpose: To solve the problem #499 (What's The Frequency, Kenneth?) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=440
 * */

#include <iostream>
#include <map>
#include <utility>
#include <iterator>
#include <set>
#include <string>

using namespace std;

struct WordFreq {
	char letter;
	int freq;
	WordFreq(char l, int f) : letter(l), freq(f) {}
};

/* the < is implemented in order for std::set to be able to sort WordFreq */
bool operator < (WordFreq const& A, WordFreq const &B)
{
	if (A.freq > B.freq)		
		return true;
	else if (A.freq < B.freq)	
		return false;
	else
	{
		if (A.letter < B.letter)
			return true;
		else
			return false;
	}
}

int main ()
{
   string sentence;
   while (1)
   {
	   if (getline(cin,sentence))
	   {
		   map<char,int> frequencies;
		   pair<map<char,int>::iterator,bool> result;
		   /* count the number of frequencies per letter in the input sentence */
		   for (int i=0;i<(int)sentence.size();++i)
		   {
				result = frequencies.insert(make_pair(sentence[i],1));
				if (result.second == false) // already inserted into the map!
					result.first->second += 1; 
		   }
		   set<WordFreq> unique_vals;
		   map<char,int>::iterator it = frequencies.begin();
		   map<char,int>::iterator itEnd = frequencies.end();

		   /* now insert all the unique ones to a set (which already sorts it!) */
		   for (;it!=itEnd;++it)
				if (it->first != ' ' && ((it->first >= 65 && it->first <= 90)||(it->first >= 97 && it->first <= 122)))
					unique_vals.insert(WordFreq(it->first,it->second));

		   /* display output! */
		   string highestChars="";
		   if (unique_vals.size() == 0)
				break;
		   set<WordFreq>::iterator iter = unique_vals.begin();
		   int highestFrequency = iter->freq;
		   highestChars += iter->letter;

		   /* find letters with equal frequency */
		   if (unique_vals.size() > 1)
		   {
				set<WordFreq>::iterator checkDups = iter;
				set<WordFreq>::iterator checkDupsEnd = unique_vals.end();
				++checkDups;
				for (;checkDups!=checkDupsEnd;++checkDups)
				{
					if (checkDups->freq == highestFrequency)
						highestChars += checkDups->letter;
				}
		   }

		   cout << highestChars << " " << highestFrequency << endl;
 
	   }
	   else
	   {
		   break;
	   }
   }
}
