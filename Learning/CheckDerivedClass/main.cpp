#include <iostream>

template<typename D, typename B>
class IsDerivedFromHelper
{
    class No { };
    class Yes { No no[3]; };
    
    static Yes Test( B* );
    static No Test( ... );
public:
    enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes)
 };
    ~IsDerivedFromHelper(){
        std::cout << "size Test = " << sizeof(Test(static_cast<D*>(0))) << '\n';
        std::cout << "size Yes = " << sizeof(Yes)
 << '\n';
    }
};


template <class C, class P> 
bool IsDerivedFrom() {
    {
        IsDerivedFromHelper<C, P>();
    }
    return IsDerivedFromHelper<C, P>::Is;
}

class Base {};

class Derived : public Base {};

int main(){
    std::cout << IsDerivedFrom<Derived, Base>();
    return 0;
}
