// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>
#include"14_4_person.h"

const int SIZE = 5;

using namespace std;

int main()
{
    Person* lolas[SIZE];
    int ct;
    for(ct = 0;ct < SIZE;++ct){
        char choice;
        cout << "Enter the person category:\n"
        << "g: Gunslinger  p: PokerPlayer  b: BadDude  q: quit\n";
        cin >> choice;
        while(strchr("gpbq",choice) == NULL){
            cout << "Please enter a g,p,b or q: ";
            cin >> choice;
        }
        if(choice == 'q') break;
        switch(choice)
        {
            case 'g': lolas[ct] = new Gunslinger;
            break;
            case 'p': lolas[ct] = new PokerPlayer;
            break;
            case 'b': lolas[ct] = new BadDude;
            break;
        }
        cin.get();
        lolas[ct]->Get();
    }

    cout << "\nHere is the people:\n";
    int i;
    for(i = 0;i<ct;++i){
        cout << endl;
        lolas[i]->Show();
    }
    for(i=0;i<ct;++i) delete lolas[i];
    cout << "Bye.\n";
    return 0;
}
