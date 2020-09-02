// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"11_5_stonewt.h"
#include<iostream>

using namespace std;

int main()
{
    Stonewt w0;
    Stonewt w1(11);
    Stonewt w2(11,12.3);
    cout << "Show w0,w1,w2:\n";
    cout << w0 << ";" << w1 << ";" << w2 << endl;
    cout << "w1 + w2 = " << w1 + w2 << endl;
    cout << "w2 - w1 = " << w2 - w1 << endl;
    cout << "w2 * 2.0 = " << w2 * 2.0 << endl;
    cout << "2.5 * w1 = " << 2.5 * w1 << endl;

    return 0;
}
