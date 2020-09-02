// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

string mon[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main()
{
    int sell[12];
    int sum = 0;
    for(int i=0;i<12;++i){
        cout << "Enter the sell in " << mon[i] <<" :";
        cin >> sell[i];
        sum += sell[i];
    }

    cout << "The yearly sell is: " << sum << endl;

    return 0;
}
