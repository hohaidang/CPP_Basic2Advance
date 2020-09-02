// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    const int ArSize = 30;
    char firstName[ArSize],lastName[ArSize],fullName[ArSize];

    cout << "Enter your first name: ";
    cin.getline(firstName,ArSize);
    cout << "Enter your last name: ";
    cin.getline(lastName,ArSize);

    strcpy(fullName,lastName);
    strcpy(fullName+strlen(lastName),", ");
    strcpy(fullName+strlen(lastName)+2,firstName);

    cout << "Here's the information in a single string: " << fullName << endl;

    return 0;
}
