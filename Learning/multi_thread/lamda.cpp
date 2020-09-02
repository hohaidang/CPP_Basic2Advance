#include <vector>
#include <array>
#include <thread>
#include <iostream>
#include "utility.h"
using namespace std;


int main() {
	const uint64_t number_of_threads = 10;
	const uint64_t number_of_elements = 1000 * 1000 * 1000;
	const uint64_t steps = number_of_elements / number_of_threads;

	array<uint64_t, number_of_threads> partitions_sum = {};
	vector<thread> v_threads;

	for (uint64_t i = 0; i < number_of_threads; ++i) {
		v_threads.push_back(thread([&partitions_sum, i, steps]() {
			uint64_t start = steps * i;
			uint64_t stop = steps * (i + 1);
			for (uint64_t j = start; j < stop; ++j) {
				partitions_sum[i] += j;
			}
		}));
	}

	for (auto& m_thread : v_threads) {
		m_thread.join();
	}

	uint64_t sum_ = 0;
	for (auto& part_sum : partitions_sum) {
		sum_ += part_sum;
	}


	cout << "sum = " << sum_ << endl;
}