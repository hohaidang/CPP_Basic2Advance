#include <iostream>

struct InternalMsg {
public:
    int k = 5;
    static constexpr const int GLOB = 50;

    static int add(int a, int b) { 
        return a + b;
    }

    // static int val() {
    //     return k; // error, static member function cannot access to local member of class
    // }

    static int val_glob() {
        return GLOB;
    }
};

int main() {
    // static member function can be call by <class_name>::<func_name>
    std::cout << InternalMsg::add(5, 6) << '\n'; // call static member function without using class declare
    std::cout << InternalMsg::val_glob() << '\n';
}