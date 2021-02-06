#include <iostream>

template<typename Result>
struct Optional{
private:
    Result content;
    bool isFull;

public:
    Optional(bool isFull, Result content) : isFull(isFull), content(content) {}
    Result operator*() {
        return content;
    }

    bool operator!() {
        return !isFull;
    }

    Result result() {
        return **this; // con tro this nay se goi den operator*, sau do return ve content
    }

    bool checkFull() {
        return !*this; // con tro this nay se goi den operator!, sau do return ve content
    }
};


int main() {
    int a = 5;
    Optional<int> dang(0, a);
    std::cout << "*dang = " << *dang << std::endl;
    std::cout << "dang.result() = " << dang.result() << std::endl;
    std::cout << "dang.checkFull() = " << std::boolalpha << dang.checkFull() << std::endl;
    return 0;
}