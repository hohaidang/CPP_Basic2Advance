// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"11_4_time.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time& t1,const Time& t2)
{
    Time sum(t1.hours,t1.minutes);
    sum.AddHr(t2.hours);
    sum.AddMin(t2.minutes);
    return sum;
}

Time operator-(const Time& t1,const Time& t2)
{
    Time diff;
    int m1,m2;
    m1 = t1.minutes + 60*t1.hours;
    m2 = t2.minutes + 60*t2.hours;
    diff.hours = (m1-m2) / 60;
    diff.minutes = (m1-m2) % 60;
    return diff;
}

Time operator*(const Time& t,double n)
{
    Time result;
    result.minutes = (t.minutes + t.hours * 60) * n;
    result.hours = result.minutes / 60;
    result.minutes %= 60;
    return result;
}

Time operator*(double n,const Time& t)
{
    return t*n;
}

std::ostream& operator<<(std::ostream& os,const Time& t)
{
    os << t.hours << " hours " << t.minutes << " minutes";
    return os;
}




