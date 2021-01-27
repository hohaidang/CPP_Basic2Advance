#include <iostream>

// variadic template cho phep truyen vao tham so cho ham 
// voi so luong khong can define truoc

void print() {
    std::cout << "Empty function\n";
}

template<typename T, typename... Types>
void print(T var1, Types... var2) {
    std::cout << var1 << '\n';
    print(var2...);
    // print(var2...) se lien tuc duoc goi cho den het so luong var2 
    // duoc truyen vao recursive.
    // Moi lan duoc goi thi var1 se lay phan tu dau tien,
    // nhung phan tu con lai se duoc gan vao var2
}

int main() {
    print("Hello", "World", "Dang", "Dep", 1, 2, 3.14, "Trai");
    return 0;
}
