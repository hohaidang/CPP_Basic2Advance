// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include"11_7_complex.h"

using namespace std;

int main()
{
    Complex a(3.0,4.0);
    Complex c;
    while(cin >> c)
    {
        cout << "c is " << c << endl;
        cout << "Complex conjugate is " << ~c << endl;
        cout << "a is " << a << endl;
        cout << "a + c is " << a + c << endl;
        cout << "a - c is " << a - c << endl;
        cout << "a * c is " << a * c << endl;
        cout << "2 * c is " << 2 * c << endl;
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}
