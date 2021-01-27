#include <iostream>
#include <cstring>
// tham khao: https://www.modernescpp.com/index.php/perfect-forwarding#:~:text=If%20a%20function%20templates%20forward,we%20call%20it%20perfect%20forwarding.

#define _VARIADIC_TEMPLATE

#ifndef _VARIADIC_TEMPLATE
template<typename T, typename Arg> 
T create(Arg&& a) {
    return T(std::forward<T>(a)); 
    // neu khong co forward o day thi copy constructor se duoc goi
    // Arg&& a dang le la rvalue, nhung khi vao ham thi no se bien thanh lvalue
    // do do ta can std::forward
}

#else
// variadic template
// dung de da dang gia tri Arg dau vao, co the chap nhan gia tri dau vao rong
// hoac vo so gia tri dau vao
template<typename T, typename... Args> 
T create(Args&& ... a) {
    return T(std::forward<T>(a) ...); 
}
#endif


struct MyStruct {
public:
    MyStruct() = default;
    MyStruct(int i, double d, std::string s) 
        : m_i(i), m_d(d), m_s(s) {
            std::cout << "Constructor called\n";
    }
    // Copy constructor
    MyStruct(const MyStruct &s) {
        std::cout << "Copy Constructor is called\n";
        m_i = s.m_i;
        m_d = s.m_d;
        m_s = s.m_s;
    }

    // Move constructor
    MyStruct(MyStruct&& s) {
        std::cout << "Move Constructor is called\n";
        m_i = s.m_i;
        m_d = s.m_d;
        m_s = s.m_s;
    }

    int m_i;
    double m_d;
    std::string m_s;

};

int main() {
    // truyen vao rvalue
    MyStruct _create = create<MyStruct>(MyStruct(1, 2, "3"));
    double _double = create<double>(5.5);

#ifdef VARIADIC_TEMPLATE
    double _double1 = create<double>(); // neu khong co variadic template
    // thi double1 nay se bi loi, vi khong co gia tri dau vao cho create
    std::cout << _double1 << '\n';
#endif

    return 0;
}
