// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

const int Max = 5;

double* fill_array(double* begp,double* endp);
void show_array(double* begp,double* endp);
void revalue(double r,double* begp,double* endp);

int main()
{
    double properties[Max];
    double* pos = fill_array(properties,properties+Max);
    show_array(properties,pos);
    if(pos != properties){
        cout << "Enter revalustion factor: ";
        double factor;
        while(!(cin >> factor)){
            cin.clear();
            while(cin.get() != '\n') continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor,properties,pos);
        show_array(properties,pos);
    }
    cout << "Done\n";
    cin.get();
    cin.get();
    return 0;
}

double* fill_array(double* begp, double* endp)
{
    double temp;
    double* curp;
    int cnt;
    for(curp = begp,cnt = 0;curp != endp;curp++,cnt++){
        cout << "Enter value #" << (cnt+1) << ":";
        cin >> temp;
        if(!cin){
            cin.clear();
            while(cin.get() != '\n') continue;
            cout << "Bad input;input process terminated.\n";
            break;
        }
        else if(temp < 0) break;
        *curp = temp;
    }
    return curp;
}

void show_array(double* begp, double* endp)
{
    int i=0;
    for(double* curp = begp;curp != endp;curp++){
        cout << "Property #" << ++i << ": $";
        cout << *curp << endl;
    }
}

void revalue(double r, double* begp, double* endp)
{
    for(double* curp = begp;curp != endp;curp++) (*curp) *= r;
}
