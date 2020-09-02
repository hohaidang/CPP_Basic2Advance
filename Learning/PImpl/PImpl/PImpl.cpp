//#include "user.h"
//#include <iostream>
//using namespace std;
//
//struct User::Impl
//{
//	Impl(string name) : name(name) {};
//	~Impl();
//
//	void welcomeMessage()
//	{
//		cout << "Welcome, " << name << endl;
//	}
//	string name;
//	int salary = -1;
//};
//
//// Constructor connected with our Impl structure
//User::User(string name) : pimpl(new Impl(name))
//{
//	pimpl->welcomeMessage();
//}
//
//// Default constructor
//User::~User() = default;
//
//// Assignment operator and Copy constructor
//User::User(const User& other) : pimpl(new Impl(*other.pimpl))
//{}
//
//User& User::operator=(User rhs)
//{
//	swap(pimpl, rhs.pimpl);
//	return *this;
//}
//
//// Getter and setter
//int User::getSalary()
//{
//	return pimpl->salary;
//}
//
//void User::setSalary(int salary)
//{
//	pimpl->salary = salary;
//	cout << "Salary set to " << salary << endl;
//}


#include <iostream>
#include <memory>

// interface (widget.h)
class widget {
	class impl;
	std::unique_ptr<impl> pImpl;
public:
	void draw() const; // public API that will be forwarded to the implementation
	void draw();
	bool shown() const { return true; } // public API that implementation has to call
	widget(int);
	~widget(); // defined in the implementation file, where impl is a complete type
	widget(widget&&); // defined in the implementation file
					  // Note: calling draw() on moved-from object is UB
	widget(const widget&) = delete;
	widget& operator=(widget&&); // defined in the implementation file
	widget& operator=(const widget&) = delete;
};

// implementation (widget.cpp)
class widget::impl {
	int n; // private data
public:
	void draw(const widget& w) const {
		if (w.shown()) // this call to public member function requires the back-reference 
			std::cout << "drawing a const widget " << n << '\n';
	}
	void draw(const widget& w) {
		if (w.shown())
			std::cout << "drawing a non-const widget " << n << '\n';
	}
	impl(int n) : n(n) {}
};
void widget::draw() const { pImpl->draw(*this); }
void widget::draw() { pImpl->draw(*this); }
widget::widget(int n) : pImpl{ std::make_unique<impl>(n) } {}
widget::widget(widget&&) = default;
widget::~widget() = default;
widget& widget::operator=(widget&&) = default;

// user (main.cpp)
int main()
{
	widget w(7);
	const widget w2(8);
	w.draw();
	w2.draw();
}