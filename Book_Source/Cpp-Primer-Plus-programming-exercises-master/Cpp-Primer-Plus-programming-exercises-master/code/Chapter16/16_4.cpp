// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int reduce(long ar[],int n)
{
    vector<long> temp;
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
    delete [] ar;

    return 0;
}
