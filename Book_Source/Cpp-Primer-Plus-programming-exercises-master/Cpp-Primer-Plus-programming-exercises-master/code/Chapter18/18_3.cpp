// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

template<typename Tval,typename... Targs>
long double sum_value(Tval val,Targs... args)
{
    long double sum;
    sum = (long double)val + sum_value(args...);
    return sum;
}

template<typename Tval>
long double sum_value(Tval val)
{
    return (long double)val;
}

int main()
{
    long double sum;
    sum = sum_value(1,5,8.9);
    cout << sum << endl;
    sum = sum_value(1.8,89,9,'d');
    cout << sum << endl;

    return 0;
}
