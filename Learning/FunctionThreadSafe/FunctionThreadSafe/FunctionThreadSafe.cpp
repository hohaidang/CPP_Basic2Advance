#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <atomic>
#include <cmath>
using namespace std;

class Polynominal
{
public:
	using RootsType = vector<double>;
	RootsType roots() const
	{
		lock_guard<mutex> g(m); // lock mutex
		if (!rootsAreValid) // if cache not valid
		{
			//... compute roots here

			rootsAreValid = true; // release mutex
		}
		return rootVals;
	}
private:
	mutable mutex m;
	mutable bool rootsAreValid{ false };
	mutable RootsType rootVals{};
};

Polynominal p;
void func1()
{
	auto rootsOfP = p.roots();
}

void func2()
{
	auto valsGivingZero = p.roots();
}

class Point
{
public:
	double distanceFromOrigin() const noexcept
	{
		++callCount;
		cout << callCount << "\n";
		return sqrt((x*x) + (y*y));
	}
private:
	mutable atomic<unsigned> callCount{ 0 };
	double x, y;
};


int main()
{
	/*thread t1(func1);
	thread t2(func2);
	t1.join();
	t2.join();*/
	return 0;
}