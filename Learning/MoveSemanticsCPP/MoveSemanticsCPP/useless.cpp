#include <iostream>
using namespace std;

class Useless
{
private:
	int n; // number of elements
	char *pc; //pointer to data
	static int ct; // number of objects
	void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless &f); // regular copy constructor
	Useless(Useless &&f); // move constructor
	~Useless();
	Useless operator+(const Useless &f) const;
	void ShowData() const;
	Useless& operator=(const Useless &f);
	Useless& operator=(Useless &&f);
};

int Useless::ct = 0;
Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	cout << "default constructor called; number of objects: " << ct << endl;
	ShowObject();
}

Useless::Useless(int k) : n(k)
{
	++ct;
	cout << "int constructor called; number of objects: " << ct << endl;
	pc = new char[n];
	ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
	++ct;
	cout << "int, char constructor called; number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = ch;
	ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
	++ct;
	cout << "copy const called; number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; ++i)
		pc[i] = f.pc[i];
	ShowObject();
}

Useless::Useless(Useless && f) : n(f.n)
{
	++ct;
	cout << "move constructor called; number of objects: " << ct << endl;
	pc = f.pc;
	f.pc = nullptr;
	f.n = 0;
	ShowObject();
}

Useless::~Useless()
{
	cout << "destructor called; objects left: " << --ct << endl;
	cout << "deleted object:\n";
	ShowObject();
	delete[] pc;
}

Useless Useless::operator+(const Useless & f) const
{
	cout << "Entering operator+()\n";
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; ++i)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; ++i)
		temp.pc[i] = f.pc[i - n];
	cout << "temp object:\n";
	cout << "Leaving operator+()\n";
	return temp;
}

Useless& Useless::operator=(const Useless &f) // copy operator
{
	if (this == &f)
		return *this;
	delete[] pc;
	int temp_n = f.n;
	char *temp = new char[temp_n];
	for (int i = 0; i < temp_n; i++)
	{
		temp[i] = f.pc[i];
	}
	this->n = temp_n;
	this->pc = temp;
	return *this;
}

Useless& Useless::operator=(Useless &&f) // move operator
{
	if (this == &f)
		return *this;
	delete[] pc;
	this->n = f.n;
	this->pc = f.pc;
	f.n = 0;
	f.pc = nullptr;
	return *this;
}

void Useless::ShowObject() const
{
	cout << "Number of elements: " << n;
	cout << " Data address: " << (void *)pc << endl;
}

void Useless::ShowData() const
{
	if (n == 0)
		cout << "(object empty)";
	else
		for (int i = 0; i < n; ++i)
			cout << pc[i];
	cout << endl;
}

Useless makeUseless()
{
	Useless u(5, 'g');
	return u;
}

int main()
{
	{
		Useless one(10, 'x');
		Useless two = one; // call copy constructor 
		// goi copy contrustor ma khong goi operator+ la vi two la mot class moi duoc tao ra
		// neu viet "two = one;" thi operator+ se duoc goi
		Useless three(20, 'o');
		Useless four(one + three); // calls operator+(), move constructor
		//the rvalue reference f binds to the rvalue temporary object returned by the method
		// "one + three" se goi operator+(), sau do ket qua tra ra se la rvalue(bien tam) va vi la rvalue cho nen 
		// se goi move constructor

		Useless five = makeUseless(); // call move constructor
		// boi vi makeUseLess function se tao ra 1 cai rvalue vi la rvalue cho nen move constructor se duoc goi

		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		cout << "object three: ";
		three.ShowData();
		cout << "object four: ";
		four.ShowData();

		three = one; // lvalue -> copy operator
		cout << "object three: ";
		three.ShowData();
		three = Useless(3, 'k'); // rvalue -> normal constructor -> move operator= 
		//  luc dau Useless(3, 'k') se goi normal constructor, sau do se return ve 1 cai rvalue -> move operator = se dc goi
		cout << "object three: ";
		three.ShowData();

		three = move(one); // turn one to rvalue by using std::move casting
		cout << "object three: ";
		three.ShowData();
	}
}