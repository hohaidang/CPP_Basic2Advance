/*CircularQueue is also call ring buffer*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

	class MyCircularQueue {
	private:
		vector<int> data;
		int head, tail, size;
	public:
		MyCircularQueue(int n) : head(-1), tail(-1), size(n) {
			data.resize(n);
		}

		bool enQueue(int val) {
			if(isFull())
				return false;
			if(isEmpty())
				head = 0;
			tail = (tail + 1) % size;
			data[tail] = val;
			return true;
		}

		bool deQueue() {
			if(isEmpty())
				return false;
			if(head == tail) {
				head = -1;
				tail = -1;
				return true;
			}
			head = (head + 1) % size;
			return true;
		}

		int Front(){
			return isEmpty() ? -1 : data[head];
		}

		int Rear() {
			return isEmpty() ? -1 : data[tail];
		}

		bool isEmpty() {
			return head == -1;
		}
		bool isFull() {
			return ((tail + 1) % size) == head;
		}
	};

int temp()
{
	MyCircularQueue q = MyCircularQueue(5);
	for(int i = 0; i < 5; ++i) {
		q.enQueue(i);
	}
	cout << "Head = " << q.Front() << endl;
	cout << "Tail = " << q.Rear() << endl;
	q.deQueue();
	q.deQueue();
	q.enQueue(5);
	q.enQueue(6);
	cout << "New head = " << q.Front() << endl;
	cout << "New tail = " << q.Rear() << endl;
	cout << "New head = " << q.Front() << endl;
	cout << "New tail = " << q.Rear() << endl;
	return 0;
}
