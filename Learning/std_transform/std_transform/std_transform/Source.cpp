#include <algorithm>
#include <iostream>
using namespace std;

struct decrement {
	decrement(int i) : temp_(i) {
		cout << "constructor called" << endl;
	}

	int operator()(const int& _Left) const {
		cout << "operator called" << endl;
		cout << "_left = " << _Left << endl;
		return _Left - temp_;
	}

private:
	int temp_ = 0;
};

int main() {
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 4, 5, 6 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int res[3];

	auto decrement2 = [](int i, int b) {
		return i;
	};

	std::transform(arr1, arr1 + n, arr1, decrement(2));
	//std::transform(arr1, arr1 + n, arr1, decrement2(2));
	for (int i = 0; i < n; ++i) {
		std::cout << arr1[i] << " ";
	}

	return 0;
}