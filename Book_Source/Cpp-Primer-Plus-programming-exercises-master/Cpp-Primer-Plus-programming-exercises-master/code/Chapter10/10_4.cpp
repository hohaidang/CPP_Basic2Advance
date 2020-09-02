// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

class Sales
{
private:
    static const int QUARTERS = 4;
    double sales[QUARTERS];
    double average;
    double max;
    double min;
public:
    Sales();
    Sales(const double ar[],int n);
    void setSales();
    void showSales()const;
};

Sales::Sales()
{
    for(int i=0;i<4;++i) sales[i] = 0.0;
    max = 0;
    min = 0;
    average = 0;
}

Sales::Sales(const double ar[], int n)
{
    if(n > 4) n = 4;
    for(int i=0;i<n;++i) sales[i] = ar[i];
    for(int i=n;i<4;++i) sales[i] = 0.0;
    max = sales[0];
    min = sales[0];
    average = sales[0];
    for(int i=1;i<4;++i){
        max = sales[i] > max ? sales[i] : max;
        min = sales[i] < min ? sales[i] : min;
        average += sales[i];
    }
    average /= 4.0;
}

void Sales::setSales()
{
    int cnt = 0;
    average = 0;
    for(cnt = 0;cnt < 4;++cnt){
        cout << "Enter the sale in season " << cnt+1 << ": ";
        cin >> sales[cnt];
        cin.get();
        average += sales[cnt];
    }
    average /= 4.0;
    max = sales[0];
    min = sales[0];
    for(int i=i;i<4;++i){
        max = sales[i] > max ? sales[i] : max;
        min = sales[i] < min ? sales[i] : min;
    }
}

void Sales::showSales() const
{
    cout << "Sales in four seasons: "
    << sales[0] << " " << sales[1] << " " << sales[2] << " " << sales[3] << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Average: " << average << endl;
}

int main ()
{
    double ar[4] = {2348.90,84783.72,7832.56,34292.26};
    Sales sales1(ar,4);
    Sales sales2;
    sales2.setSales();
    sales1.showSales();
    sales2.showSales();

    return 0;
}
