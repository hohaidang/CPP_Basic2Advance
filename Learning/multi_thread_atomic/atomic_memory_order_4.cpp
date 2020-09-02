#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>
using namespace std;

/* Muc dich cua bai nay la phan biet su khac nhau giua memory_order_relaxed, memory_order_seq_cst, memory_order_acquire, memory_order_release
*  Phan nay van chua chac 100%, xem lai sau TODO:
   memory_order_seq_cst la default cua atomic, no se sychronize tat ca cac load va store cua cac thread
   memory_order_acquire, memory_order_release la khi store() thi dung acquire, khi load() thi dung acquire, no se dong bo giua acquire va release vs nhau
   memory_order_relaxed: la khong dong bo gi ca, compiler co the thoai mai thay doi vi tri cua code. co the dan den sai
*/

atomic<bool> x{ false };
atomic<bool> y{ false };
int z = 0;

void thread1() {
	x.store(true, memory_order_relaxed);
}

void thread2() {
	y.store(true, memory_order_relaxed);
}

void thread3() {
	//while (!x.load(memory_order_relaxed));
	if (y.load(memory_order_relaxed) == true && x.load(memory_order_relaxed) == true) {
		++z;
	}
}

void thread4() {
	/*while (!y.load(memory_order_relaxed));*/
	if (x.load(memory_order_relaxed) && y.load(memory_order_relaxed)) {
		++z;
	}
}

void sleep(unsigned ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main() {
	thread t1(thread1);
	thread t2(thread2);
	thread t3(thread3);
	thread t4(thread4);
	t4.join();
	t3.join();
	sleep(100);
	t2.join();
	t1.join();


	cout << "z = " << z << endl;
}
