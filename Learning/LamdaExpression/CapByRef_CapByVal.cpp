#include <iostream>
#include <string>
using namespace std;

int main()
{
	int counter = 10;
	auto func1 = [&]() { // capture by reference
		cout << "Before: " << counter << endl;
		counter = 20;

	};
	func1();
	cout << "After func1: " << counter << endl;
	// mutable because data input for lamda [=] is const
	auto func2 = [=] () mutable { // capture by value
		cout << "Before: " << counter << endl;
		counter = 30; // doesn't make outside lamda change value
	};
	cout << "After func2: " << counter << endl;
	return 0;
}