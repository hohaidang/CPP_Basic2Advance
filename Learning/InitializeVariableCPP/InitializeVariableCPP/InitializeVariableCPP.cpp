// InitializeVariableCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Widget
{
private:
	int x{ 0 };
	int y = 0;
	//int z(0); // error
};

int main()
{
	//int x(0); // initializes is in paratheses
	//int y = 0; // initializes follow "="
	//int z{ 0 }; // initializes in braces
	
	double x = 0, y = 0, z = 0;
	//int sum1{ x + y + z }; // good 
							//error! sum of doubles
							// may not be expressible as int
	//int sum2(x + y + z); // not good
	//int sum3 = x + y + z; //not good because double assign to in

	for (int i{ 0 }; i < 10; ++i)
	{
		cout << "Dang";
	}

	char a = 'a';
	int b{ a };

}

