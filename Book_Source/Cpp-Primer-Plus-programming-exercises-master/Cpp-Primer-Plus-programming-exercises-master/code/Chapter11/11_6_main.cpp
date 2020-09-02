// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"11_6_stonewt.h"
#include<iostream>

using namespace std;

int main()
{
    Stonewt w[6] = {{23.45},{24.0},{89.7},{},{},{}};
    double n;
    for(int i=3;i<6;++i){
        cout << "Enter a number: ";
        cin >> n;
        cin.get();
        w[i] = Stonewt(n);
    }
    int cnt = 0,idx_max = 0,idx_min = 0;
    Stonewt stn11(11,0.0);
    for(int i=0;i<6;++i){
        if(w[i] >= stn11) cnt++;
        if(w[i] > w[idx_max]) idx_max = i;
        if(w[i] < w[idx_min]) idx_min = i;
    }

    cout << "The max weight is " << w[idx_max] << endl;
    cout << "The min weight is " << w[idx_min] << endl;
    cout << "There are " << cnt << " over 11 stones.\n";

    return 0;
}
