#include <iostream>

template<typename T>
class class1{
public:
    T val;
};

int main() {
    int *duc = new int [2];
    *duc = 5;
    *(duc + 1) = 6;
    std::cout << "duc = " << *duc << ", *(duc + 1) = " << *(duc + 1) << '\n';

    // boi vi template la int* nen bien val cung se la 1 con tro nhung bien dang van la 1 variable. 
    // Do do dung dau cham o bien dang va '*' o dau de thay doi gia tri cua val
    class1<int *> dang;
    dang.val = new int [2];
    *dang.val = 15;
    *(dang.val + 1) = 20;
    std::cout << "*dang.val = " << *dang.val << ", *(dang.val + 1) = " << *(dang.val + 1) << '\n';
    std::cout << "Hello";
}