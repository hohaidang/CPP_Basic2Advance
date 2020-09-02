// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

template<typename T>
T maxn(T arr[],int n)
{
    T m = arr[0];
    for(int i=1;i<n;++i){
        m = arr[i] > m ? arr[i] : m;
    }
    return m;
}

template<> char* maxn<char*>(char* arr[],int n)
{
    char* str = arr[0];
    unsigned int m = strlen(str);
    for(int i=1;i<n;++i){
        if(strlen(arr[i]) > m){
            m = strlen(arr[i]);
            str = arr[i];
        }
    }
    return str;
}

int main()
{
    int arr_int[6] = {1,2,3,4,5,6};
    double arr_double[4] = {1.1,2.2,3.3,4.4};
    const char* arr_str[5] = {"string 1 !","string 2: hhd!","strin 3","str4:best.","string 5: the longest!!"};
    cout << "The max in int array: " << maxn(arr_int,6) << endl;
    cout << "The max in double array: " << maxn(arr_double,4) << endl;
    cout << "The max in char* array: " << maxn(arr_str,5) << endl;

    return 0;
}
