#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
private:
	vector<int> data;
	int p_start;

public:
	MyQueue() {p_start = 0;}
	bool enQueue(int x) {
		data.push_back(x);
		return true;
	}

	bool deQueue() {
		if(isEmpty()) {
			return false;
		}
		p_start++;
		return true;
	}

	/* Get the front item from the queue */
	int Front() {
		return data[p_start];
	}

	bool isEmpty() {
		return p_start >= data.size();
	}
};

int temp2() {
	MyQueue queue;
	for(int i = 0; i < 2; ++i) {
		queue.enQueue(i);
	}
	int i = 0;
	while(1) {
		if (queue.isEmpty()) break;
		cout << "Deque[" << i++ << "] = " << queue.Front() << endl;
		queue.deQueue();
	}
	return 0;
}
