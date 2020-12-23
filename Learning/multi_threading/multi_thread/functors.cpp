#include <vector>
#include <array>
#include <thread>
#include <iostream>
#include "utility.h"
using namespace std;

struct acceleration_range {
	void operator()(uint64_t start, uint64_t end) {
		for (uint64_t i = start; i < end; ++i) {
			sum_ += i;
		}
	}

	uint64_t sum_ = 0;
};

int main() {
	const uint64_t number_of_threads = 10;
	const uint64_t number_of_elements = 1000 * 1000 * 1000;
	const uint64_t steps = number_of_elements / number_of_threads;

	vector<thread> v_threads;
	vector<acceleration_range> functors(number_of_threads);

	for (uint64_t i = 0; i < number_of_threads; ++i) {
		v_threads.push_back(thread(ref(functors[i]), steps * i, steps * (i + 1)));
	}

	for (auto &thread : v_threads) {
		thread.join();
	}

	uint64_t sum_ = 0;
	for (int i = 0; i < number_of_threads; ++i) {
		sum_ += functors[i].sum_;
	}

	cout << "sum_ = " << sum_ << endl;
	return 0;
}