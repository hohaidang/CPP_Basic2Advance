// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string mon[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
string year[3] = {"first", "second","third" };

int main()
{
    int sell[3][12];
    int sum[3];
    memset(sum,0,3*sizeof(int));

    for(int i=0;i<3;++i){
        for(int j=0;j<12;++j){
            cout << "Enter the sell in " << mon[j] << "," << "the " << year[i] << " year: ";
            cin >> sell[i][j];
            sum[i] += sell[i][j];
        }
        cout << "The total sell of the " << year[i] << " year is: " << sum[i] << endl;
    }

    return 0;
}
