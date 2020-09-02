#include <iostream>
#include <algorithm>
#include <array>
#include <chrono>
#include <vector>
using namespace std;

struct MyLocalData
{
	int value1;
	int value2;
	int value3;

	//MyLocalData(BigObject const& bigObject, LargeAPI const& largeAPI)
	//	: value1(getValue1(bigObject)
	//		, value2(getValue2(bigObject, largeAPI)
	//			, value3(getValue3(largeAPI))
	//{}
};

void blink_led(std::chrono::milliseconds time_to_blink)
{
	cout << "Dang";
}

void use()
{
	blink_led(1500ms);
}
int main()
{


	
	return 0;
}