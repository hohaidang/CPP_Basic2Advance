// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<cstring>
#include"13_3_dma.h"

using namespace std;

ABCDMA::ABCDMA(const char* l, int r)
{
    label = new char[strlen(l)+1];
    strcpy(label,l);
    rating = r;
}

ABCDMA::ABCDMA(const ABCDMA& rs)
{
    label = new char[strlen(rs.label)+1];
    strcpy(label,rs.label);
    rating = rs.rating;
}

ABCDMA::~ABCDMA()
{
    delete [] label;
}

void ABCDMA::View()const
{
    cout << "Label: " << label << endl;
    cout << "Rating: " << rating << endl;
}

ABCDMA& ABCDMA::operator=(const ABCDMA& rs)
{
    if(this == &rs) return *this;
    delete [] label;
    label = new char[strlen(rs.label)+1];
    strcpy(label,rs.label);
    rating = rs.rating;
    return *this;
}

ostream& operator<<(ostream& os,const ABCDMA& rs)
{
    os << "Label: " << rs.label << endl;
    os << "Rating: " << rs.rating << endl;
    return os;
}

ostream& operator<<(ostream& os,const baseDMA& rs)
{
    os << (const ABCDMA&)rs;
    return os;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r): ABCDMA(l,r)
{
    strncpy(color,c,39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const ABCDMA& rs): ABCDMA(rs)
{
    strncpy(color,c,COL_LEN-1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View()const
{
    ABCDMA::View();
    cout << "Color: " << color << endl;
}

lacksDMA& lacksDMA::operator=(const lacksDMA& rs)
{
    ABCDMA::operator=(rs);
    strcpy(color,rs.color);
    return *this;
}

ostream& operator<<(ostream& os,const lacksDMA& ls)
{
    os << (const ABCDMA&) ls;
    os << "Color: " << ls.color << endl;
    return os;
}

hasDMA::hasDMA(const char* s, const char* l, int r):ABCDMA(l,r)
{
    style = new char[strlen(s)+1];
    strcpy(style,s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs):ABCDMA(rs)
{
    style = new char[strlen(s)+1];
    strcpy(style,s);
}

hasDMA::hasDMA(const hasDMA& hs):hasDMA(hs)
{
    style = new char[strlen(hs.style)+1];
    strcpy(style,hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

void hasDMA::View()const
{
    ABCDMA::View();
    cout << "Style: " << style << endl;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
    if(this == &hs) return *this;
    ABCDMA::operator=(hs);
    delete [] style;
    style = new char[strlen(hs.style)+1];
    strcpy(style,hs.style);
    return *this;
}

ostream& operator<<(ostream& os,const hasDMA& hs)
{
    os << (const ABCDMA&)hs;
    os << "Style: " << hs.style << endl;
    return os;
}


