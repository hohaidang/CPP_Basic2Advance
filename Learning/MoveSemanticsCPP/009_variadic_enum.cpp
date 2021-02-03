#include <iostream>

enum eventType {
    NewOrder = 0,
    Modify,
    Cancle
};

struct test {
    eventType msgType;
    template<typename ...Args>
    bool isEventType(eventType type, Args &&...args) {
        // truyen vao bao nhieu tham so cung duoc, se goi recursion lan luot de check
        return (type == msgType) || isEventType(args...);
    }

    bool isEventType() {
        // den khi het tham so truyen vao se goi den ham nay va return false
        return false;
    }
};

int main() {
    test my_struct;
    my_struct.msgType = eventType::Modify;
    std::cout << my_struct.isEventType(eventType::NewOrder, eventType::Modify);
    return 0;
}