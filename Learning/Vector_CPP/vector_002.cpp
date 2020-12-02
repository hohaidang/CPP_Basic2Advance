#include <iostream>
#include <vector>

int main() {
    std::vector<int> dang;
    dang.reserve(150); // define the block size of vector
    for(int i = 0; i < 149; ++i) {
        dang.push_back(1);
    }
    // for(int i = 0; i < 149; ++i) {
        dang.push_back(1);
        dang.push_back(1);dang.push_back(1);dang.push_back(1);
        dang.push_back(1);dang.push_back(1);
        dang.push_back(1);
        dang.push_back(1);
        dang.push_back(1);
        dang.push_back(1);
    // }
    std::cout << "capacity = " << dang.capacity() << '\n';
    return 0;
}
