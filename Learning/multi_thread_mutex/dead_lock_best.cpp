#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <shared_mutex>
using namespace std;
#define BEST_PRACTIS
mutex m1, m2;
int counter = 0;

#ifdef DEAD_LOCK
void increase1() {
	lock_guard<mutex> lg1(m1);
	lock_guard<mutex> lg2(m2);
	for (int i = 0; i < 100; ++i) {
		++counter;
	}
}

void increase2() {
	lock_guard<mutex> lg1(m2);
	lock_guard<mutex> lg2(m1);
	for (int i = 0; i < 100; ++i) {
		++counter;
	}
}
#endif

void increase_better() {
	lock(m1, m2); /*LOCK tat ca m1, m2 hoac la khong lock gi ca*/
	lock_guard<mutex> lg1(m1, adopt_lock); // assume mutex is already lock
	lock_guard<mutex> lg2(m2, adopt_lock);
	for (int i = 0; i < 100; ++i) {
		++counter;
	}
}

void increase_best() {
	std::scoped_lock lock(m1, m2);
	++counter;
}
int main() {
	const int number_of_thread = 100;
	vector<thread> v_threads;
	const int N = 1000;

	for (int i = 0; i < number_of_thread; ++i) {
#ifdef DEAD_LOCK
		v_threads.push_back(thread(increase1));
		v_threads.push_back(thread(increase2));
#endif
#ifdef BETTER
		v_threads.push_back(thread(increase_better));
#endif
#ifdef BEST_PRACTIS
		v_threads.push_back(thread(increase_best));
#endif
	}

	for(auto &thread : v_threads) {
		thread.join();
	}

	return 0;
}