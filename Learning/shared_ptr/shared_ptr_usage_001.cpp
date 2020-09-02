#include <iostream>
#include <memory>
using namespace std;

class TestClass {
public:
	TestClass() {
		cout << "Constructor" << endl;
	}

	~TestClass() {
		cout << "Deconstructor" << endl;
	}

	int val_ = 0;
};

/* Cach tra ve 1 shared_ptr trong func */
shared_ptr<TestClass> func() {
	shared_ptr<TestClass> ptr3(new TestClass);
	return ptr3;
}

/* neu truyen smart pointer by value, se rat ton thoi gian, vi no se thuc hien mot copy contrustor, khoi tao bo nho va tang counter
   do do' nen dung reference*/
/* Khong duoc khuyen nghi dung BAD*/
void modifyPtr(const shared_ptr<TestClass> &ptr) {
	cout << "modifyptr number count = " << ptr.use_count() << endl;
	ptr->val_ = 15;
}

/* Nen dung reference object hoac la pointer to object chu khong dung smart pointer lam function parameter tham khao https://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters/*/
// GOOD
void modifyPtr2(TestClass &ptr) {
	ptr.val_ = 50;
}

// GOOD
void modifyPtr3(TestClass* ptr) {
	ptr->val_ = 60;
}

int main(){
	shared_ptr<TestClass> ptr(new TestClass);
	{
		shared_ptr<TestClass> ptr2(ptr); // copy constructor
		cout << "use count = " << ptr2.use_count() << endl;
	}

	
	cout << "use count = " << ptr.use_count() << endl;
	ptr.reset();
	cout << "End main" << endl; 

	{
		shared_ptr<TestClass> ptr4 = func();
		modifyPtr(ptr4);
		cout << "ptr4 val_ = " << ptr4->val_ << endl;
		modifyPtr2(*ptr4.get());
		cout << "ptr4 val_ = " << ptr4->val_ << endl;
		modifyPtr3(ptr4.get());
		cout << "ptr4 val_ = " << ptr4->val_ << endl;
	}
	

	shared_ptr<int []> test_num(new int[15]);
	test_num[0] = 10;
	test_num[1] = 15;
	cout << "test_num[0] = " << test_num[0] << endl;
	return 0;
}
