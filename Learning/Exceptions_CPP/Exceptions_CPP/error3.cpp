#include <iostream>

using namespace std;

double hmean3(double x, double y);

int temp3()
{
	double x, y, z;
	cout << "Enter two numbers: \n";
	while (cin >> x >> y)
	{
		try 
		{
			z = hmean3(x, y);
		}
		catch (const char *s) // start of exception handler
		{
			cout << s << endl;
			cout << "Enter a new pair of numbers: ";
			continue;
		}
		cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << endl;
		cout << "Enter next set of numbers <q to quit>: ";
	}
	cout << "Bye";

	return 0;
}

double hmean3(double a, double b)
{
	if (a == -b)
		throw "bad hmean() arguments: a = -b not allowed";
	return 2.0 * a * b / (a + b);
}