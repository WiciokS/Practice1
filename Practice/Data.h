#pragma once

#include <iostream>
#include <vector>
#include<algorithm>
#include<string>

class RationalNumbers
{
private:

	//numerator/denominator
	int numerator=0;
	int denominator=1;
public:
	//simplify
	int absint(int integer);
	void getfactors(int integer, std::vector<int>& factorset);
	void simplifyrationalnumber(int& leftint, int& rightint);

	//seterai
	void setrational(int numer, int denum);
	void setnumerator(int numer);
	void setdenominator(int denum);

	//geterai
	int getnumerator()const;
	int getdenominator()const;

	//methods
	RationalNumbers addition(RationalNumbers& rational);
	RationalNumbers subtraction(RationalNumbers& rational);
	RationalNumbers multiplication(RationalNumbers& rational);
	RationalNumbers division(RationalNumbers& rational);
	bool more(RationalNumbers& rational);
	RationalNumbers negative();

	//operations
	RationalNumbers plus(const RationalNumbers& leftrational,const RationalNumbers& rightrational);
	RationalNumbers minus(const RationalNumbers& leftrational, const  RationalNumbers& rightrational);
	RationalNumbers multiply(const RationalNumbers& leftrational, const  RationalNumbers& rightrational);
	RationalNumbers divide(const RationalNumbers& leftrational, const RationalNumbers& rightrational);
	bool ismore(const RationalNumbers& leftrational, const  RationalNumbers& rightrational);
	bool iseaqual(const RationalNumbers& leftrational, const  RationalNumbers& rightrational);
	RationalNumbers byminusone(const RationalNumbers& rational);
	
	//output
	void output(std::ostream& out);
	void outputbool(std::ostream& out);

	//constructors
	RationalNumbers(int numer, int denom);//constructor with 2 integers
	RationalNumbers(int numer);//constructor with 1 integers
	RationalNumbers();//constructor without integers
	RationalNumbers(std::istream& in);//constructor with keyboard input
};