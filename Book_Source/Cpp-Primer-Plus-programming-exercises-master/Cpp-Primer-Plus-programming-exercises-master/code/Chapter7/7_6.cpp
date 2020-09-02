// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int Fill_array(double ar[],int maxn);
void Show_array(double ar[],int total);
void Reverse_array(double ar[],int total);

int main()
{
    double arr[10];
    int total;
    total = Fill_array(arr,10);
    Show_array(arr,total);
    Reverse_array(arr,total);
    Show_array(arr,total);
}

int Fill_array(double ar[], int maxn)
{
    int cnt = 0;
    cout << "Enter double numbers: ";
    while(cnt < maxn && cin >> ar[cnt]) cnt++;
    cout << cnt << " numbers saved" << endl;
    return cnt;
}

void Show_array(double ar[], int total)
{
    for(int i=0;i<total;++i) cout << ar[i] << " ";
    cout << endl;
}

void Reverse_array(double ar[], int total)
{
    int n = total/2;
    double temp;
    for(int i=0;i<n;++i){
        temp = ar[i];
        ar[i] = ar[total-i-1];
        ar[total-i-1] = temp;
    }
}
