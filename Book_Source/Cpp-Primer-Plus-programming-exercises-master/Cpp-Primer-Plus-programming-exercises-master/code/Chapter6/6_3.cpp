// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore     " << "p) pianist" << endl;
    cout << "t) tree          " << "g) game" << endl;
    char c;
    int f = 0;
    while(cin.get(c)){
        switch(c)
        {
            case 'c':
                {
                    cout << "A maple is a carnivore." << endl;
                    f = 1;
                    break;
                }
            case 'p':
                {
                    cout << "A maple is a pianist." << endl;
                    f = 1;
                    break;
                }
            case 't':
                {
                    cout << "A maple is a tree." << endl;
                    f = 1;
                    break;
                }
            case 'g':
                {
                    cout << "A maple is a game." << endl;
                    f = 1;
                    break;
                }
            default:
                {
                    while(c != '\n') cin.get(c); // get the chars left;
                    cout << "Please enter a c, p, t, or g: ";
                }
        }
        if(f) break;
    }

    return 0;
}
