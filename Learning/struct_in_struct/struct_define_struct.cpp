#include <iostream>


struct dang1 {
#define IMPORT(MsgBase) \ 
    public: \
        int a;

};

template<typename base>
struct dang2 : base{
    IMPORT(base)
};

int main() {
    // dang2 inherit tu dang1, va dang 1 co 1 cai #define IMPORT
    // tu do struct dang2 se co bien public: int a; nhung dang1 se khong co bien nao
    dang2<dang1> my_struc;
    my_struc.a = 15;
    std::cout << "sizeof dang1 = " << sizeof(dang1) << '\n';
    std::cout << "sizeof dang2 = " << sizeof(dang2<dang1>) << '\n';
	return 0;
}