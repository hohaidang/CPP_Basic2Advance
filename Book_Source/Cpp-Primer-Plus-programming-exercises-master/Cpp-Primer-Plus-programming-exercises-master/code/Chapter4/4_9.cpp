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
    CandyBar *snack[3];
    for(int i=0;i<3;++i){
        snack[i] = new CandyBar;
        (*snack[i]) = {"Mocha Munch",2.3,350};
        cout << "snack_" << i << ":\n";
        cout << "      Brand: " << snack[i]->brand << endl;
        cout << "      Weight: " << snack[i]->weight << endl;
        cout << "      Calory: " << snack[i]->calory << endl;
        delete snack[i];
    }

    return 0;
}
