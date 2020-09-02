#include "exc_mean.h"
#include <cmath>
#include <string>
using namespace std;

class demo
{
private:
	string word;
public:
	demo(const string &str) : word(str)
	{
		cout << "demo " << word << "created\n";
	}

	~demo()
	{
		cout << "demo " << word << " destroyed\n";
	}

	void show() const
	{
		cout << "demo " << word << " lives!\n";
	}
};

double hmean5(double a, double b);
double gmean5(double a, double b);
double means5(double a, double b);

int temp5()
{
	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "Enter two numbers: ";
		while (cin >> x >> y)
		{
			try
			{
				z = means5(x, y);
			}
			catch (bad_hmean &bg)
			{
				bg.mesg();
				cout << "Try again\n";
				continue;
			}
			catch (bad_gmean &hg)
			{
				cout << hg.mesg();
				cout << "Values used: " << hg.v1 << ", "
					<< hg.v2 << endl;
				cout << "Sorry, you don't get to play any more.\n";
				break;
			}
			d1.show();
		}
	}
	cout << "Bye!\n";
	cin.get();
	cin.get();
	return 0;
}

double hmean5(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean5(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return sqrt(a * b);
}

double means5(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0; // arithmetic mean
	try
	{
		hm = hmean5(a, b);
		gm = gmean5(a, b);
	}
	catch (bad_hmean &bg) // start of catch block
	{
		bg.mesg();
		cout << "Caught in means()\n";
		throw; // rethrows the exception for main
		// d2 deconstructor will be destroyed here.
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}