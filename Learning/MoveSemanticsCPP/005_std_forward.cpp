#include <iostream>

// ham nay chi chap nhan l value
// template<typename T, typename Arg>
// T create(Arg &a) {
//     return T(a);
// }

// create(const Arg &a) nay se chap nhan rvalue va lvalue
// nhung dieu khac biet la neu rvalue dua vao
// thi no se thuc hien 1 deepcopy vao bien const Arg &a
// boi vi bien a la const nen luon co 1 dia chi trong o nho
template<typename T, typename Arg>
T create(const Arg &a) {
    return T(a);
}

// create(Arg &&a) vua co the nhan lvalue, vua co the nhan rvalue
// khong giong nhu Arg &a chi co the nhan lvalue
template<typename T, typename Arg>
T create(Arg &&a) {
    return std::forward<T>(a); // std::forward de rvalue 
    //van la rvalue ma khong bi doi thanh lvalue
    // return T(a);
}

int main() {
    int five = 5;
    int myFive = create<int>(five);
    std::cout << "myFive: " << myFive << '\n';

    int myFive_1 = create<int>(5); // ham nay se goi create(Arg &&a)
    // boi vi 5 la rvalue
    std::cout << "myFive_1: " << myFive_1 << '\n';
    return 0;
}
