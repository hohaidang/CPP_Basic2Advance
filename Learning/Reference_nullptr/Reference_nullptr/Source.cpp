#include <iostream>
#include <memory>
#include <gsl.h>
using namespace std;

void addRef(int &a)
{
	cout << "add is called" << endl;
	a = a + 5;
}

void addPtr(int *a)
{
	*a = *a + 5;
}

void checkNotNull(gsl::not_null<int *> p)
{
	cout << "Dang";
}

int main()
{
	int *a = new int (5);
	cout << *a << endl;

	a = 0;
	//addRef(*a); // error will occur because reference cannot get null_ptr
	//addPtr(a);
	//checkNotNull(a);
	return 0;
}