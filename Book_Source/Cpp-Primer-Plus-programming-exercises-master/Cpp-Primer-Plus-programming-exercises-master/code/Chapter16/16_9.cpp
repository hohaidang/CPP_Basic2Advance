// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<vector>
#include<iostream>
#include<list>
#include<ctime>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int SIZE = 1000000;

vector<int> vi0;
vector<int> vi(SIZE);
list<int> li(SIZE);

int main()
{
    srand(time(0));
    for(int i=0;i<SIZE;++i) vi0.push_back(rand());
    copy(vi0.begin(),vi0.end(),vi.begin());
    copy(vi0.begin(),vi0.end(),li.begin());
    cout << "Time used in sorting by vector: ";
    clock_t start = clock();
    sort(vi.begin(),vi.end());
    clock_t end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC << "s" << endl;
    cout << "Time used in sorting by list: ";
    li.sort();
    end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC << "s" << endl;
    copy(vi0.begin(),vi0.end(),li.begin());
    cout << "Time used in sorting list by vector: ";
    start = clock();
    copy(li.begin(),li.end(),vi.begin());
    sort(vi.begin(),vi.end());
    copy(vi.begin(),vi.end(),li.begin());
    end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
