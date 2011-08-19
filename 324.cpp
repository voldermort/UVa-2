#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

struct bigNum {
	string number; 
	int s; 
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


bigNum operator + (bigNum A, bigNum B)
{
	bigNum C;

	int diff;
	if (A.s < B.s) 
	{
		diff = B.s - A.s;
		addLeadingZeroes(A,diff);
	}
	else if (A.s > B.s)
	{
		diff = A.s - B.s;
		addLeadingZeroes(B,diff);
	}
	
	int highDig = (A.s > B.s)? A.s : B.s;
	int carry=0;
	

	for (int i=highDig-1;i>=0;--i)
	{
		int summ = (int)A.number[i] + (int)B.number[i] - 2*48 + carry;
		carry = summ/10;
		stringstream out;
		out << summ%10; 
		C.number = out.str() + C.number;
	}

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

	int addZeroes=0;
	for (int i=B.s-1;i>=0;--i)
	{
		bigNum T;
		carry = 0;

		for (int j=A.s-1;j>=0;--j)
		{
			currMult = ((int)B.number[i]-48)*((int)A.number[j]-48)+carry;
			stringstream out;
			out << currMult%10;
			T.number = out.str() + T.number;
			carry = currMult/10;
		}

		if (carry)
		{	
			stringstream out;
			out << carry;
			T.number = out.str() + T.number;
		}
		addTrailingZeroes(T,addZeroes);
		T.updateS();
		C.updateS();
		C = C+T;
		++addZeroes;
	}
	
	return C;
}

int main ()
{
	int LIMIT=468;
	bigNum A[LIMIT];
	A[0].number = "1"; A[0].updateS();
	A[1].number = "1"; A[1].updateS();
	for (int i=0;i<LIMIT;++i)
	{
		A[i].updateS();
		stringstream out;
		out << i+1; 
		bigNum T(out.str());
		A[i+1] = A[i]*T;
	}

	int N;
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;

		int F[10];
		for (int i=0;i<10;++i)
			F[i] = 0;

		for (int j=0;j<A[N].s;++j)
			++F[(int)A[N].number[j]-48]; 

		cout << N << "! --" << endl;
		printf("    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d\n",0,F[0],1,F[1],2,F[2],3,F[3],4,F[4]);
		printf("    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d\n",5,F[5],6,F[6],7,F[7],8,F[8],9,F[9]);
	}
	
}

