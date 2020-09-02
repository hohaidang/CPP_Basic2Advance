// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int times = 10000;
const int num = 100;
int fre[num];

vector<int> lotto(int tot,int sel)
{
    vector<int> totv;
    for(int i=1;i<=tot;++i) totv.push_back(i);
    random_shuffle(totv.begin(),totv.end());
    vector<int> selv;
    copy(totv.begin(),totv.begin()+sel,insert_iterator<vector<int> >(selv,selv.begin()));
    return selv;
}

int main()
{
    for(int i=0;i<times;++i){
        vector<int> temp = lotto(num,10);
        for(int x: temp) fre[x-1]++;
    }
    for(int i=0;i<num;++i) cout << fre[i] << endl;

    return 0;
}
