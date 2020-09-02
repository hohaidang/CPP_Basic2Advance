#include <cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);
	// should be about 57.295

	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y); // dinh ly pytago tinh canh huyen^2 = x2 + y2
	}

	void Vector::set_ang()
	{
		if (x == 0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(x, y); // tan = doi / ke
	}

	void Vector::set_x()
	{
		x = mag * cos(ang); // cos(ang) = x / mag (ke / huyen)
	}

	void Vector::set_y()
	{
		y = mag * sin(ang); // sin(ang) = y / mag (doi / huyen)
	}

	Vector::Vector() // default constructor
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag(); // caculate lenght of vector
			set_ang(); // caculate angle
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() --";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() --";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector() {}
	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+ (const Vector &b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector &b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator- () const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator* (double n) const
	{
		return Vector(n * x, n * y);
	}

	Vector operator*(double n, const Vector &a)
	{
		return a * n;
	}

	std::ostream & operator<< (std::ostream & os, const Vector & v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", "
				<< v.ang * Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}
}
