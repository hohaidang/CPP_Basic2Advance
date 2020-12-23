#include <iostream>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <array>
#include <cstdlib>

template<typename T>
class ThreadSafeQueue {
public:
    constexpr ThreadSafeQueue() : m_ptr(0) {};
    void push(T &input) {
        if(full())
            return; // queue is full
        m_queue[m_ptr] = input;
    }

    void pop() {
        if(empty())
            return;
        ++m_ptr;
    }

    T& front() {
        return m_queue[m_ptr];
    }

    bool empty() {
        return (m_ptr == 0);
    }

    bool full() {
        return (m_ptr == 299);
    }
private:
    std::array<T, 300> m_queue;
    size_t m_ptr;
};

int main() {
    
    std::cout << "Hello WOrld\n";
    ThreadSafeQueue<int> my_queue = ThreadSafeQueue<int>();
    for(int i = 0; i < 10; ++i) {
        srand (time(NULL));
        int a = rand();
        int b = rand();
        my_queue.push(a);
        my_queue.push(b);
    }

    auto printQueue = [&](size_t length){
        for(size_t i = 0; i < length; ++i) {
            std::cout << my_queue.front() << "  ";
        }
    };

    printQueue(5);
    return 0;
}