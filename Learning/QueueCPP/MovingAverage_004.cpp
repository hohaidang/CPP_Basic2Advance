#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MyQueue {
private:
	vector<int> data;
	int head, tail, size;
public:
	MyQueue(int n) : head(-1), tail(-1), size(n) {
		data.resize(n);
	}
	MyQueue() = default;

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

	int Front() {
		return isEmpty() ? -1 : data[head];
	}

	int Back() {
		return isEmpty() ? -1 : data[tail];
	}

	double ComputeAverageAll() {
		if(isEmpty())
			return -1;
		double total = 0;
		double average = 0;
		for(int i = 0; i < size; ++i) {
			total += data[i];
		}
		if(tail >= head) {
			average = total / double(tail - head + 1);
		}
		else {
			average = total / double(size - head + tail + 1);
		}
		return average;
	}

	bool isEmpty() {
		return head == -1;
	}

	bool isFull() {
		return (tail + 1) % size == head;
	}
};


class MovingAverage {
private:
    int *array;
    int size = 0, head = 0, sum = 0, count = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int n) : size(n) {
        array = new int[n]();
    }
    
    double next(int val) {
        ++count;
        sum = sum - array[head] + val;
        array[head] = val;
        head = (head + 1) % size;
        
        return sum * 1.0 / min(count, size);
    }
};



int main() {
	MovingAverage1 m = MovingAverage1(3);
	cout << m.next(1) << endl;
	cout << m.next(10) << endl;
	cout << m.next(3) << endl;
	cout << m.next(5) << endl;
	return 0;
}



