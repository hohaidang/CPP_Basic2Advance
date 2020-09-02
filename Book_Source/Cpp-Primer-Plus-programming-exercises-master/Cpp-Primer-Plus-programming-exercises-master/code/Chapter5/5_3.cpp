// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    int sum = 0,n;
    cin >> n;
    while(n != 0){
        sum += n;
        cout << "Sum untill now is: "<< sum << endl;
        cin >> n;
    }
    return 0;
}
