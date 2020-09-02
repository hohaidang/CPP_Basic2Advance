// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j) cout << ".";
        for(int j=0;j<=i;++j) cout << "*";
        cout << endl;
    }

    return 0;
}
