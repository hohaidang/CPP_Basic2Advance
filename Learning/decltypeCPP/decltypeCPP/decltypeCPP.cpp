// decltypeCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class Widget {};

template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) // return type will be auto and is declared by result of (a + b)
										// If dont define "decltype" keyword, what type will be return? 
										// for eg: double add(T1 a, T2 b) ? what if T1 and T2 is double?
{
	return a + b;
}

int main()
{
	Widget w;
	const Widget &cw = w;
	auto myWidget1 = cw;// auto type deduction:
						// myWidget1's type is Widget

	decltype(auto) myWidget2 = cw;// decltype type deduction:
								 // myWidget2's type is
								 //   const Widget&

	auto data1 = add(10, "A");
	auto data2 = add(3, 5);
	cout << typeid(w).name() << "\n";

	std::vector<int> v;
	v.push_back(5);
	unsigned sz = v.size();
	cout << sz << "\n";
	cout << sizeof(unsigned __int64) << "\n";
	cout << sizeof(unsigned) << "\n";
	for (auto i = 0; i < 10; ++i)
	{
		cout << "Dang";
	}
}

