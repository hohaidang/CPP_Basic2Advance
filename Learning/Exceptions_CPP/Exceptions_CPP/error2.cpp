#include <iostream>
#include <cfloat>

using namespace std;

bool hmean(double a, double b, double *ans);

int error2()
{
	double x, y, z;
	cout << "Enter two number: ";
	while (cin >> x >> y)
	{
		if (hmean(x, y, &z))
			cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << endl;
		else
			cout << "One value should not be the negative "
			<< "of the other - try again.\n";
		cout << "Enter the next set of numbers <q to quit>: ";
	}
	cout << "Bye";
	return 0;
}

bool hmean(double a, double b, double * ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}