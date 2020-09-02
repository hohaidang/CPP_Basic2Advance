#include "exc_mean.h"
#include <cmath>

double hmean4(double a, double b);
double gmean4(double a, double b);

int temp4()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean4(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean4(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (bad_hmean &bg)
		{
			bg.mesg();
			cout << "Try again. \n";
			continue;
		}
		catch (bad_gmean &hg)
		{
			cout << hg.mesg();
			cout << "Value used: " << hg.v1 << ", "
				<< hg.v2 << endl;
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}

double hmean4(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean4(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}