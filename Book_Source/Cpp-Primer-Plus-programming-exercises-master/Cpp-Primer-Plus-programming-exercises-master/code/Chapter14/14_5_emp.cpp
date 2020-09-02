// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"14_5_emp.h"
#include<iostream>

using namespace std;

abstr_emp::~abstr_emp(){}

void abstr_emp::ShowAll()const
{
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
    cout << "Enter the first name: ";
    getline(cin,fname);
    cout << "Enter the last name: ";
    getline(cin,lname);
    cout << "Enter the job: ";
    getline(cin,job);
}

ostream& operator<<(ostream& os,const abstr_emp& e)
{
    os << "(" << e.fname << "," << e.lname << "," << e.job << ")";
    return os;
}

void employee::ShowAll()const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void manager::ShowAll()const
{
    abstr_emp::ShowAll();
    cout << "In charge of: " << inchargeof << endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the inchargeof: ";
    cin >> inchargeof;
    cin.get();
}

void fink::ShowAll()const
{
    abstr_emp::ShowAll();
    cout << "Report to: " << reportsto << endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the reportsto: ";
    getline(cin,reportsto);
}

void highfink::ShowAll()const
{
    manager::ShowAll();
    cout << "Report to: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the inchargeof: ";
    cin >> manager::InChargeOf();
    cin.get();
    cout << "Enter the reportsto: ";
    getline(cin,fink::ReportsTo());
}
