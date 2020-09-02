// By luckycallor
// Welcome to my site: www.luckycallor.com

#include "stdafx.h"
#include"14_3_worker.h"
#include<iostream>

using namespace std;

void Worker::Data()const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin,fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while(cin.get() != '\n') continue;
}

void Waiter::Set()
{
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while(cin.get() != '\n') continue;
}

char* Singer::pv[Singer::Vtype] = {"other","alto","contralto","soprano","bass","baritone","tenor"};

void Singer::Set()
{
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}

void Singer::Data() const
{
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout << "Enter number for singer's vocal ranger: \n";
    int i;
    for(i=0;i<Vtype;++i){
        cout << i << ": " << pv[i] << "  ";
        if(i%4 == 3) cout << endl;
    }
    if(i%4 != 0) cout << endl;
    cin >> voice;
    while(cin.get() != '\n') continue;
}

void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set()
{
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const
{
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}
