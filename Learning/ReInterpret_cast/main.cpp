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
//	cout << "Hello World" << endl;
//	int* p = new int(65);
//	char *ch = reinterpret_cast<char*>(p);
//	cout << *p << endl;
//	cout << *ch << endl;
//	cout << p << endl;
//	cout << ch << endl;
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//struct mystruct
//{
//	int x;
//	int y;
//	char c;
//	bool b;
//};
//
//int main()
//{
//	mystruct s;
//	s.x = 5;
//	s.y = 10;
//	s.c = 'a';
//	s.b = true;
//
//	int *p = reinterpret_cast<int *>(&s);
//	cout << "size(s) == " << sizeof(s) << endl;
//	cout << "*p = " << *(p) << endl;
//	p++;
//	cout << "*(p+1) = " << *p << endl;
//	p++;
//	char *ch = reinterpret_cast<char *>(p);
//	cout << "*ch = " << *ch << endl;
//	ch++;
//	bool *n = reinterpret_cast<bool *>(ch);
//	cout << "*(n) = " << *n << endl;
//}



#include <iostream>
using namespace std;

class A
{
public:
	int a = 5;
	void fun_a()
	{
		cout << "In class A\n";
	}
	bool Yes()
	{
		return 1;
	}
};

class B
{
public:
	void fun_b()
	{
		cout << "In class B\n";
	}
};

bool TestFun(B* K)
{
	return reinterpret_cast<A*>(K)->Yes();
}

int main()
{
	B* x = new B();
	bool BoolTest = TestFun(x);
	cout << "BoolTest = " << BoolTest << endl;
	A* new_a = reinterpret_cast<A*>(x);
	new_a->fun_a();
//	new_a->fun_b(); // Error
	x->fun_b();


	return 0;
}
