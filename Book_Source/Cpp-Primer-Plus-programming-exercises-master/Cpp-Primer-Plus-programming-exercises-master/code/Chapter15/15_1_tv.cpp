// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include"15_1_tv.h"

bool Tv::volup()
{
    if(volume < MaxVal){
        volume++;
        return true;
    }
    else{
        return false;
    }
}

bool Tv::voldown()
{
    if(volume > MinVal){
        volume--;
        return true;
    }
    else return false;
}

bool Tv::turn_pat(Remote& r)const
{
    if(state == On) r.pattern = (r.pattern == Remote::Normal)? Remote::Interactive : Remote::Normal;
    else return false;
    return true;
}

void Tv::chanup()
{
    if(channel < maxchannel) channel++;
    else channel = 1;
}

void Tv::chandown()
{
    if(channel > 1) channel--;
    else channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off":"On") << endl;
    if(state == On){
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = " << (mode == Antenna? "Antenna":"Cable") << endl;
        cout << "Input = " << (input == TV? "TV":"DVD") << endl;
    }
}
