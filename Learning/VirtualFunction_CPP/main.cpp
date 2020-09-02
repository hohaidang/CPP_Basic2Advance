///*
// * main.cpp
// *
// *  Created on: Jan 20, 2020
// *      Author: prnsoft
// */
//#include <iostream>
//using namespace std;
//
//
//class base
//{
//public:
//	virtual void print()
//	{
//		cout << "print base class" << endl;
//	}
//
//	void show()
//	{
//		cout << "show base class" << endl;
//	}
//};
//
//class derived : public base
//{
//public:
//	void print()
//	{
//		cout << "print derived class" << endl;
//	}
//
//	void show()
//	{
//		cout << "show derived class" << endl;
//	}
//};
//
//int main()
//{
//	base *bptr;
//	derived d;
//	bptr = &d;
//	bptr->print();
//	bptr->show();
//	d.print();
//	d.show();
//}




//// CPP program to illustrate
//// working of Virtual Functions
//#include <iostream>
//using namespace std;
//
//class base {
//public:
//    void fun_1() { cout << "base-1\n"; }
//    virtual void fun_2() { cout << "base-2\n"; }
//    virtual void fun_3() { cout << "base-3\n"; }
//    virtual void fun_4() { cout << "base-4\n"; }
//};
//
//class derived : public base {
//public:
//    void fun_1() { cout << "derived-1\n"; }
//    void fun_2() { cout << "derived-2\n"; }
//    void fun_4(int x) { cout << "derived-4\n"; }
//};
//
//int main()
//{
//    base* p;
//    derived obj1;
//    p = &obj1;
//
//    // Early binding because fun1() is non-virtual
//    // in base
//    p->fun_1();
//
//    // Late binding (RTP)
//    p->fun_2();
//
//    // Late binding (RTP)
//    p->fun_3();
//
//    // Late binding (RTP)
//    p->fun_4();
//
//    // Early binding but this function call is
//    // illegal(produces error) becasue pointer
//    // is of base type and function is of
//    // derived class
//    // p->fun_4(5);
//}

/* Tai sao phai can dung virtual function trong khi co the dirive truc tiep
 * https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c*/
#include <iostream>


class Animal
{
public:
	virtual void eat()
	{
		std::cout << "I'm eating generic food." << std::endl;
	}
};

class Cat : public Animal
{
public:
	void eat()
	{
		std::cout << "I'm eating a rat." << std::endl;
	}
};

void func(Animal *xyz)
{
	xyz->eat();
}

int main()
{
	Animal *animal = new Animal;
	Cat *cat = new Cat;
	animal->eat();
	cat->eat();

	func(animal);
	func(cat);
}
