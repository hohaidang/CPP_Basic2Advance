#include <iostream>

using namespace std;

class non_Polimophic
{
	int a;
};

class Polimophic
{
	int a;
	virtual void test() = 0;
	virtual void test1() = 0; // increase number of virual funtion does not increase size of Polimophic object
};

class Base
{
public:
	int baseData = 10;
	virtual void print()
	{
		cout << "This is base class" << endl;
	}
};

// TODO change ve private tim cach fix loi
class Derived : public Base
{
public:
	int derivedData = 5;
	virtual void print() override
	{
		cout << "This is derived class" << endl;
	}
};

int main()
{
	/*------------Size------------*/
	cout << "non_Polimic size = " << sizeof(non_Polimophic) << endl;
	cout << "Polimic size = " << sizeof(Polimophic) << endl; // size of cua polimophic object luon lon hon size cua non_polimophic (thuong la size cua con tro)

	/*---------Casting---------*/
	Base *b1 = new Derived;
	Base *b2 = new Base;

	Derived *s1 = static_cast<Derived *>(b1); // derivedData = 5 because b2 is a Derived class
	Derived *s2 = static_cast<Derived *>(b2); // derivedData in Derived class will get dump value because b1 is just a Base Class, because memory location of derivedData is not allocated

	/* De tranh mat thong tin sau khi ep kieu nhu s2 thi nguoi ta co the dung dynamic_cast cho polimic objects. Boi vi type of object duoc encode trong polymic object */
	Derived* d1 = dynamic_cast<Derived *>(b1); // Succeeds
	Derived* d2 = dynamic_cast<Derived *>(b2); // d2 == nullptr boi vi b2 khong phai la Derived class
	cout << d2;
	return 0;
}