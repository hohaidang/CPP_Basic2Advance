#include <iostream>


template <int age>
struct father {
    int dang = 5;
    template<typename T>
    struct son{
        bool restricted;
    };

    struct son<age> my_son;
};

template <int year>
struct family{
    struct father<year> fat;
};

int main() {
    father<5> my_father;
    my_father.dang = 15;
    father<5>::son<int> my_son;
    my_son.restricted = false;

    family<5> my_family;
    my_family.fat.my_son.restricted = false;
    
    // my_family<5>::father.dang = 5;
    // my_family<5>::father::son<int>::restricted = false;
    std::cout << "my_son = " << std::boolalpha << my_son.restricted << '\n';
    std::cout << "HelloWorld\n";
    return 0;
}