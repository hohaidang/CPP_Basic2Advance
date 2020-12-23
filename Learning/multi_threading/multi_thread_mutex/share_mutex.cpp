#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <shared_mutex>
using namespace std;

shared_mutex s_mutex;
int counter = 0;

/*shared mutex de dam bao rang trong luc ghi thi chi co 1 thread duoc ghi
  trong luc doc thi se khong co thread nao dang ghi*/
void writer() {
	lock_guard<shared_mutex> lg(s_mutex); /* make sure only one thread is writing */
	//unique_lock<shared_mutex> ul(s_mutex);
	for (int i = 0; i < 100; ++i) {
		++counter;
	}
}

void reader() {
	/* make sure no one thread is writing */
	shared_lock<shared_mutex> sl(s_mutex);
	cout << "Current counter: " << counter << endl;
}

int main() {
	const int number_of_thread = 100;
	vector<thread> v_threads;
	const int N = 1000;

	for (int i = 0; i < number_of_thread; ++i) {
		v_threads.push_back(thread(writer));
		v_threads.push_back(thread(reader));
	}

	for(auto &thread : v_threads) {
		thread.join();
	}

	return 0;
}