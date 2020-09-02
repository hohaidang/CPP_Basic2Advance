// By luckycallor
// Welcome to my site: www.luckycallor.com

#ifndef DMA_H
#define DMA_H
#include<iostream>

using namespace std;

class ABCDMA
{
private:
    char* label;
    int rating;
public:
    ABCDMA(const char* l = "null",int r = 0);
    ABCDMA(const ABCDMA& rs);
    virtual ~ABCDMA() =0;
    virtual void View()const;
    virtual ABCDMA& operator=(const ABCDMA& rs);
    friend ostream& operator << (ostream& os,const ABCDMA& rs);
};

class baseDMA: public ABCDMA
{
public:
    baseDMA(const char* l = "null",int r = 0):ABCDMA(l,r){};
    baseDMA(const baseDMA& rs):ABCDMA(rs){};
    virtual ~baseDMA(){}
    virtual void View(){ABCDMA::View();}
    virtual baseDMA& operator=(const baseDMA& rs){ABCDMA::operator=(rs);return *this;}
    friend ostream& operator << (ostream& os,const baseDMA& rs);
};

class lacksDMA: public ABCDMA
{
private:
    enum{COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank",const char* l = "null",int r = 0);
    lacksDMA(const char*c,const ABCDMA& rs);
    virtual ~lacksDMA(){}
    virtual void View()const;
    virtual lacksDMA& operator=(const lacksDMA& rs);
    friend ostream& operator<<(ostream& os,const lacksDMA& rs);
};

class hasDMA: public ABCDMA
{
private:
    char* style;
public:
    hasDMA(const char* s = "none",const char* l = "null",int r = 0);
    hasDMA(const char* s,const baseDMA& rs);
    hasDMA(const hasDMA& hs);
    virtual ~hasDMA();
    virtual void View()const;
    virtual hasDMA& operator=(const hasDMA& hs);
    friend ostream& operator << (ostream& os,const hasDMA& rs);
};

#endif // DMA_H
