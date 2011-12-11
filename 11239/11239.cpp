/* Alex Velazquez
 * Start: Sun Dec 11 03:10:10 EST 2011
 * End  : Sun Dec 11 03:43:46 EST 2011
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <string>

using namespace std;

struct Project {
	string name;
	int occur;
	Project (string n, int o ) : name( n ), occur( o ) {} 
};

bool operator < (Project const& A, Project const& B )
{
	if( A.occur > B.occur )
		return true;
	else if ( A.occur < B.occur )
		return false;
	else
	{
		if( A.name.compare( B.name ) < 0 )
			return true;
		else
			return false;
	}
}

int main ()
{
	string line;
	while( 1 )
	{
		map<string,set<string> > projects;
		map<string,set<string> > students;
		bool end = false;
		string P;
		while( getline( cin, line ) )
		{
			//cout << "--" << line << "--" << endl;
			if( line[0] == '1' )
			{
				break;
			}
			else if ( line[0] == '0' )
			{
				end = true;
				break;
			}
			if( line[0] >= 65 && line[0] <= 90 )
			{ 
				// uppercase letter => project
				P = line;
				projects.insert(make_pair(P,set<string>()));
			}
			else // student
			{
				projects[P].insert( line );
				students[line].insert( P );
			}
		}
		map<string, set<string> >::iterator p = projects.begin(), pEnd = projects.end();
		map<string, set<string> >::iterator s = students.begin(), sEnd = students.end();
		set<Project> sProj;
		for( ; p != pEnd ; ++p )
		{
			//cout << "Project: " << p->first << ": " << endl;
			int numStudents = 0;
			for( set<string>::iterator it = p->second.begin(); it!=p->second.end(); ++it )
			{
				if( students[*it].size() == 1 )
					++numStudents;
				//cout << "\tStudent: " << *it << ". size: " << students[*it].size() << endl;
			}
			sProj.insert( Project( p->first, numStudents ) );
		}
		
		for( set<Project>::iterator it = sProj.begin(); it!=sProj.end(); ++it )
		{
			cout << it->name << " " << it->occur << endl;
		}
		if( end )
			break;
	}
}
