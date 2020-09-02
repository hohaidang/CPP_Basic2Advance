// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cmath>
#include<stdexcept>

using namespace std;

class bad_mean:public logic_error
{
private:
    double a;
    double b;
public:
    bad_mean(const double& aa,const double& bb):logic_error(""),a(aa),b(bb){}
    virtual void show() const;
};

class bad_hmean:public bad_mean
{
public:
    bad_hmean(const double& aa,const double& bb):bad_mean(aa,bb){}
    virtual void show() const;
};

class bad_gmean:public bad_mean
{
public:
    bad_gmean(const double& aa,const double& bb):bad_mean(aa,bb){}
    virtual void show() const;
};

void bad_mean::show()const
{
    cout << "Bad arguments: " << a << ", " << b << endl;
}

void bad_hmean::show()const
{
    cout << "Function: hmean()\n";
    bad_mean::show();
}

void bad_gmean::show()const
{
    cout << "Function: gmean()\n";
    bad_mean::show();
}

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
        catch(bad_mean& bm)
        {
            bm.show();
            cout << "Sorry,you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a,double b)
{
    if(a == -b) throw bad_hmean(a,b);
    return 2.0*a*b/(a+b);
}

double gmean(double a,double b)
{
    if(a < 0 || b <0) throw bad_gmean(a,b);
    return sqrt(a*b);
}

