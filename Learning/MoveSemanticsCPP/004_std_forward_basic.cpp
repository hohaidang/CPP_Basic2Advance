#include <cstdio>
#include <utility>
#include <iostream>

using std::puts;

struct S{};

void f(S& s) {
    puts("f(S&)");
}

void f(S&& s) {
    puts("f(S&&)");
}

template<typename T>
void wrap(T&& s){
    // f(s);
    f(std::forward<T>(s)); // neu khong co std::forward o day
    // thi khi goi wrap(S(s)), vao function wrap no van se hieu s la lvalue
    // std:: forward de cho biet s van la l value do do se goi ham f(S&& s)
}

int main() {
    S s;
    f(s);
    f(S(s)); // cai nay se goi f(S&& s) vi la rvalue
    wrap(s);
    wrap(S(s));
}
