#include <iostream>
#include <cstring>

// muc dich cua bai nay la thay vi dung copy constructor
// ta co the dung move constructor de tranh duplicate viec tao 2 lan bo nho sau do delete

class String {
public:
    String() : m_Data{nullptr} {};
    String(const char *string) {
        printf("Created\n");
        m_Size = std::strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    // copy constructor
    String(const String &order) {
        printf("Copied Constructor\n");
        m_Size = order.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, order.m_Data, m_Size);
    }

    // move constructor
    String(String &&order) noexcept {
        printf("Moved Constructor\n");
        m_Size = order.m_Size;
        m_Data = order.m_Data;

        order.m_Size = 0;
        order.m_Data = nullptr; // cho nay se goi delete nullptr, se khong lam gi ca
    }

    ~String() {
        if(m_Data) {
            printf("Destroyed\n");
            delete []m_Data;
        }
    }
private:
    uint32_t m_Size;
    char *m_Data;
};

class Entity {
public:
    // co the dung const String &name hoac String&& name
    // boi vi String("Cherno") se tra ve rvalue
    Entity(const String &name) : m_name(name) // goi copy constructor
    {
        printf("Const Entity called\n");
    }

    // casting (String &&) de bao cho compiler biet la chac chan
    // se goi vao move constructor cua class string thay vi copy constructor
    // co the thay the (String &&) = std::move()
    Entity(String&& name) : m_name((String &&)name)
    {
        printf("r_ref Entity called\n");
    }


private:
    String m_name;
};


int main() {
    // Entity entity(String("Cherno"));
    Entity entity1("Cherno");
    // entity va entity1 la nhu nhau, deu se vao constructor truoc roi sao do
    // vao move constructor boi vi "Cherno" la lvalue
    // doi voi entity1 co the hieu cach khac la 
    // String &&name("Cherno") -> constructor, sau do
    // m_name(name) -> copy constructor
    return 0;
}