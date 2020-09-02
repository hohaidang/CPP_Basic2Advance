#include <iostream>
using namespace std;

class Foo
{
private:
	int m_foo;
public:
	//Foo(int foo) : m_foo(foo) {};
	explicit Foo(int foo) : m_foo(foo) {};
	int getFoo() { return m_foo; };
};

int DoBar(Foo foo)
{
	return foo.getFoo();
}

int main()
{
	/*Argument is int but still can be an argument of class Foo
	This is a implicit conversion from compiler*/
	//int Data = DoBar(42);  
	int Data = DoBar(Foo(42)); // When "explicit" is declare, argument must be class of Foo
	cout << "Data = " << Data << endl;
	return 0;
}