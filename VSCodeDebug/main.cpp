#include <memory>

struct Type
{
    int do_thing() const {return data + 4;};
    int data;
};

int main()
{
    Type obj;
    obj.do_thing();
    int b = 5;
    int a[5] = {1, 2, 3, 4,5};
}