#include <iostream>

class dang_class {
public:
    dang_class(int val) : m_val(val){}
    int val() const { return m_val; }
private:
    int m_val;
};