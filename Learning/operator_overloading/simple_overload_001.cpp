#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

class Time {
public:
	Time(int hour) : hour_(hour) {
		for (int i = 0; i < arr_.size(); ++i) {
			arr_[i] += i * 5;
		}
	}
	
	Time() {
		for (int i = 0; i < arr_.size(); ++i) {
			arr_[i] += i * 5;
		}
	}

	// copy constructor: la bien dau vao la 1 class giong nhu vay
	Time(const Time &t) {
		this->hour_ = t.hour_;
		copy(t.arr_.begin(), t.arr_.end(), this->arr_.begin());
	}

	// move constructor: la bien dau vao la mot rvalue va la class 
	Time(Time&& t) {
		this->hour_ = t.hour_;
		this->arr_ = move(t.arr_);
		t.hour_ = 0;
		
	}


	//operator plus
	Time operator+(const Time& t) {
		Time temp = Time();
		temp.hour_ = this->hour_ + t.hour_;
		return temp;
	}

	// operator minus
	Time operator-(const Time& t) {
		Time temp;
		temp.hour_ = this->hour_ - t.hour_;
		return temp;
	}

	// operator minus_num
	Time operator-(const int num) {
		Time temp;
		temp.hour_ = this->hour_ - num;
		return temp;
	}

	// operator negative
	Time operator-() {
		Time temp;
		temp = -this->hour_;
		return temp;
	}

	// operator multiple * num
	Time operator*(const int num) {
		Time temp;
		temp.hour_ = this->hour_ * num;
		return temp;
	}

	// operator num * multiple
	/* Bat buoc phai dung friend function cho num*class boi vi khi operator* se khong hieu gia tri noi tai cua class
	 * nen can friend function de truy cap vao */
	friend Time operator*(const int num, const Time& t);

	// operator increasement prefix
	void operator++() {
		++this->hour_;
	}

	// operator increasement posfix
	Time operator++(int) {
		Time temp(this->hour_); // save the original value
		++this->hour_;
		return temp;
	}

	// relational operator
	bool operator>(const Time& t) {
		return (t.hour_ > this->hour_);
	}

	// input // output operator
	friend ostream& operator<<(ostream& output, const Time& t);
	friend istream& operator>>(istream& input, Time& t);

	// assignment copy operator
	void operator=(const Time& t) {
		this->hour_ = t.hour_;
	}

	// assigment move operator 
	void operator=(Time&& t) noexcept {
		this->hour_ = t.hour_;
		this->arr_ = move(t.arr_);
		this->hour_ = 0;
	}

	// operator function call overloading
	Time operator()(int a, int b, int c) {
		Time temp(0);
		temp.hour_ += a + b + c;
		return temp;
	}

	// subscripting operator
	int operator[](int i) {
		if (i > 5) {
			return arr_[0];
		}
		return arr_[i];
	}

    Time& operator|=(const Time &t) {
        this->hour_ += t.hour_;
        return *this;
    }

	void show_time(string name) const {
		cout << name << " hour_ = " << this->hour_ << endl;
	}
private:
	int hour_;
	array<int, 5> arr_ = {};
};

Time operator*(const int num, const Time& t) {
	Time temp;
	temp = num * t.hour_;
	return temp;
}

// return reference just like return pointer
ostream& operator<<(ostream& output, const Time& t) {
	output << "\ntime hour: " << t.hour_;
	return output;
}

istream& operator>>(istream& input, Time& t) {
	input >> t.hour_;
	return input;
}

int main() {
	Time a(5);
	Time b(10);
	Time copy_construct(a); // copy constructor
	Time move_construct(a + b); // move constructor
	Time plus = a + b;
	Time minus = a - b;
	Time negative = -a;
	Time minus_num = a - 3;
	Time multiple_num = b * 15;
	Time num_multiple = 15 * b;
	Time assignment = a;
	Time assignment_move = a + b;
	Time function_call = a(1, 2, 3);
    Time or_equal(3);
    Time f(5);
    or_equal |= f;

	plus.show_time("plus");
	minus.show_time("minus");
	negative.show_time("negative");
	minus_num.show_time("minus_num");
	multiple_num.show_time("multiple_num");
	num_multiple.show_time("num_multiple");
	assignment.show_time("assignment");
	function_call.show_time("function_call");
    or_equal.show_time("or_equal");
	cout << "subscripting operator = " << a[3] << endl;
	++a;
	a.show_time("prefix increse operator");
	Time c(4);
	Time pos_fix = c++;
	pos_fix.show_time("pos_fix increase");
	c.show_time("c pos_fix");
	cout << "Is a > b ? " << boolalpha << (a > b);

	cout << "\nPlease enter hour: ";
	Time inTime;
	cin >> inTime;
	cout << inTime; // input/output operator
	return 0;
}