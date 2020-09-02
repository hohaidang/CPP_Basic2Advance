#include <iostream>
using namespace std;

template <int I> void div(char(*)[I % 2 == 0] = 0) {
    // this overload is selected when I is even
    cout << "Even";
}
template <int I> void div(char(*)[I % 2 == 1] = 0) {
    // this overload is selected when I is odd
    cout << "Odd";
}

template <typename T>
int get_int_value_impl(T t, std::true_type) {
    return static_cast<int>(t + 0.5f);
}

template <typename T>
int get_int_value_impl(T t, std::false_type) {
    return static_cast<int>(t);
}

template <typename T>
int get_int_value(T t) {
    return get_int_value_impl(t, std::is_floating_point<T>{});
}

int main() {
    int a = 3;
    div<3>();

    /*int b = get_int_value_impl<int>(a, true);*/
    float c = 3.3;
    int d  = get_int_value(c);
    int e = 5;
    int k = get_int_value_impl(e, std::is_floating_point<int>{});

    cout << "Hello World" << endl;
    return 0;
}
