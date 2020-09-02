// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include"11_1_vect.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int n;
    cout << "Enter target distance (q to quit): ";
    while(cin >> target){
        cout << "Enter step length: ";
        if(!(cin >> dstep)) break;
        cout << "Enter experiment times: ";
        if(!(cin >> n)) break;
        cout << "Target Distance: " << target << " Step Size: " << dstep << endl;
        unsigned long maxstep = 0;
        unsigned long minstep;
        double average = 0.0;
        for(int i=0;i<n;++i){
            while(result.magval() < target){
                direction = rand() % 360;
                step.reset(dstep,direction,Vector::POL);
                result = result + step;
                steps++;
            }
            maxstep = steps > maxstep ? steps : maxstep;
            minstep = (steps < minstep || i == 0) ? steps : minstep;
            average += steps;
            steps = 0;
            result.reset(0.0,0.0);
        }
        average /= (double)n;
        cout << "Max steps: " << maxstep << endl;
        cout << "Min steps: " << minstep << endl;
        cout << "Average steps: " << average << endl;
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n') continue;
    return 0;
}

