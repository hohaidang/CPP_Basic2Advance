#include <iostream>
#include <vector>
#include <thread>
#include <array>
#include <numeric>
//#include "utility.h"
using namespace std;

void accumulateRange(uint64_t &sum, uint64_t start, uint64_t end) {
	for (uint64_t i = start; i < end; ++i) {
		sum += i;
	}
}

int main() {
	const uint64_t num_of_threads = 10;
	uint64_t num_elements = 1000 * 1000 * 1000;
	uint64_t step = num_elements / num_of_threads;
	array<uint64_t, num_of_threads> sum_partitions = {};

	vector<thread> v_thread;
	for (uint64_t i = 0; i < num_of_threads; ++i) {
		v_thread.push_back(thread(accumulateRange, ref(sum_partitions[i]), step * i, step * (i + 1)));
	}

	for (uint64_t i = 0; i < num_of_threads; ++i) {
		v_thread[i].join();
	}

	for (uint64_t i = 0; i < num_of_threads; ++i) {
		cout << "array[" << i << "] = " << sum_partitions[i] << endl;
	}
	uint64_t sum = accumulate(sum_partitions.begin(), sum_partitions.end(), (uint64_t) 0);
	cout << "\nsum = " << sum;
}