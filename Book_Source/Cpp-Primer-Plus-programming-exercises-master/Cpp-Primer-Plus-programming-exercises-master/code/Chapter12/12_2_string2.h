// By luckycallor
// Welcome to my site: www.luckycallor.com

#ifndef STRING2_H
#define STRING2_H
#include<iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char*s);
    String();
    String(const String&);
    ~String();
    int length() const {return len;}

    String& operator=(const String& );
    String& operator=(const char* s);
    char& operator[](int i);
    const char& operator[](int i) const;
    void stringlow();
    void stringup();
    int has(char c) const;

    friend String operator+(const String& st1,const String& st2);
    friend String operator+(const String& st,const char* cst);
    friend String operator+(const char* cst,const String& st);
    friend bool operator<(const String& st1,const String& st2);
    friend bool operator>(const String& st1,const String& st2);
    friend bool operator==(const String& st1,const String& st2);
    friend ostream& operator<<(ostream& os,const String& st);
    friend istream& operator>>(istream& is,String& st);

    static int HowMany();
};
#endif // STRING2_H
