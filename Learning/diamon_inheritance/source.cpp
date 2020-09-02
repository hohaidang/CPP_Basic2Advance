#include <iostream>
using namespace std;

class A {
public:
	int a_ = 5;
	void printA() {
		cout << "printA = " << a_;
	}
};

class B : virtual public A {
public:
	int b_;
};


class C : virtual public A {
public:
	int C_;
};

class D : public B, public C {
public:
	int d_;
};

/* Diamon inheritance
		A
      /   \
     B     C
	  \   /
	    D

class D se co bien a_ xuat hien 2 lan
a_,
b_,
a_,
c_,
d_

Do do khi truy cap vao bien a_, compilier se bao loi, la khong bien dang truy cap vao bien a_ nao
Giai phap la ta dung virtual inheritance o class B va class C -> compiler luc dich ra se dich class D chi co 1 bien a_ duy nhat
*/

int main() {
	class D dang;
	dang.d_ = 5;
	dang.printA();
	dang.a_ = 10; 
	return 0;
}