#include <iostream>
#include <cstdlib>
using namespace std;
double hmean(double a, double b);

int temp()
{
	//int x = 5;
	//int y = -x;
	//int k = 2.0*x*y / (x + y); // divide for 0

	double x, y, z;
	cout << "Enter two number: ";
	while (cin >> x >> y)
	{
		z = hmean(x, y);
		cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << endl;
		cout << "Enter the next set of numbers <q to quit>: ";
	}
	cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		cout << "untenable arguments to hmean()\n";
		abort();
	}
	return 2.0 * a * b / (a + b);
}