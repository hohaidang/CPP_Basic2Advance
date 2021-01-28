#include <iostream>

struct A {
    using foo = int;
    template<typename T>
    void function(){
        std::cout << "Call template function\n";
    }

    void no_template_function() {
        std::cout << "Call no_template function\n";
    }

    template<typename T>
    struct C {
        T var_in_C;
    };

    int a;
};

template<typename T>
class B : public T{
public:
    // (1)
    typename T::foo *ptr; // T::foo chinh la A::foo
    // se duoc hieu la int, boi vi day la type
    // cho nen phai dung typename de explicit cho 
    // compiler hieu
    void call_template() {
        //(2)
        T::template function<int>();
        // o day B duoc inherit tu A cho nen
        // B cung co duoc A::function()
        // nhung vi A::function() la mot template
        // nen phai them tu template de compiler hieu
        T::no_template_function();
        // o day no_template_function() khong co template
        // nen khong can phai specify template keyword
        this->template function<int>();
        this->a = 10;
        // goi bien hoac ham trong 1 class base thi co 2 cach:
        // cach 1: dung <ten class>::
        // cach 2: dung con tro *this

        typename T::template C<int> my_struct_C;
        // truong hop nay la tong hop cua (1) va (2)
        // ta muon co duoc mot bien co kieu du lieu la struct C
        // ma struct C lai duoc khai bao trong struct A
        // nen ta dung T::A, tiep theo la vi struct C
        // co template nen ta phai dung template sau dau ::
        // va vi structC la 1 kieu du lieu, nen ta phai dung typename
        // o phia dau tien
    }
};



int main() {
    B<A> my_class;
    my_class.call_template();
    return 0;
}
