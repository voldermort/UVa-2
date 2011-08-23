/* Name: Alex Velazquez
 * Start Date: August 22, 11:35PM
 * End Date:   August 23, 12:47PM
 * Purpose: To solve the problem #465 (Overflow) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=97&page=show_problem&problem=406
 * */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string removeLeadingZeroes(string A)
{
	int start=(int)A.size()-1;
	for (int i=0;i<(int)A.size();++i)
	{
		if (A[i] != '0')
		{
			start = i;
			break;
		}
	}
	return A.substr(start);
}

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
		C = C+T;
		++addZeroes;
	}
	return C;
}

bool overflow (string X)
{
	/* maximum int in C is 2,147,483,647 */
	if ((int)X.size() > 10)
		return true;
	else if ((int)X.size() < 10)
		return false;
	else // 10 digits. check each digit!
	{
		if (X <= "2147483647")
			return false;
		else
			return true;
	}
}

inline std::string TrimStr(const std::string& Src, const std::string& c = " \r\n")
{
	size_t p2 = Src.find_last_not_of(c);
	if (p2 == std::string::npos) return std::string();
	size_t p1 = Src.find_first_not_of(c);
	if (p1 == std::string::npos) p1 = 0;
	return Src.substr(p1, (p2-p1)+1);
}

int main ()
{
	string a, b;
	char op;
	string line;
	while (getline(cin,line))
	{
		size_t opPlus = line.find("+");
		size_t opTimes= line.find("*");
		if (opPlus!=string::npos)
		{
			a = line.substr(0,opPlus);
			op = line[opPlus];
			b = line.substr(opPlus+1);
		}
		else
		{
			a = line.substr(0,opTimes);
			op = line[opTimes];
			b = line.substr(opTimes+1);
		}
		
		a = TrimStr(a);
		b = TrimStr(b);

		cout << line << endl;
		bigNum A(a), B(b), C;
		switch (op)
		{
			case '+': C = A+B; break;
			case '*': C = A*B; break; 
		}
		C.updateS();

		if (overflow(removeLeadingZeroes(A.number))) cout << "first number too big" << endl;
		if (overflow(removeLeadingZeroes(B.number))) cout << "second number too big" << endl;
		if (overflow(removeLeadingZeroes(C.number))) cout << "result too big" << endl;
	}
}
