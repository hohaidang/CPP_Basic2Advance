///*
// * main.cpp
// *
// *  Created on: Jan 24, 2020
// *      Author: prnsoft
// */
//
//
//
//
//#include <iostream>
//using namespace std;
//
//class Test
//{
//private:
//	int x;
//	int y;
//public:
//	Test(int x = 0, int y = 0)
//	{
//		this->x = x;
//		this->y = y;
//	}
//	Test &setX(int a)
//	{
//		x = a;
//		return *this;
//	}
//	Test &setY(int b)
//	{
//		y = b;
//		return *this;
//	}
//	void print()
//	{
//		cout << " x = " << x << endl << "y = " << y << endl;
//	}
//};
//
//int main()
//{
//	cout << "HelloWorld" << endl;
//	Test obj1(5, 5);
//	obj1.setX(10).setY(20);
//	obj1.print();
//	return 0;
//}
#include <iostream>

class Foo
{
	private:
        int value;
    public:
        Foo()
        {
            this->value = 0;
        }

        Foo get_copy()
        {
            return *this;
        }

        Foo& get_copy_as_reference()
        {
            return *this;
        }

        Foo* get_pointer()
        {
            return this;
        }

        void increment()
        {
            this->value++;
        }

        void print_value()
        {
            std::cout << this->value << std::endl;
        }


};

int main()
{
    Foo foo;
    foo.increment();
    foo.print_value();

    foo.get_copy().increment(); // No increase
    foo.print_value();

    foo.get_copy_as_reference().increment();
    foo.print_value();

    foo.get_pointer()->increment();
    foo.print_value();

    return 0;
}
