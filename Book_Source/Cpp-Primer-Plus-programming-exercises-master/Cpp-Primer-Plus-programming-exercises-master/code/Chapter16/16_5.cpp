// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
int reduce(T ar[],int n)
{
    vector<T> temp;
    for(int i=0;i<n;++i) temp.push_back(ar[i]);
    sort(temp.begin(),temp.end());
    auto ite = unique(temp.begin(),temp.end());
    return ite - temp.begin();
}

int main()
{
    long* ar;
    int n;
    cout << "How many numbers: ";
    cin >> n;
    cout << "Enter " << n << " numbers:\n";
    ar = new long[n];
    for(int i=0;i<n;++i) cin >> ar[i];
    int rn = reduce(ar,n);
    cout << "There are " << rn << " numbers after reduce.";

    return 0;
}

