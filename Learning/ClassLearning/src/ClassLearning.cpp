////============================================================================
//// Name        : ClassLearning.cpp
//// Author      : Dang
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include <iostream>
//using namespace std;
//
//class Me
//{
//private:
//	int MyMoney;
//public:
//	Me()
//	{
//		MyMoney = 10; // 10$
//	}
//	friend class MyFriend; // Friend class MyFriend
//};
//
//class MyFriend
//{
//private:
//	 int MyFriendMoney; // 5$
//public:
//	 void showMoney(Me &x)
//	 {
//		 cout << "A::a = " << x.MyMoney << endl;
//	 }
//	 void useMoney(Me &x, int moneyToUse)
//	 {
//		 x.MyMoney -= moneyToUse;
//		 cout << "Money left = " << x.MyMoney << endl;
//	 }
//};
//
//class Geeks
//{
//public:
//	int id;
//	/*Constructor */
//	Geeks()
//	{
//		cout << "Default Constructor called" << endl;
//		id = - 1;
//	}
//
//	/*Constructor with parameter*/
//	Geeks(int x)
//	{
//		cout << "Parameter Constructor called" << endl;
//		id = x;
//	}
//
//	/*Destructor*/
//	~Geeks()
//	{
//		cout << "Desutructor called for id: " << id << endl;
//	}
//};
//
//
//int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	Geeks obj(1);
//	obj.id = 7;
//	int i = 0;
//	while (i < 5)
//	{
//		Geeks obj2;
//		obj2.id = i;
//		i++;
//	} // scope for object 2 ended here
//	//scope for object 1 ended here
//
//	Me Dang;
//	MyFriend ConChoNaoDo;
//	ConChoNaoDo.showMoney(Dang);
//	ConChoNaoDo.useMoney(Dang, 5);
//	return 0;
//}


//------------- Protected Class --------------
#include <iostream>
using namespace std;

class Parent{
protected: // private
	int id_protected;
};

class Child: Parent
{
public:
	void setID(int id)
	{
		id_protected = id;// Child class is able to access the inherited
        // protected data members of the base class
		// Private: just can access by interal of a class
	}

	void displayID()
	{
		cout << "id_protected is: " << id_protected << endl;
	}
};

int main() {
	Child obj1;
	obj1.setID(81);
	obj1.displayID();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
