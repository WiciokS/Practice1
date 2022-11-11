#include "Data.h"

//simplify
int RationalNumbers::absint(int integer)
{
	if (integer >= 0) return integer;
	else return -integer;
}
void RationalNumbers::getfactors(int integer, std::vector<int>& factorset)
{
	if (integer != 1) factorset.push_back(integer);
	for (int i = 2; i <= sqrt(integer); i++) 
	{
		if (integer % i == 0) 
		{
			factorset.push_back(i);
			if(i!=integer/i) factorset.push_back(integer / i);
		}
	}
	std::sort(factorset.begin(), factorset.end(), std::greater<int>());
}
void RationalNumbers::simplifyrationalnumber(int& leftint, int& rightint)
{
	int numer = leftint;
	int denom = rightint;
	int smallest, integer;
	std::vector<int> factorset;

	if (numer == denom)
	{
		leftint = 1;
		rightint = 1;
	}

	if (absint(numer) < absint(denom)) smallest = absint(numer);
	else smallest = absint(denom);

	getfactors(smallest, factorset);

	for (int i = 0; i < factorset.size(); i++) 
	{
		integer = factorset[i];
		if(numer % integer == 0 && denom % integer == 0)
		{
			numer /= integer;
			denom /= integer;
			break;
		}
	}

	leftint = numer;
	rightint = denom;
}

//seterai
void RationalNumbers::setrational(int numer, int denom)
{
	simplifyrationalnumber(numer, denom);
	setnumerator(numer);
	setdenominator(denom);
}
void RationalNumbers::setnumerator(int numer)//set numerator
{
		numerator = numer;
}
void RationalNumbers::setdenominator(int denom)//set denominator
{
	if (denom == 0)//check if denominator is positive
	{
		std::cout << "denominator ->"<<denom<<" is 0, is set as 1" << "\n";
		denominator = 1;//if not set as 1
	}
	if (denom < 0)
	{
		denominator = -denom;
		numerator = -numerator;
		std::cout << "denominator ->" << denom << " is less than 0, minus moved to numerator" << "\n";
	}
	else//if yes continue
	{
		denominator = denom;
	}
}

//geterai
int RationalNumbers::getnumerator()const //get numerator
{
	return numerator;//return numerator integer
}
int RationalNumbers::getdenominator()const //get denominator
{
	return denominator;//return denominator integer
}

//methods
RationalNumbers RationalNumbers::addition(RationalNumbers& rational)//add rational number
{
	RationalNumbers current(getnumerator(), getdenominator());//create variable
	int numer = rational.getnumerator();//for easier understanding
	int denom = rational.getdenominator();
	current.setrational((getnumerator() * denom) + (numer * getdenominator()), getdenominator() * denom);//simplify calculate and set numerator and denominator
	return current;//return rational number
}
RationalNumbers RationalNumbers::subtraction(RationalNumbers& rational)//substract rational number
{
	RationalNumbers current(getnumerator(), getdenominator());//create variable
	int numer = rational.getnumerator();//for easier understanding
	int denom = rational.getdenominator();
	current.setrational((getnumerator() * denom) - (numer * getdenominator()), getdenominator() * denom);//simplify calculate and set numerator and denominator
	return current;//return rational number
}
RationalNumbers RationalNumbers::multiplication(RationalNumbers& rational)//multiply rational number
{
	RationalNumbers current(getnumerator(), getdenominator());//create variable
	int numer = rational.getnumerator();//for easier understanding
	int denom = rational.getdenominator();
	current.setrational(getnumerator() * numer, getdenominator() * denom);//simplify calculate and set numerator and denominator
	return current;//return rational number
}
RationalNumbers RationalNumbers::division(RationalNumbers& rational)//divide rational number
{
	RationalNumbers current(getnumerator(), getdenominator());//create variable
	int numer = rational.getnumerator();//for easier understanding
	int denom = rational.getdenominator();
	current.setrational(getnumerator() * denom, getdenominator() * numer);//simplify calculate and set numerator and denominator
	return current;//return rational number
}
bool RationalNumbers::more(RationalNumbers& rational)//compare rational number
{
	int numer = rational.getnumerator();//for easier understanding
	int denom = rational.getdenominator();
	simplifyrationalnumber(numer, denom);//simplify added number
	int left = getnumerator() * denom;//calculate current rational number value
	int right = getdenominator() * numer;//calculate compared rational number value
	return (left > right);// return value 1/1(true) or 0/1(false)
}
RationalNumbers RationalNumbers::negative()//return negative rational number
{
	RationalNumbers current(-getnumerator(), getdenominator());//create and set negative variable
	return current;//return rational number
}

//operations
RationalNumbers RationalNumbers::plus(const RationalNumbers& leftrational, const RationalNumbers& rightrational)
{
	RationalNumbers current;//create variable
	current.setrational((leftrational.getnumerator() * rightrational.getdenominator()) + (rightrational.getnumerator() * leftrational.getdenominator())
		, leftrational.getdenominator() * rightrational.getdenominator());//simplify calculate and set numerator and denominator
	setrational(current.getnumerator(),current.getdenominator());//save number for future output to screen
	return current;
}
RationalNumbers RationalNumbers::minus(const RationalNumbers& leftrational, const  RationalNumbers& rightrational)
{
	RationalNumbers current;//create variable
	current.setrational((leftrational.getnumerator() * rightrational.getdenominator()) - (rightrational.getnumerator() * leftrational.getdenominator())
		, leftrational.getdenominator() * rightrational.getdenominator());//simplify calculate and set numerator and denominator
	setrational(current.getnumerator(), current.getdenominator());//save number for future output to screen
	return current;
}
RationalNumbers RationalNumbers::multiply(const RationalNumbers& leftrational, const  RationalNumbers& rightrational)
{
	RationalNumbers current;//create variable
	current.setrational((leftrational.getnumerator() * rightrational.getnumerator())
		, leftrational.getdenominator() * rightrational.getdenominator());//simplify calculate and set numerator and denominator
	setrational(current.getnumerator(), current.getdenominator());//save number for future output to screen
	return current;
}
RationalNumbers RationalNumbers::divide(const RationalNumbers& leftrational, const RationalNumbers& rightrational)
{
	RationalNumbers current;//create variable
	int numerleft = leftrational.getnumerator();
	int numerright = rightrational.getnumerator();
	current.setrational((numerleft * rightrational.getdenominator())
		, leftrational.getdenominator() * numerright);//simplify calculate and set numerator and denominator
	setrational(current.getnumerator(), current.getdenominator());//save number for future output to screen
	return current;
}
bool RationalNumbers::ismore(const RationalNumbers& leftrational, const  RationalNumbers& rightrational)
{
	int left = leftrational.getnumerator() * rightrational.getdenominator();//calculate left rational number value
	int right = leftrational.getdenominator() * rightrational.getnumerator();//calculate right rational number value
	setnumerator((left > right));//save
	setdenominator(1);
	return (left > right);// return value 1/1(true) or 0/1(false)
}

bool RationalNumbers::iseaqual(const RationalNumbers& leftrational, const  RationalNumbers& rightrational)
{
	int left = leftrational.getnumerator() * rightrational.getdenominator();//calculate left rational number value
	int right = leftrational.getdenominator() * rightrational.getnumerator();//calculate right rational number value
	setnumerator((left == right));//save
	setdenominator(1);
	return (left == right);// return value 1/1(true) or 0/1(false)
}
RationalNumbers RationalNumbers::byminusone(const RationalNumbers& rational)
{
	RationalNumbers current(-rational.getnumerator(), rational.getdenominator());//create and set negative variable
	setrational(current.getnumerator(), current.getdenominator());
	return current;//return rational number
}

//output
void RationalNumbers::output(std::ostream& out)//output rational number
{
	out << getnumerator() << "/" << getdenominator() << "\n";
}
void RationalNumbers::outputbool(std::ostream& out)
{
	if (getnumerator())
		out << "True" << "\n";
	else
		out << "False" << "\n";
}

//constructors
RationalNumbers::RationalNumbers(int numer, int denom)//constructor with 2 integers
{
	try
	{
		if (numer == 0 || denom == 0) throw 1;
		setrational(numer, denom);
	}
	catch (int e)//just catch
	{
		if (e == 1)
		{
			std::cout << "Wrong input, numerator or denominator is 0" << std::endl;
			exit(0);
		}
	}
	
}
RationalNumbers::RationalNumbers(int numer)//constructor with 1 integers
{
	
	try
	{
		if (numer == 0) throw 1;
		setnumerator(numer);
	}
	catch (int e)//just catch
	{
		if (e == 1)
		{
			std::cout << "Wrong input, numerator is 0" << std::endl;
			exit(0);
		}
	}
}
RationalNumbers::RationalNumbers()//constructor without integers
{

}
RationalNumbers::RationalNumbers(std::istream& in)//constructor with keyboard input
{
	std::string input;//entered string
	int curscannum = 0;//current scanned number
	int checkminus = 1;//check it is minus
	bool slash = false;//check for /
	bool minusend = false;//check - after /

	int numer = 0;//numerator
	int denom = 1;//denominator

	std::cout << "Write numerator/denumerator, also could be numerator only" <<"\n"
		<<"Allowed only digits - and / symbols, else end program"<<"\n";//explonation
	in >> input;//input to string
	char prscanner = '0';//previous scanned char
	try
	{
		for (int i = 0; i < input.size(); i++)//string scan
		{
			char scanner = input[i];//current char
			if ((scanner >= '0' && scanner <= '9') || scanner == '/' || scanner == '-')//restrict inputs
			{

				if (scanner == '/' && slash == false)//check for / to set numerator and start scan denominator
				{
					numer = curscannum * checkminus;//set numerator
					if(numer == 0 ) throw 3;
					std::cout << "numerator is " << numer << "\n";
					curscannum = 0;//reset
					checkminus = 1;
					slash = true;//start denominator
				}


				else if (scanner == '-')//check for -
				{
					if (i == 0)//minus for numerator
					{
						checkminus *= -1;
					}

					if (prscanner == '/' && minusend == false)//minus for denominator
					{
						checkminus *= -1;
						minusend = true;
					}

				}

				prscanner = input[i];//update previous char

				if (scanner >= '0' && scanner <= '9')//if digit add char(int)
				{
					curscannum *= 10;
					curscannum += scanner - '0';
				}

				if (i + 1 == input.size())//at the end set denominator
				{
					if (slash == true)//if numerator was set, set denominator
					{
						denom = curscannum * checkminus;
						if (denom == 0) throw 2;//check for divide by 0
						std::cout << "denominator is " << denom << "\n";
					}
					else//if not set numerator
					{
						numer = curscannum * checkminus;
						if (numer == 0) throw 3;
						std::cout << "numerator is " << numer << "\n";
					}


				}
			}
			else//if wrong input end
			{
				throw 1;
			}


		}
		setrational(numer, denom);//save and simplify values
		std::cout << "The set number is: " << getnumerator() << "/" << getdenominator() << std::endl;
		
	}
	catch (int e)//just catch
	{
		if (e == 1)
		{
			std::cout << "Wrong input, allow only digits - and /, number set as 0/1" << std::endl;
			exit(0);
		}

		if (e == 2)
		{
			std::cout << "Wrong input, denominator is 0" << std::endl;
			exit(0);
		}

		if (e == 3)
		{
			std::cout << "Wrong input, numerator is 0" << std::endl;
			exit(0);
		}
	}
	
}