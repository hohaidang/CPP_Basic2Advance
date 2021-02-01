#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <list>
using namespace std;

//void abssort(float* x, unsigned n)
//{
//	std::sort(x, x + n,
//		// Lambda expression begins
//		[](float a, float b) {
//			return (std::abs(a) < std::abs(b));
//		} // end of lambda expression
//	);
//}


int temp()
{
	int a = 5;
	int b = 10;
	auto f1 = [](int x, int y) 
	{ 
		return x + y; 
	
	};
	int c = f1(a, b);
	cout << f1(2, 3) << endl;

	function<int(int, int)> f2 = [](int x, int y) { return x + y; };
	cout << f2(3, 4) << endl;


	int i = 3;
	int j = 5;
	// The following lambda expression captures i by value and
	// j by reference.
	function<int(void)> f = [i, &j] { return i + j; };

	// Change the values of i and j.
	i = 22;
	j = 44;

	// Call f and print its result.
	cout << f() << endl;

	using namespace std;
	int n = [](int x, int y) { return x + y; }(5, 4);
	cout << n << endl;

	list<int> numbers;
	numbers.push_back(13);
	numbers.push_back(17);
	numbers.push_back(42);
	numbers.push_back(46);
	numbers.push_back(99);

	// Use the find_if function and a lambda expression to find the
	// first even number in the list.
	const list<int>::const_iterator result =
		find_if(numbers.begin(), numbers.end(), [](int n) { return (n % 2) == 0; });
	if (result != numbers.end()) {
		cout << "The first even number in the list is " << *result << "." << endl;
	}
	else {
		cout << "The list contains no even numbers." << endl;
	}

	return 0;
}

