#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <string>
using namespace std;

atomic<int> flag{ 0 };
atomic<string *> msg; // cannot use variable string in atomic
// boi vi atomic cam xu dung copyable
int b = 0, x = 0, y = 0;
string *text;

/* Vi du nay cho ta thay viec sychronize giua cac thread thong qua memory order
   flag.store() se link voi flag.load()*/

void producer() {
	x = 3;
	y += x;
	string* p = new string("HelloWorld");
	msg = p;
	flag.store(1, std::memory_order_seq_cst); // flag.store() se make sure sychronize between producer and reader
	// dam bao flag.store se luon chay truoc flag.load nho co che memory_order_seq_cst
	b += flag;
}

void reader() {
	text = new string("Hi");
	while (flag.load() != 1); // thread reader nay de bi loop o day cho den khi flag.store dc active
	text = msg;
}

int main() {
	thread t1(producer);
	thread t2(reader);

	t2.join();
	t1.join();

	cout << "text = " << *text;
	return 0;
}