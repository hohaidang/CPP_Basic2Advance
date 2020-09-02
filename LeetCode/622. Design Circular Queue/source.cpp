#include <iostream>
#include <mutex>
#include <vector>
#include <memory>
using namespace std;

class MyCircularQueue {
private:
    vector<int> queue;
    int count;
    int head;
	std::mutex mutex_;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : count(0), head(0) {
        queue.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
		std::lock_guard<std::mutex> lock(mutex_);
        if(count == queue.size()) {
            return false;
        }
        queue[(head + count) % queue.size()]  = value;
        count += 1;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        std::lock_guard<std::mutex> lock(mutex_);
        if(count == 0) {
            return false;
        }
        head = (head + 1) % queue.size();
        count -= 1;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return (count == 0) ? -1 : queue[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return (count == 0) ? -1 : queue[(head + count - 1) % queue.size()];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count == queue.size();
    }
};

int main() {
	MyCircularQueue q = MyCircularQueue(3);
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	cout << "rear = " << q.Rear();
	cout << "head = " << q.Front();
	return 0;
}