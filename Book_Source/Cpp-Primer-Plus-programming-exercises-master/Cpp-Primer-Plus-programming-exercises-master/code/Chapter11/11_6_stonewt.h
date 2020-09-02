// By luckycallor
// Welcome to my site: www.luckycallor.com

#ifndef STONEWT_H
#define STONEWT_H
#include<iostream>

class Stonewt
{
private:
    enum{Lbs_per_stn = 14};
    enum Mode{STN,PND,IPND};
    Mode mode;
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs,Mode form = PND);
    Stonewt(int stn,double lbs,Mode form = STN);
    Stonewt();
    void reset(double lbs,Mode form = PND);
    void reset(int stn,double lbs,Mode form = STN);
    ~Stonewt();
    Stonewt operator+(const Stonewt& w)const;
    Stonewt operator-(const Stonewt& w)const;
    Stonewt operator*(double n)const;
    bool operator==(const Stonewt& w)const {return pounds == w.pounds;};
    bool operator!=(const Stonewt& w)const {return pounds != w.pounds;};
    bool operator<=(const Stonewt& w)const {return pounds <= w.pounds;};
    bool operator>=(const Stonewt& w)const {return pounds >= w.pounds;};
    bool operator<(const Stonewt& w)const {return pounds < w.pounds;};
    bool operator>(const Stonewt& w)const {return pounds > w.pounds;};
    friend Stonewt operator*(double n,const Stonewt& w);
    friend std::ostream& operator<<(std::ostream& os,const Stonewt& w);
};
#endif // STONEWT_H

