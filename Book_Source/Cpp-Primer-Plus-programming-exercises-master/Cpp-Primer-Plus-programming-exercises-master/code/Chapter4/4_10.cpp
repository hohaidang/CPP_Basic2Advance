// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    int time[3];
    cout << "Enter your grades in the three 40-meter games: ";
    cin >> time[0] >> time[1] >> time[2];
    cout << "Your average grade is: " << (time[0]+time[1]+time[2])/3.0 << endl;

    return 0;
}
