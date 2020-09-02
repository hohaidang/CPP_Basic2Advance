// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

struct donator
{
    string name;
    double money;
};

int main()
{
    int n,cnt = 0;
    donator* donators;
    cout << "Enter the number of donators: ";
    cin >> n;
    cin.get();
    donators = new donator[n];
    for(int i=0;i<n;++i){
        cout << "Enter the name of donator: ";
        getline(cin,donators[i].name);
        cout << "Enter how much money he donated: ";
        cin >> donators[i].money;
        cin.get();
    }
    cout << "Grand Patrons:" << endl;
    for(int i=0;i<n;++i){
        if(donators[i].money > 10000){
            cout << donators[i].name << endl;
            cnt++;
        }
    }
    if(cnt == 0) cout << "none" << endl;
    cout << "Patrons:" << endl;
    if(cnt == n) cout << "none" << endl;
    else{
        for(int i=0;i<n;++i)
            if(donators[i].money <= 10000) cout << donators[i].name << endl;
    }

    return 0;
}
