// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

struct BOX
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void showBox(BOX box);
void addVolume(BOX* box);

int main()
{
    BOX box;
    cout << "Enter the maker of the box: ";
    cin.getline(box.maker,40);
    //cin.get();
    cout << "Enter the height of the box: ";
    cin >> box.height;
    cin.get();
    cout << "Enter the width of the box: ";
    cin >> box.width;
    cin.get();
    cout << "Enter the length of the box: ";
    cin >> box.length;
    cin.get();
    addVolume(&box);
    cout << "The information of the box:" << endl;
    showBox(box);
}

void showBox(BOX box)
{
    cout << "maker: " << box.maker << endl;
    cout << "height: " << box.height << endl;
    cout << "width: " << box.width << endl;
    cout << "length: " << box.length << endl;
    cout << "volume: " << box.volume << endl;
}

void addVolume(BOX* box)
{
    box->volume = box->height * box->length * box->width;
}
