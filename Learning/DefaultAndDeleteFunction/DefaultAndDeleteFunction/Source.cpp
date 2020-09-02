#include <iostream>
#include <vector>
using namespace std;

class Someclass
{
public:
	Someclass() = default; // use compiler-generated default constructor
	// disable copy constructor and copy assignment operator:
	Someclass(const Someclass &) = delete;
	Someclass & operator=(const Someclass &) = delete;
	// use compiler-generated move constructor and move assignment operator:
	Someclass(Someclass &&) = default;
	Someclass & operator=(Someclass &&) = default;
	Someclass & operator+(const Someclass &) const;
};

int main()
{
	Someclass one;
	Someclass two;
	//Someclass three(one); // not allowed, one an lvalue
	//Someclass four(one + two); // allowed, expression is an rvalue
	return 0;
}