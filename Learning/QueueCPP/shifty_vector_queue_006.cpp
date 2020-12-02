#include <iostream>
#include <vector>

struct widget {
    widget(size_t size) {
        fifo.reserve(size);
        front = fifo.begin();
    }

    int pop() {
        return *front++; 
    }

    bool empty() const {
        return front == fifo.end();
    }

    void push(int i) {
        std::vector<int>::difference_type x;
        if(fifo.size() == fifo.capacity()) {
            if(front != fifo.begin()) 
                fifo.erase(fifo.begin(), front);
            x = 0;
        } else {
            x = front - fifo.begin();
        }
        fifo.push_back(i);
        front = fifo.begin() + x;
    }

    int getfront() {
        return *front;
    }

    std::vector<int> fifo;
    std::vector<int>::iterator front;
};

int main() {

    return 0;
}
