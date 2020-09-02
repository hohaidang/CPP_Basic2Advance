#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include "utility.h"

using namespace std;

void AccumulateRange(uint64_t& sum, uint64_t start, uint64_t end) {
	for (int i = start; i < end; ++i) {
		sum += i;
	}
}

/* Create 2 threads, for increasing number 1000 * 1000 * 1000, each thread handle a half number */
int main() {
	const int number_of_threads = 2;
	const int number_of_elements = 1000 * 1000 * 1000;

	vector<uint64_t> partical_sum(number_of_threads);
	thread t1(AccumulateRange, ref(partical_sum[0]), 0, number_of_elements / 2);
	thread t2(AccumulateRange, ref(partical_sum[1]), number_of_elements / 2, number_of_elements);

	t1.join();
	t2.join();

	/* sau khi t1 va t2 ket thuc thi no moi nhay xuong dong nay */
	uint64_t sum = 0;
	sum = accumulate(partical_sum.begin(), partical_sum.end(), static_cast<uint64_t>(0)); /*add sum[0] + sum[1]*/
	PrintVector(partical_sum);
	cout << "sum = " << sum;
}