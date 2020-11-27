#include <iostream>
#include <memory>

struct dang_struct {
public:
    dang_struct() : a_(55) {
        std::cout << "Created\n"; 
    }

    ~dang_struct() {
        std::cout << "Deleted\n";
    }

    int a_;
};

int main() {
    std::unique_ptr<dang_struct> my(new dang_struct());
    {
        dang_struct *ptr = my.get(); // pass smart pointer vao normal pointer qua .get()
        ptr->a_ = 99;
    }
    // smart pointer van se co kha nang delete sau khi out of scope
    std::cout << "my->a_ = " << my->a_ << '\n';
 
    return 0;
}