#include <vector>
#include <iostream>
#include <thread>
#include <future>

using namespace std;

/*async is used for mutilthread function wants to return value rather than put reference.*/

uint64_t accelerate_range(uint64_t start, uint64_t stop) {
	uint64_t retVal = 0;
	for (auto i = start; i < stop; ++i) {
		retVal += i;
	}
	return retVal;
}

int main() {
	const uint64_t number_of_threads = 10;
	const uint64_t number_of_elements = 1000 * 1000 * 1000;
	const uint64_t steps = number_of_elements / number_of_threads;
	vector<future<uint64_t>> tasks; /*future<return type>*/

	for (uint64_t i = 0; i < number_of_threads; ++i) {
		tasks.push_back( async(accelerate_range, steps * i, steps*(i + 1)) );
	}

	uint64_t sum_ = 0;
	for (auto i = (uint64_t)0; i < tasks.size(); ++i) {
		sum_ += tasks[i].get(); /* get from thread return value */
	}

	cout << "sum_ = " << sum_;
}