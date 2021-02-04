#include <iostream>

struct Time {
    Time() : hour_(0) {}
    Time(int hour) : hour_(hour) {}
    Time& operator|= (const Time &t) {
        this->hour_ += t.hour_;
        return *this;
    }

    int hour_;
};

// tuy thuoc vao so 1 nam ben nao ma ta khai bao (Time t, int b) hay la (int b, Time t)
// nhung operator nay co the xem nhu la 1 function ngoai, thay vi la 1 overload operator thuong thay nam trong class
Time operator&& (int b, Time t) {
    return Time(5);
}

Time operator|| (int b, Time t) {
    return Time(10);
}

bool operator == (int b, Time T) {
    return (b == T.hour_);
}

bool operator != (int b, Time T) {
    return (b != T.hour_);
}

int main() {
    Time t;
    t = 1 && Time(15); // goi function operator&&
    std::cout << "&& operator = " << t.hour_ << '\n';
    t = 1 || Time(15);
    std::cout << "|| operator = " << t.hour_ << "\n";
    if(5 == t) {
        std::cout << "== operator called\n";
    } else if(5 != t) {
        std::cout << "!= opeartor called\n";
    }

    return 0;
}