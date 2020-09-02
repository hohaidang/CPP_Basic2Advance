// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

void addItem(double ar [],double item,int index);
void showItem(double ar [],int total);
double Mean(double ar [],int total);

int main()
{
    int cnt = 0;
    double arr[10];
    double item;
    cout << "Enter at most ten numbers(non-number input to quit): " << endl;
    while(cnt < 10 && cin >> item) addItem(arr,item,cnt++);
    showItem(arr,cnt);
    double mean = Mean(arr,cnt);
    cout << "\nThe mean of the numbers: " << mean;
    return 0;
}

void addItem(double ar [], double item, int index)
{
    ar[index] = item;
}

void showItem(double ar [], int total)
{
    for(int i=0;i<total;++i) cout << ar[i] << " ";
}

double Mean(double ar [], int total)
{
    double mean = 0;
    for(int i=0;i<total;++i) mean += ar[i];
    return mean/total;
}
