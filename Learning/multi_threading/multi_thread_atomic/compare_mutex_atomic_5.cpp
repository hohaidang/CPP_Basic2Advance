#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

atomic<uint64_t> atomic_sum = 0;
mutex m_mutex;
uint64_t mutex_sum = 0;

void increasement_range_mutex(int start, int end) {
	uint64_t local_sum = 0;
	for (int i = start; i < end; ++i) {
		local_sum += i;
	}
	lock_guard<mutex> lg(m_mutex);
	mutex_sum += local_sum;
}

void increasement_range_atomic(int start, int end) {
	uint64_t local_sum = 0;
	for (int i = start; i < end; ++i) {
		local_sum += i;
	}

	atomic_sum += local_sum;
	//atomic_sum = atomic_sum + local_sum; // WRONG:
	// boi vi khi load atomicsum de thuc hien phep cong 1 thread khac co the se thay doi
	// bien atomic_sum, dan den ket qua sai
}

int main() {

	const uint64_t number_of_thread = 10;
	const uint64_t number_of_elements = 1000 * 1000 * 1000;
	const uint64_t steps = number_of_elements / number_of_thread;
	vector<thread> v_threads_mutex, v_threads_atomic;
	for (int i = 0; i < number_of_thread; ++i) {
		v_threads_mutex.push_back(thread(increasement_range_mutex, steps * i, steps * (i + 1ULL)));
		v_threads_atomic.push_back(thread(increasement_range_atomic, steps * i, steps * (i + 1ULL)));
	}

	// compute mutex
	auto start = chrono::system_clock::now();
	for (auto& thread : v_threads_mutex) {
		thread.join();
	}

	cout << "mutex_sum = " << mutex_sum << endl;
	auto end = chrono::system_clock::now();
	chrono::duration<double> time = end - start;
	cout << "mutex time = " << time.count() << endl;

	// compute atomic
	start = chrono::system_clock::now();
	for (auto& thread : v_threads_atomic) {
		thread.join();
	}

	cout << "atomic_sum = " << atomic_sum << endl;
	end = chrono::system_clock::now();
	time = end - start;
	cout << "atomic time = " << time.count() << endl;

	return 0;
}