// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"14_4_person.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

Person::~Person(){}

void Person::Data()const
{
    cout << "  " << "Firstname: " << firstname << endl;
    cout << "  " << "Familyname: " << familyname << endl;
}

void Person::Set()
{
    cout << "Enter the firstname: ";
    getline(cin,firstname);
    cout << "Enter the familyname: ";
    getline(cin,familyname);
}

void Person::Show()const
{
    cout << "Person:\n";
    Data();
}

void Person::Get()
{
    Set();
}

void Gunslinger::Data()const
{
    cout << "  " << "Time: " << time << endl;
    cout << "  " << "Nicks: " << nicks << endl;
}

void Gunslinger::Set()
{
    cout << "Enter the time: ";
    cin >> time;
    cout << "Enter the nicks: ";
    cin >> nicks;
    while(cin.get() != '\n')continue;
}

void Gunslinger::Show()const
{
    cout << "Gunslinger:" << endl;
    Person::Data();
    Data();
}

void Gunslinger::Get()
{
    Person::Set();
    Set();
}

int PokerPlayer::Draw()const
{
    srand(time(0));
    return rand()%52 + 1;
}

void PokerPlayer::Show()const
{
    cout << "PokerPlayer: \n";
    Person::Data();
}

void PokerPlayer::Get()
{
    Person::Set();
}

double BadDude::Gdraw()const
{
   return Gunslinger::Draw();
}

int BadDude::Cdraw()const
{
    return PokerPlayer::Draw();
}

void BadDude::Show()const
{
    cout << "BadDude:\n";
    Person::Data();
    Gunslinger::Data();
}

void BadDude::Get()
{
    Person::Set();
    Gunslinger::Set();
}



