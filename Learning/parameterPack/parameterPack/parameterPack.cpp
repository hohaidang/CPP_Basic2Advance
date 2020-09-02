#include <iostream>
#include <string>
using namespace std;

template <typename T>
T adder(T v)
{
	return v;
}

template <typename T, typename... Args>
T adder(T first, Args...args)
{
	return first + adder(args...);
}

// this function will be call at the end of recursion
void show_list3() { cout << "\n"; }

template<typename T, typename ...Args>
void show_list3(const T& value,const Args&...args) noexcept
{
	cout << value << ", ";
	show_list3(args...); // call show_list3 recursion
}

int main()
{
	auto sum = adder(1, 2, 3, 4, 6, 8);
	int n = 14;
	double x = 2.71828;
	string mr = "Mr. String objects!";
	show_list3(n, x);
	show_list3(x*x, '!', 7, mr);
	
	return 0;
}