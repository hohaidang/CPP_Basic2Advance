// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<cmath>
#include"11_2_vect.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad_to_deg = 45.0/atan(1.0);
#if(0)
    void Vector::set_mag()
    {
        mag = sqrt(x*x + y*y);
    }

    void Vector::set_ang()
    {
        if(x == 0 && y == 0) ang = 0.0;
        else ang = atan2(y,x);
    }

    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }
#endif
    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1,double n2,Mode form)
    {
        mode = form;
        if(form == RECT){
            x = n1;
            y = n2;
            //set_ang();
            //set_mag();
        }
        else if(form == POL){
            //mag = n1;
            //ang = n2;
            x = n1 * cos(n2);
            y = n1 * sin(n2);
            //set_x();
            //set_y();
        }
        else{
            cout << "Incorrect 3rd argument to Vector() -- vector set to 0.\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if(form == RECT){
            x = n1;
            y = n2;
            //set_ang();
            //set_mag();
        }
        else if(form == POL){
            //mag = n1;
            //ang = n2;
            //set_x();
            //set_y();
            x = n1 * cos(n2);
            y = n1 * sin(n2);
        }
        else{
            cout << "Incorrect 3rd argument to Vector() -- vector set to 0.\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {

    }

    double Vector::magval()const
    {
        return sqrt(x*x + y*y);
    }

    double Vector::angval()const
    {
        if(x == 0.0 && y == 0.0) return 0.0;
        else return atan2(y,x);
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector& b)const
    {
        return Vector(x+b.x,y+b.y);
    }

    Vector Vector::operator-(const Vector& b) const
    {
        return Vector(x-b.x,y-b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x,-y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(x*n,y*n);
    }

    Vector operator*(double n,const Vector& a)
    {
        return a*n;
    }

    std::ostream& operator<<(std::ostream& os,const Vector& v)
    {
        if(v.mode == Vector::RECT) os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if(v.mode == Vector::POL) os << "(x,y) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
        else os << "Vector object mode is invalid.";
        return os;
    }
}

