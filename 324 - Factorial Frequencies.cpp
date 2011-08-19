/* Name: Alex Velazquez
 * Date: August 13, 2011
 * Purpose: To solve the problem #324 (Factorial Frequencies) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=260
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

struct bigNum {
	string number; // number representation in string
	int s; // number of digits in number
	bigNum (string n) : number(n), s((int)n.size()) {}
	bigNum () 	      : number(""),s(0) {}
	bigNum (const bigNum& rhs)
	{
		this->number = rhs.number;
		this->s = rhs.s;
	}
	bigNum& operator = (const bigNum& rhs)
	{
		this->number = rhs.number;
		this->s = rhs.s;
		return *this;
	}
	void updateS () { this->s = (int)number.size();}
};

ostream& operator << (ostream& os, const bigNum& N)
{
	os << N.number;
	return os;
}

void addLeadingZeroes (bigNum& A, int i)
{
	if (i > 0)
	{
		A.number = "0" + A.number;
		addLeadingZeroes(A,i-1);
	}
}

void addTrailingZeroes (bigNum& A, int i)
{
	if (i > 0)
	{
		A.number += "0";
		addTrailingZeroes(A,i-1);
	}
}

/* adding two bigNums */
bigNum operator + (bigNum A, bigNum B)
{
	bigNum C;
	/* strings must be the same size in order to add them */
	//cout << "A: " << A << ". B: " << B << endl;
	//cout << "A.s: " << A.s << ". B.s: " << B.s << endl;
	int diff;
	if (A.s < B.s) // add zeroes to A
	{
		diff = B.s - A.s; // add $diff zeroes to A
		addLeadingZeroes(A,diff);
	}
	else if (A.s > B.s)
	{
		diff = A.s - B.s;
		addLeadingZeroes(B,diff);
	}
	
	int highDig = (A.s > B.s)? A.s : B.s;
	int carry=0;
	
	/* now add the strings bit by bit, starting from the rightmost bit */
	for (int i=highDig-1;i>=0;--i)
	{
		int summ = (int)A.number[i] + (int)B.number[i] - 2*48 + carry;
		carry = summ/10;
		stringstream out;
		out << summ%10; // last digit of summ
		C.number = out.str() + C.number;
	}
	/* add the leftover carry (if any!) */
	if (carry)
	{
		stringstream out;
		out << carry;
		C.number = out.str() + C.number;
	}
	
	return C;
}

bigNum operator * (bigNum A, bigNum B)
{
	bigNum C("0");
	int currMult;
	int carry;
	/* multiply each digit in B (starting with the right most) and add it to C */
	int addZeroes=0;
	for (int i=B.s-1;i>=0;--i)
	{
		bigNum T;
		carry = 0;
		/* iterate through string A and multiply with digit chosen above */
		for (int j=A.s-1;j>=0;--j)
		{
			currMult = ((int)B.number[i]-48)*((int)A.number[j]-48)+carry;
			stringstream out;
			out << currMult%10;
			T.number = out.str() + T.number;
			carry = currMult/10;
		}
		/* dont forget the carry! */
		if (carry)
		{	
			stringstream out;
			out << carry;
			T.number = out.str() + T.number;
		}
		addTrailingZeroes(T,addZeroes);
		T.updateS();
		C.updateS();
		//cout << "C: " << C << endl;
		//cout << "T: " << T << endl;
		//cout << "C+T: " << C+T << endl;
		C = C+T;
		++addZeroes;
	}
	
	return C;
}

int main ()
{
	int LIMIT=368;
	bigNum A[LIMIT];
	A[0].number = "1"; A[0].updateS();
	A[1].number = "1"; A[1].updateS();
	for (int i=0;i<LIMIT;++i)
	{
		//cout << "i: " << i << ". i!: " << A[i] << endl;
		A[i].updateS();
		stringstream out;
		out << i+1; 
		//cout << "before" << endl;
		bigNum T(out.str());
		//cout << "after" << endl;
		//cout << "A[i]: " << A[i] << ". T:" << T << ". A[i]*T: " << A[i]*T << endl;
		A[i+1] = A[i]*T;
	}
	/* getting input */
	int N;
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
			
		/* initialize array counter */
		int F[10];
		for (int i=0;i<10;++i)
			F[i] = 0;
		
		/* calculate frequencies of numbers in string */
		for (int j=0;j<A[N].s;++j)
			++F[(int)A[N].number[j]-48]; 
		
		/* displaying output */
		cout << N << "! --" << endl;
		printf("    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d\n",0,F[0],1,F[1],2,F[2],3,F[3],4,F[4]);
		printf("    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d\n",5,F[5],6,F[6],7,F[7],8,F[8],9,F[9]);
	}
	
}

