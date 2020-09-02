// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<cstring>
#include<cctype>
#include"12_2_string2.h"

using std::cin;
using std::cout;
using std::endl;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char* s)
{
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[len+1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String& st)
{
    num_strings++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

String& String::operator=(const String& st)
{
    if(this == &st) return *this;
    delete [] str;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
    return *this;
}

String& String::operator=(const char* s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    return *this;
}

char& String::operator[](int i)
{
    return str[i];
}

const char& String::operator[](int i)const
{
    return str[i];
}

String operator+(const String& st1,const String& st2)
{
    char temp[st1.len+st2.len+1];
    std::strcpy(temp,st1.str);
    std::strcpy(temp+st1.len,st2.str);
    return String(temp);
}

String operator+(const String& st,const char* cst)
{
    char temp[st.len+std::strlen(cst)+1];
    std::strcpy(temp,st.str);
    std::strcpy(temp+st.len,cst);
    return String(temp);
}

String operator+(const char* cst,const String& st)
{
    char temp[std::strlen(cst)+st.len+1];
    std::strcpy(temp,cst);
    std::strcpy(temp+std::strlen(cst),st.str);
    return String(temp);
}

void String::stringlow()
{
    for(int i=0;i<len;++i) str[i] = std::tolower(str[i]);
}

void String::stringup()
{
    for(int i=0;i<len;++i) str[i] = std::toupper(str[i]);
}
int String::has(char c) const
{
    int cnt = 0;
    for(int i=0;i<len;++i){
        if(str[i] == c) cnt++;
    }
    return cnt;
}

bool operator<(const String& st1,const String& st2)
{
    return (std::strcmp(st1.str,st2.str) < 0);
}

bool operator>(const String& st1,const String& st2)
{
    return st2 < st1;
}

bool operator==(const String& st1,const String& st2)
{
    return (std::strcmp(st1.str,st2.str) == 0);
}

ostream& operator<<(ostream& os,const String& st)
{
    os << st.str;
    return os;
}

istream& operator>>(istream& is,String& st)
{
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if(is) st = temp;
    while(is && is.get() != '\n') continue;

    return is;
}
