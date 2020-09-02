// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<valarray>
#include<iostream>
#include<string>

using namespace std;

template<class T>
class Pair
{
private:
    T first;
    T second;
public:
    Pair(){}
    Pair(T item1,T item2):first(item1),second(item2){}
    const T& getFirst()const {return first;}
    const T& getSecond()const {return second;}
    T& getFirst() {return first;}
    T& getSecond() {return second;}
    void setFirst(T item){first = item;}
    void setSecond(T item){second = item;}
};

class Wine:private Pair<valarray<int> >
{
private:
    string label;
    int years;
public:
    Wine();
    Wine(const char* l,int y,const int yr[],const int bot[]):Pair<valarray<int> >(valarray<int>(yr,y),valarray<int>(bot,y)),label(l),years(y){}
    Wine(const char* l,int y);
    void GetBottles();
    string& Label(){return label;}
    int sum(){return Pair<valarray<int> >::getSecond().sum();}
    void Show() const;
};

Wine::Wine():Pair<valarray<int> >(valarray<int>(0),valarray<int>(0))
{
    label = "none";
    years = 0;
}

Wine::Wine(const char* l,int y):Pair<valarray<int> >(valarray<int>(y),valarray<int>(y))
{
    label = l;
    years = y;
}

void Wine::GetBottles()
{
    valarray<int>& temp = Pair<valarray<int> >::getSecond();
    valarray<int>& tempp = Pair<valarray<int> >::getFirst();
    int cnt = temp.size();
    for(int i=0;i<cnt;++i){
        cout << "Enter year: ";
        cin >> tempp[i];
        cout << "Enter bottles for that year: ";
        cin >> temp[i];
    }
}

void Wine::Show()const
{
    cout << "Wine: " << label << endl;
    const valarray<int>& temp = Pair<valarray<int> >::getSecond();
    const valarray<int>& tempp = Pair<valarray<int> >::getFirst();
    int cnt = temp.size();
    cout << "Year  " << "  Bottles" << endl;
    for(int i=0;i<cnt;++i) cout << "        " << tempp[i] << "    " << temp[i] << endl;
}

int main()
{
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab,50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab,yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = {1993,1995,1998};
    int b[YRS] = {48,60,72};
    Wine more("Gushing Grape Red",YRS,y,b);
    more.Show();
    cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
    cout << "Bye!\n";
    return 0;
}

