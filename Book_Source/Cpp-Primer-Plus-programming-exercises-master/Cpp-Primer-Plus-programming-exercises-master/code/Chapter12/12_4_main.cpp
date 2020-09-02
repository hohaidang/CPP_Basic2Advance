// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include"12_4_stack.h"

using namespace std;

int main()
{
    Stack s1;
    Stack s2(10);
    int item;
    for(int i=1;i<=10;++i) s1.push(i);
    s2 = s1;
    for(int i=0;i<5;++i){
        s2.pop(item);
        cout << item << ' ';
    }
    cout << endl;
    Stack s3(s2);
    int n = 10;
    while(!s3.isfull()) s3.push(n--);
    while(!s3.isempty()){
        s3.pop(item);
        cout << item << ' ';
    }
    cout << endl;

    return 0;
}

