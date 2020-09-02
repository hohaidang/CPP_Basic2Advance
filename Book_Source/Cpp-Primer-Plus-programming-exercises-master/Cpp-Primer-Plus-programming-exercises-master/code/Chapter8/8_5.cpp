// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

template<typename T>
T max5(T arr[])
{
    T m = arr[0];
    for(int i=1;i<5;++i){
        if(arr[i] > m) m = arr[i];
    }
    return m;
}

int main()
{
    int arr_int[5] = {1,2,3,4,5};
    double arr_double[5] = {1.1,2.2,3.3,4.4,5.5};
    cout << "The max in the int array: " << max5(arr_int) << endl;
    cout << "The max in the double array: " << max5(arr_double) << endl;

    return 0;
}
