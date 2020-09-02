// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int Fac(int n);

int main ()
{
    int n,f;
    cout << "Enter an integer: ";
    while(cin >> n){
        f = Fac(n);
        cout << "The factorial of " << n << " is: " << f << endl;
        cout << "Enter an integer: ";
    }
}

int Fac(int n)
{
    if(n == 0) return 1;
    else return n*Fac(n-1);
}
