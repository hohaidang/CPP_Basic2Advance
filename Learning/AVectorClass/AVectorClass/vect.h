#pragma once
#include <iostream>

namespace VECTOR
{
	extern const double Rad_to_deg;
	class Vector
	{
	public:
		enum Mode {RECT, POL};
	private:
		double x; // horizontal value
		double y; // Vertical value
		double mag; // length of vector (canh huyen)
		double ang; // direction of vector in degrees
		Mode mode; // regtangle or polygonal
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode();
		void rect_mode();
		// Operator overloading
		Vector operator+ (const Vector & b) const;
		Vector operator- (const Vector & b) const; // add minus sign
		Vector operator- () const;
		Vector operator* (double n) const;
		//friends
		friend Vector operator*(double n, const Vector &a);
		friend std::ostream & operator<<(std::ostream &os, const Vector &v);
	};
}