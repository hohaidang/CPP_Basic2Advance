#include <iostream>
#include <memory>
#include "widget.h"
using namespace std;

struct Task
{
	int mID;
	Task(int id) : mID(id)
	{
		cout << "Task::Constructor" << endl;
	} 
	~Task()
	{
		cout << "Task::Destructor" << endl;
	}
};

class Resource
{
public:
	Resource(){cout << "Resource acquire\n";}
	~Resource(){cout << "Resource destroyed\n";};
};

class LargeObject
{
private:
	int _data;
public:
	LargeObject() : _data(5) {}
	void DoSomething(){cout << "Do something\n";}
	int getData() {return _data; };
};

void ProcessLargeObject(LargeObject &lo)
{
	lo.DoSomething();
	cout << "_data = " << lo.getData() << endl;
}

void LegacyLargeObjectFunction(LargeObject *lo)
{
	lo->DoSomething();
}

int temp()
{
	{
		cout << "----Unique_ptr----" << endl;
		unique_ptr<Task> taskPtr(new Task(23));
		unique_ptr<Task> taskPtr2 = move(taskPtr);
		if(taskPtr == nullptr)
			cout << "taskPtr is empty" << endl;
		if(taskPtr2 != nullptr)
			cout << "taskPtr2 is not empty" << endl;
		cout << "ID = " << taskPtr2->mID << endl;
	}
	{
		cout << "----Shared_ptr----" << endl;
		Resource *res = new Resource;
		shared_ptr<Resource> ptr1(res);
		{
			shared_ptr<Resource> ptr2(ptr1); // share ptr with ptr2
			cout << "Killing one shared pointer\n";
			// shared pointer is not remove because still one ptr1 hold resource
		}
		cout << "Killing another shared pointer\n";

	}
	//{
	//	/*Crash because deallocate 2 times in just one Resource*/
	//	Resource *res = new Resource;
	//	shared_ptr<Resource> ptr1(res);
	//	{
	//		shared_ptr<Resource> ptr2(res);
	//		cout << "Killing one shared pointer\n";
	//	}
	//	cout << "Killing another shared pointer\n";
	//}

	{
		unique_ptr<LargeObject> pLarge(new LargeObject());
		pLarge->DoSomething();
		ProcessLargeObject(*pLarge); // Pass variable in argument 

		// Pass raw pointer to a legacy API
		LegacyLargeObjectFunction(pLarge.get());
	}
	system("pause");
	return 0;
}