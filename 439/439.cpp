/* Name: Alex Velazquez
 * Date: August 19, 2011
 * Purpose: To solve the problem #439 (Knight Moves) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=380
 * */

#include <iostream>
#include <set>
#include <utility>

using namespace std;

/* returns all valid moves for a knight */
set<pair<int,int> > nextMove (pair<int,int> S)
{
	set<pair<int,int> > allMoves;
	if (S.first-1>0 && S.first-1<9 && S.second+2<9 && S.second+2>0) allMoves.insert(make_pair(S.first-1,S.second+2));
	if (S.first+1>0 && S.first+1<9 && S.second+2<9 && S.second+2>0) allMoves.insert(make_pair(S.first+1,S.second+2));
	if (S.first-1>0 && S.first-1<9 && S.second-2<9 && S.second-2>0) allMoves.insert(make_pair(S.first-1,S.second-2));
	if (S.first+1>0 && S.first+1<9 && S.second-2<9 && S.second-2>0) allMoves.insert(make_pair(S.first+1,S.second-2));
	if (S.first-2>0 && S.first-2<9 && S.second+1<9 && S.second+1>0) allMoves.insert(make_pair(S.first-2,S.second+1));
	if (S.first-2>0 && S.first-2<9 && S.second-1<9 && S.second-1>0) allMoves.insert(make_pair(S.first-2,S.second-1));
	if (S.first+2>0 && S.first+2<9 && S.second+1<9 && S.second+1>0) allMoves.insert(make_pair(S.first+2,S.second+1));
	if (S.first+2>0 && S.first+2<9 && S.second-1<9 && S.second-1>0) allMoves.insert(make_pair(S.first+2,S.second-1));
	return allMoves;
}

bool isDone (set<pair<int,int> > allMoves, pair<int,int> F)
{
	set<pair<int,int> > ::iterator it = allMoves.begin();
	set<pair<int,int> > ::iterator itEnd = allMoves.end();
	for (;it!=itEnd;++it)
	{
		//cout << "F = (" << F.first << "," << F.second << "). it= (" << it->first << "," << it->second << ")" << endl; 
		if (F == *it) return true;
	}
	return false;
}

int searchMoves (pair<int,int> S, pair<int,int> F)
{
	if (S == F)
		return 0;
	//cout << "S = (" << S.first << "," << S.second << ").  F = (" << F.first << "," << F.second << ")" << endl; 
	int numMoves = 0;
	set<pair<int,int> > moves;
	moves.insert(S);
	set<pair<int,int> > ::iterator it = moves.begin();
	set<pair<int,int> > ::iterator itEnd = moves.end();
	
	while (1)
	{
		set<pair<int,int> > ALLMOVES;
		++numMoves;
		for (;it!=itEnd;++it)
		{
		//	cout << "it = (" << it->first << "," << it->second << ")" << endl; 
			set<pair<int,int> > newMoves = nextMove(*it);
			set<pair<int,int> >::iterator itMoves = newMoves.begin();
			set<pair<int,int> >::iterator itMovesEnd = newMoves.end();
			for (;itMoves!=itMovesEnd;++itMoves)
			{
				//cout << "numMoves: " << numMoves << ". itMoves = (" << itMoves->first << "," << itMoves->second << ")" << endl;
				//if (F == *itMoves) return numMoves;
				ALLMOVES.insert(*itMoves);
			}
		}
		if (isDone(ALLMOVES,F))
			return numMoves;
		moves = ALLMOVES;
		it = moves.begin();
		itEnd = moves.end();
	}
	return 0;
}

int main ()
{
	string start, finish;
	pair <int,int> S, F;
	while (cin >> start >> finish)
	{
		/* convert chars to ints (easier manipulation) */
		S.first  = (int)start[0]-2*48;
		S.second = (int)start[1]-48;
		F.first  = (int)finish[0]-2*48;
		F.second = (int)finish[1]-48;
		set<pair<int,int> > allMoves = nextMove(S);
		set<pair<int,int> >::iterator it = allMoves.begin();
		set<pair<int,int> >::iterator itEnd = allMoves.end();
		for (;it!=itEnd;++it)
		{
			//cout << "(" << it->first << "," << it->second << ")" << endl;
		}
		cout << "To get from " << start << " to " << finish << " takes ";
		cout << searchMoves(S,F) << " knight moves." << endl;
	}
}
