#include <iostream>
#include <array>
using namespace std;

constexpr
int pow(int base, int exp) noexcept
{
	return (exp == 0 ? 1 : base * pow(base, exp - 1));
}

int readFromDB(const char* s)
{
	return 1;
}

int temp()
{
	int sz;                             // non constexpr variable

	//constexpr auto arraysize1 = sz;   // error! sz's value not
										// known at compilation

	//std::array<int, sz> data1;        // error! same problem

	constexpr auto arraySize2 = 10;     // fine, 10 is a
										// compile-time constant

	array<int, arraySize2> data2;  // fine, arraySize2
										// is constexpr

	//const auto arraySize = sz;          // fine, arraySize is
										// const copy of sz

	//array<int, arraySize> data;  // error! arraySize's value
										// not known at compilation

  // compile-time-compute the size of a std::array:
	constexpr auto numConds = 5;                // # of conditions
	std::array<int, pow(3, numConds)> results;  // results has
												// 3^{numConds}
												// elements
	// runtime context:
	auto base = readFromDB("base");             // get these values
	auto exp = readFromDB("exponent");          // at runtime

	auto baseToExp = pow(base, exp);            // call pow function
												// at runtime
	return 0;
}