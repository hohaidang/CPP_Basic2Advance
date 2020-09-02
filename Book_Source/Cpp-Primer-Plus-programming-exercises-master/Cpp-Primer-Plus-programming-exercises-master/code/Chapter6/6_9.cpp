// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<fstream>

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
    ifstream fin;
    fin.open("txt.txt");
    //cout << "Enter the number of donators: ";
    fin >> n;
    fin.get();
    donators = new donator[n];
    for(int i=0;i<n;++i){
        //cout << "Enter the name of donator: ";
        getline(fin,donators[i].name);
        //cout << "Enter how much money he donated: ";
        fin >> donators[i].money;
        fin.get();
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
