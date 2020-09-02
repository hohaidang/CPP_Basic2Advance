// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    double don[10];
    double dig,sum(0),avg;
    int cnt(0),cnt1(0);
    cout << "Enter the donation:" << endl;
    while(cin >> dig){
        don[cnt++] = dig;
        sum += dig;
    }
    avg = sum/cnt;
    cout << "average: " << avg << endl;
    for(int i=0;i<cnt;++i){
        if(don[i] > avg) cnt1++;
    }
    cout << "There are " << cnt1 << " donation(s) over the average." << endl;

    return 0;
}
