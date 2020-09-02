#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void abssort(float* x, unsigned n) {
	std::sort(x, x + n,
		// Lambda expression begins
		[](float a, float b) {
		return (std::abs(a) < std::abs(b));
	} // end of lambda expression
	);
}

int main()
{
	float arr[5] = { 10.3, -5.7, 6.3, 2.2, 0.1 };
	abssort(arr, 5);
	for (const int& i : arr)
		cout << "array[" << i << "] = " << arr[i] << endl;
	return 0;
}