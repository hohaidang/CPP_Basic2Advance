#include <iostream>
#include <vector>
using namespace std;

class A
{
	int *ptr;
public:
	A()
	{
		cout << "Calling default constructor\n";
		ptr = new int;
	}

	// this constructor will be called when argument is a lvalue
	A(const A & obj)
	{
		// Copy constructor
		// copy of object is created
		this->ptr = new int;
		// deep copying
		cout << "Calling copy constructor\n";
	}

	// this constructor will be called when argument is a rvalue
	A(A && obj)
	{
		// Move constructor
		// It will simply shift the resource,
		// without creating a copy
		cout << "Calling move constructor\n";
		this->ptr = obj.ptr;
		obj.ptr = NULL;
	}

	~A()
	{
		cout << "Calling destructor\n";
		delete ptr;
	}
};

int main()
{
	int &&j = 20; // rvalue reference
	int k = 20;
	cout << "adr j = " << &j << endl;
	cout << "adr k = " << &k << endl;

	vector <A> vec;
	vec.push_back(A()); // A() is consider as rvalue so that move constructor will be called
	//A b = A(A());
	return 0;
}