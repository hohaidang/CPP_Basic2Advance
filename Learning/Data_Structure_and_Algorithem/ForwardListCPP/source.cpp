#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
	forward_list<int> fl1;
	forward_list<int> fl2;
	
	fl1.assign({1, 2, 3}); // add value 1, 2, 3 to flist 1
	fl2.assign(5, 10); // add 5 times value of 10
	
	cout << "list 1: ";
	for(int &val : fl1) {
		cout << val << " ";
	}
	cout << endl;
	
	cout << "list 2: ";
	for(int &val : fl2) {
		cout << val << " ";
	}
	cout << endl;
	
	
	forward_list<int> flist1 = {10, 20, 30}; 
	forward_list<int> flist2 = {40, 50, 60}; 
	// Shifting elements from first to second 
    // forward list after 1st position 
    flist2.splice_after(flist2.begin(),flist1); 
      
    // Displaying the forward list 
    cout << "The forward list after splice_after operation : "; 
    for (int&c : flist2)  
       cout << c << " "; 
    cout << endl; 
  
	return 0;
}