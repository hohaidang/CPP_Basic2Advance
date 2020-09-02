#include <iostream>
using namespace std;

class Bird
{
public:
	string birdName;

};

class FlyingBird : public Bird
{
public:
	/*Pure function make sure all derived class has to have an implementation for this fly(). If it doesnot, compiler will error.*/
	virtual void fly(double speed, double direction) = 0; // pure virtual function
};

class Vulture : public FlyingBird
{
	string flyingBirdName;
public:
	virtual void fly(double speed, double direction)
	{
		cout << "This is Vilture" << endl;
		cout << "Virtual speed is: " << speed << endl;
	}
};

class Eagle : public FlyingBird, public Bird
{
public:
	virtual void fly(double speed, double direction) override
	{
		cout << "This is Eagle" << endl;
		cout << "Eagle speed is: " << speed << endl;
		cout << "Eagle age: " << eagleAge << endl;
	}
private:
	int eagleAge = 10;
};

void hunt(FlyingBird &b)
{
	b.fly(5, 10);
}

int main()
{
	//Vulture vulture;
	//Eagle eagle;
	//hunt(vulture);
	//hunt(eagle);

	//Eagle* e = new Eagle; 
	//Bird *b = e; // base class can be casted to derived class (only small can cast to big) (no lost data)
	//FlyingBird *f = e;
	//Bird *sb = static_cast<Eagle *>(e);
	//FlyingBird *df = dynamic_cast<Eagle *>(e);

	Bird *b = new Eagle;
	//FlyingBird *df = dynamic_cast<FlyingBird *>(b);

	return 0;
}