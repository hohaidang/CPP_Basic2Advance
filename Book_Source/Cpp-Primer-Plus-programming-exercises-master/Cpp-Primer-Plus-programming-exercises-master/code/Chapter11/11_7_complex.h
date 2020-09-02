// By luckycallor
// Welcome to my site: www.luckycallor.com

#ifndef COMPLEX_H
#include<iostream>

class Complex
{
private:
    double re;
    double im;
public:
    Complex(double r = 0.0,double i = 0.0);
    ~Complex();
    Complex operator+(const Complex& c)const;
    Complex operator-(const Complex& c)const;
    Complex operator-()const;
    Complex operator*(const Complex& c)const;
    Complex operator*(double n)const;
    Complex operator~()const;
    friend Complex operator*(double n,const Complex& c);
    friend std::ostream& operator<<(std::ostream& os,const Complex& c);
    friend std::istream& operator>>(std::istream& is,Complex& c);
};
#endif // COMPLEX_H
