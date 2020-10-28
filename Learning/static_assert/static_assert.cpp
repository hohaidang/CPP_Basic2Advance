#include <iostream>

class Library {
    public:
        static const int version = 3;
};

static_assert(Library::version > 4, "Foo::bar is too small");

int main() {
    return Library::version;
}

// hay tuong tuong ban dang build 1 thu vien voi yeu cau la
// version phai lon hon 4, nhung no lai duoc define duoi dang
// static const version thay vi la #define. Thi ban se phai build
// 30p moi phat hien ra la minh dang build phien ban thu 3

// De nhanh hon thi static_assert se lam trong luc linking
// no se check neu library::version <= 4 thi se bao ra loi compiler luon