#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
using namespace std;

atomic<long long> data_1, data_2;
void do_work_1() {
	data_1++;
}

void do_work_2() { 
	data_2.fetch_add(1);
}

int main() {
	atomic<int> a{ 5 };
	atomic<int> y = ++a; // equivalance to y = a.fetch_add(1) + 1, gan y = a roi sau do + 1
	atomic<int> b{ 5 };
	atomic<int> c = b.fetch_add(1); // gan roi moi cong

	cout << "y = " << y.load() << ", c = " << c.load() << ", b = " << b << endl; 


	vector<thread> threads;
	for (int i = 0; i < 5; ++i) {
		threads.push_back(thread(do_work_1));
		threads.push_back(thread(do_work_2));
	}

	for (thread& t : threads) {
		t.join();
	}

	cout << "data_1: " << data_1 << endl;
	cout << "data_2: " << data_2 << endl;
	return 0;
}