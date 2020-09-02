// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

struct CandyBar
{
    string brand;
    float weight;
    int calory;
};

int main()
{
    CandyBar snack = {"Mocha Munch",2.3,350};
    cout << "snack:\n";
    cout << "      Brand: " << snack.brand << endl;
    cout << "      Weight: " << snack.weight << endl;
    cout << "      Calory: " << snack.calory << endl;

    return 0;
}
