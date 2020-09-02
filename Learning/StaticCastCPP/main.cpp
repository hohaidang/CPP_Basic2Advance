/*
 * main.cpp
 *
 *  Created on: Jan 20, 2020
 *      Author: prnsoft
 */



//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	char c = 'a';
//
//	int *q = (int *)&c;
//	cout << "*q = " << *q << endl;
//
////	int *p = static_cast<int*>(&c); // ERROR occur
////	cout << "*q = " << *q << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//class Int
//{
//	int x;
//public:
//	Int(int x_in = 0) : x{ x_in }
//	{
//		cout << "Conversion Ctor called" << endl;
//	}
//	operator string()
//	{
//		cout << "Conversion Operator" << endl;
//		return to_string(x);
//	}
//};
//
//int main()
//{
//	Int obj(3);
//	string str = obj;
//	obj = 20;
//	string str2 = static_cast<string>(obj);
//	obj = static_cast<Int>(30);
//	return 0;
//}


#include <iostream>
using namespace std;
class Base{};
class Derived : private Base {};
int main()
{
	Derived d1;
	Base* b1 = (Base*)(&d1); // allowed
//	Base* b2 = static_cast<Base*>(&d1);
	cout << "HelloWorld";
	return 0;
}
