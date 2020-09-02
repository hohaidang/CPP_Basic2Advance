// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cmath>
#include<stdexcept>

using namespace std;

class bad_hmean:public exception
{
public:
    const char* what(){return "bad arguments to hmean()";}
};

class bad_gmean:public exception
{
public:
    const char* what(){return "bad arguments to gmean()";}
};

double hmean(double a,double b);
double gmean(double a,double b);

int main()
{
    double x,y,z;

    cout << "Enter two numbers: ";
    while(cin >> x >> y){
        try{
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch(bad_hmean& bg)
        {
            //bg.mesg();
            cout << bg.what() << endl;
            cout << "Enter two numbers: ";
            continue;
        }
        catch(bad_gmean& hg)
        {
            cout << hg.what() << endl;
            cout << "Sorry,you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a,double b)
{
    if(a == -b) throw bad_hmean();
    return 2.0*a*b/(a+b);
}

double gmean(double a,double b)
{
    if(a < 0 || b <0) throw bad_gmean();
    return sqrt(a*b);
}
