// By luckycallor
// Welcome to my site: www.luckycallor.com

#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>

using namespace std;

class Person
{
private:
    string firstname;
    string familyname;
protected:
    virtual void Data()const;
    virtual void Set();
public:
    Person(const char* str1 = "none",const char* str2 = "none"):firstname(str1),familyname(str2){}
    Person(const Person& p):firstname(p.firstname),familyname(p.familyname){}
    virtual ~Person() =0;
    virtual void Show()const;
    virtual void Get();
};

class Gunslinger:virtual public Person
{
private:
    double time;
    int nicks;
protected:
    virtual void Data()const;
    virtual void Set();
public:
    Gunslinger(const char* str1 = "none",const char* str2 = "none",double t = 0.0, int n = 0):Person(str1,str2),time(t),nicks(n){}
    Gunslinger(const Person& p,double t = 0.0,int n = 0):Person(p),time(t),nicks(n){}
    Gunslinger(const Gunslinger& gs):Person(gs),time(gs.time),nicks(gs.nicks){}
    virtual void Show()const;
    virtual void Get();
    virtual double Draw()const {return time;}
};

class PokerPlayer:virtual public Person
{
public:
    PokerPlayer(const char* str1 = "none",const char* str2 = "none"):Person(str1,str2){}
    PokerPlayer(const PokerPlayer& pp):Person(pp){}
    virtual int Draw()const;
    virtual void Show()const;
    virtual void Get();
};

class BadDude:public Gunslinger,public PokerPlayer
{
public:
    BadDude(const char* str1 = "none",const char* str2 = "none",double t = 0.0, int n = 0)
    :Person(str1,str2),Gunslinger(str1,str2,t,n),PokerPlayer(str1,str2){}
    BadDude(const BadDude& bd):Person(bd),Gunslinger(bd),PokerPlayer(bd){}
    virtual double Gdraw()const;
    virtual int Cdraw()const;
    virtual void Show()const;
    virtual void Get();
};

#endif // PERSON_H
