// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    int l,r,sum = 0;
    cout << "Enter the end numbers: ";
    cin >> l >> r;
    for(int i=l;i<=r;++i){
        sum += i;
    }
    cout << "The sum of the numbers between " << l << " and " << r << " is " << sum << endl;
    return 0;
}
