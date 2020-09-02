#include <iostream>
#include <memory>
using namespace std;

/* Muc dich bai nay la tu implement shared pointer */

template<class T>
class Shared_ptr {
public:
    int* counter_ = new int(0);
    T* ptr_;
public:
    // constructor
    Shared_ptr(T *ptr = nullptr) {
        ptr_ = ptr;
        if (ptr_ != nullptr) {
            ++(*counter_);
        }
    }

    // assignment operator
    Shared_ptr(const Shared_ptr& data) {
        ptr_ = data.ptr_;
        counter_ = data.counter_; // lay con tro tro vao dia chi cua class goc, de neu cong tru thi se cong tru tren cai counter goc, khong phai cai moi
        if (data.ptr_ != nullptr) {
            ++(*counter_);
        }
    }

    ~Shared_ptr() {
        cout << "Destructor is called" << endl;
        --(*counter_);
        if (*counter_ == 0) {
            cout << "Delete is called" << endl;
            delete ptr_;
            delete counter_;
        }
    }

    T operator*() {
        return *ptr_;
    }
};


int main() {
    Shared_ptr<int> a(new int(15));
    cout << "*a = " << *a << endl; // *operator
    cout << "a counter = " << *a.counter_ << endl;
    {
        Shared_ptr<int> b(a);
        cout << "b counter = " << *b.counter_ << endl;
        cout << "a counter = " << *a.counter_ << endl;
    }

    cout << "a counter = " << *a.counter_ << endl;
    return 0;
}