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
    CandyBar snack[3] = {
                            {"Mocha Munch",2.3,350},
                            {"Mocha Munch",2.3,350},
                            {"Mocha Munch",2.3,350}
                        };
    for(int i=0;i<3;++i){
        cout << "snack_" << i << ":\n";
        cout << "      Brand: " << snack[i].brand << endl;
        cout << "      Weight: " << snack[i].weight << endl;
        cout << "      Calory: " << snack[i].calory << endl;
    }

    return 0;
}
