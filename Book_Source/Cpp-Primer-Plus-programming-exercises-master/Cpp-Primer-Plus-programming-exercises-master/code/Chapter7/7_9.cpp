// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[],int n);
void display1(student st);
void display2(student* st);
void display3(const student pa[],int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n') continue;
    student* ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu,class_size);
    for(int i=0;i<entered;++i){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu,entered);
    delete [] ptr_stu;
    cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n)
{
    int cnt = 0;
    char buff[SLEN];
    cout << "Enter the fullname of the student: ";
    while(cnt < n && cin.getline(buff,SLEN)){
        if(buff[0] == ' ') break;
        strcpy(pa[cnt].fullname,buff);
        cout << "Enter the hobby of the student: ";
        cin.getline(pa[cnt].hobby,SLEN);
        cout << "Enter the ooplevel of the student: ";
        cin >> pa[cnt].ooplevel;
        cin.get();
        cnt++;
        cout << "Enter the fullname of the student: ";
    }
    return cnt;
}

void display1(student st)
{
    cout << "fullname: " << st.fullname << endl;
    cout << "hobby: " << st.hobby << endl;
    cout << "ooplevel: " << st.ooplevel << endl;
}

void display2(student* st)
{
    cout << "fullname: " << st->fullname << endl;
    cout << "hobby: " << st->hobby << endl;
    cout << "ooplevel: " << st->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    for(int i=0;i<n;++i){
        cout << "Student #" << (i+1) << ": " << endl;
        cout << "fullname: " << pa[i].fullname << endl;
        cout << "hobby: " << pa[i].hobby << endl;
        cout << "ooplevel: " << pa[i].ooplevel << endl;
    }
}
