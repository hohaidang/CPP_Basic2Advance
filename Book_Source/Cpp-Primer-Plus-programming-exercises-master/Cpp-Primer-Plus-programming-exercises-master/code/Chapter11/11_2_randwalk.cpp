// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include"11_2_vect.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    ofstream fout;
    fout.open("11_1_output.txt");
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while(cin >> target){
        cout << "Enter step length: ";
        if(!(cin >> dstep)) break;
        fout << "Target Distance: " << target << " Step Size: " << dstep << endl;
        while(result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep,direction,Vector::POL);
            fout << steps++ << ": " << result << endl;
            result = result + step;
        }
        fout << steps << ": " << result << endl;
        fout << "After " << steps << " steps, the subject has the following location:" << endl;
        fout << result << endl;
        fout << "or" << endl;
        result.polar_mode();
        fout << result << endl;
        fout << "Average outward distance per step = "
             << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0,0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n') continue;
    return 0;
}

