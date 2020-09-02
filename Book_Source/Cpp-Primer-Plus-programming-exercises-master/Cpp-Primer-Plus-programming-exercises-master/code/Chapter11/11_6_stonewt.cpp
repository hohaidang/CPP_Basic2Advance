// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"11_6_stonewt.h"

Stonewt::Stonewt()
{
    mode = PND;
    stone = pounds = pds_left = 0;
}

Stonewt::Stonewt(int stn, double lbs,Mode form)
{
    mode = form;
    stone = stn;
    pds_left = lbs;
    pounds = lbs + Lbs_per_stn * stone;
}

Stonewt::Stonewt(double lbs,Mode form)
{
    mode = form;
    pounds = lbs;
    stone = (int)pounds / Lbs_per_stn;
    pds_left = pounds - stone * Lbs_per_stn;
}

void Stonewt::reset(double lbs, Mode form)
{
    mode = form;
    pounds = lbs;
    stone = (int)pounds / Lbs_per_stn;
    pds_left = pounds - stone * Lbs_per_stn;
}

void Stonewt::reset(int stn,double lbs,Mode form)
{
    mode = form;
    stone = stn;
    pds_left = lbs;
    pounds = stone * Lbs_per_stn + pds_left;
}

Stonewt::~Stonewt(){}

Stonewt Stonewt::operator+(const Stonewt& w)const
{
    return Stonewt(pounds+w.pounds);
}

Stonewt Stonewt::operator-(const Stonewt& w)const
{
    return Stonewt(pounds-w.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(n*pounds);
}

Stonewt operator*(double n,const Stonewt& w)
{
    return w*n;
}

std::ostream& operator<<(std::ostream& os,const Stonewt& w)
{
    if(w.mode == Stonewt::STN) os << w.stone << " stones," << w.pds_left << " pounds";
    else if(w.mode == Stonewt::PND) os << w.pounds << " pounds";
    else if(w.mode == Stonewt::IPND) os << (int)(w.pounds+0.5) << " pounds";
    else os << "Wrong Mode!\n";
    return os;
}

