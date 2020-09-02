// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"17_6_emp.h"
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

void abstr_emp::WriteAll(ofstream& fout) const
{
    fout << fname << endl;
    fout << lname << endl;
    fout << job << endl;
}

void abstr_emp::GetAll(ifstream& fin)
{
    getline(fin,fname);
    getline(fin,lname);
    getline(fin,job);
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

void employee::WriteAll(ofstream& fout)const
{
    fout << Employee << endl;
    abstr_emp::WriteAll(fout);
}

void employee::GetAll(ifstream& fin)
{
    abstr_emp::GetAll(fin);
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

void manager::WriteAll(ofstream& fout)const
{
    fout << Manager << endl;
    abstr_emp::WriteAll(fout);
    fout << inchargeof << endl;
}

void manager::GetAll(ifstream& fin)
{
    abstr_emp::GetAll(fin);
    fin >> inchargeof;
    fin.get();
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

void fink::WriteAll(ofstream& fout)const
{
    fout << Fink << endl;
    abstr_emp::WriteAll(fout);
    fout << reportsto << endl;
}

void fink::GetAll(ifstream& fin)
{
    abstr_emp::GetAll(fin);
    getline(fin,reportsto);
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

void highfink::WriteAll(ofstream& fout)const
{
    fout << Highfink << endl;
    abstr_emp::WriteAll(fout);
    fout << manager::InChargeOf() << endl;
    fout << fink::ReportsTo() << endl;
}

void highfink::GetAll(ifstream& fin)
{
    abstr_emp::GetAll(fin);
    (fin >> manager::InChargeOf()).get();
    getline(fin,fink::ReportsTo());
}

