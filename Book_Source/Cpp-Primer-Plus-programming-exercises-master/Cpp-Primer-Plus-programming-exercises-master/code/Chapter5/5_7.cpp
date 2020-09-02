// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

struct carInfo
{
    string pro;
    int year;
};

int main()
{
    int n;

    cout << "How many cars do you wish to catallog? ";
    cin >> n;
    cin.get(); // get the '\n' left by the last cin.

    carInfo* carCata = new carInfo[n];
    for(int i=0;i<n;++i){
        cout << "Car #" << i+1 << ":" << endl;
        cout << "Please enter the make: ";
        getline(cin,carCata[i].pro);
        cout << "Please enter the year made: ";
        cin >> carCata[i].year;
        cin.get(); // get the '\n' left by the last cin.
    }

    cout << "Here is your collection:" << endl;
    for(int i=0;i<n;++i){
        cout << carCata[i].year << " " << carCata[i].pro << endl;
    }

    delete [] carCata;

    return 0;
}
