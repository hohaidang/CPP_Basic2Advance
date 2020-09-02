// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

const int Seasons = 4;
const char Snames[Seasons][20] = {{"Spring"},{"Summer"},{"Fall"},{"Winter"}};

struct arr
{
    double items[Seasons];
};

void fill(arr* pa);
void show(arr da);

int main()
{
    arr expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}


void fill(arr* pa)
{
    for(int i=0;i < Seasons;i++){
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa->items[i];
    }
}

void show(arr da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i=0;i<Seasons;i++){
        cout << Snames[i] << ": $" << da.items[i] << endl;
        total += da.items[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

