// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"11_7_complex.h"

Complex::Complex(double r,double i)
{
    re = r;
    im = i;
}

Complex::~Complex(){}

Complex Complex::operator+(const Complex& c)const
{
    return Complex(re+c.re,im+c.im);
}

Complex Complex::operator-()const
{
    return Complex(-re,-im);
}

Complex Complex::operator-(const Complex& c)const
{
    return Complex(re-c.re,im-c.im);
}

Complex Complex::operator*(double n)const
{
    return Complex(re*n,im*n);
}

Complex Complex::operator*(const Complex& c)const
{
    return Complex(re*c.re-im*c.im,re*c.im+im*c.re);
}

Complex Complex::operator~()const
{
    return Complex(re,-im);
}

Complex operator*(double n,const Complex& c)
{
    return c*n;
}

std::ostream& operator<<(std::ostream& os,const Complex& c)
{
    os << "(" << c.re << "," << c.im << "i)";
    return os;
}

std::istream& operator>>(std::istream& is,Complex& c)
{
    std::cout << "real: ";
    if(!(is >> c.re)) return is;
    is.get();
    std::cout << "imaginary: ";
    is >> c.im;
    is.get();

    return is;
}
