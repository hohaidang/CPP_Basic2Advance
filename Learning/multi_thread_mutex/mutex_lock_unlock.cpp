#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex g_mutex;
int counter = 0;

void increase_counter() {
	/* can't never lock 2 consequence times. If forget to unlock, will lead to dead lock*/
	g_mutex.lock();
	++counter;
	g_mutex.unlock();
}

void increase_counter_guard() {
	/* lock_guard is simillar to mutex lock but automatically unlock after out of scope 
	   constructor and decontructor */
	lock_guard<mutex> l_guard(g_mutex);
	++counter;
}

void increase_counter_unique() {
	/* unique lock is lock_guard + normal lock. It will automatically unlock after out of scope
	   but can allow to lock and unlock in the scope */
	unique_lock<mutex> u_lock(g_mutex);
	++counter;
	// do something
	u_lock.unlock();
	// do something
	u_lock.lock();
}

int main() {
	const uint32_t number_of_threads = 100;
	
	int N = 1000;
	for (int i = 0; i < N; ++i) {
		vector<thread>  v_threads;
		for (uint32_t j = 0; j < number_of_threads; ++j) {
			v_threads.push_back(thread(increase_counter_unique));
		}

		for (auto& thread : v_threads) {
			thread.join();
		}

		cout << counter << ", ";
	}


	return 0;
}