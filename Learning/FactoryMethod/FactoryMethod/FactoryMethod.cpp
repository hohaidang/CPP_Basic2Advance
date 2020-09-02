#include <iostream>
#include <vector>
using namespace std;

class Stooge
{
public:
	// Factory Method
	static Stooge *make_stooge(int choice);
	virtual void slap_strick() = 0;
};

int main()
{
	vector<Stooge*> roles;
	int choice;
	while (true)
	{
		cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
		cin >> choice;
		if (choice == 0)
			break;
		roles.push_back(Stooge::make_stooge(choice));
	}

	for (const auto &role : roles)
	{
		role->slap_strick();
	}
	for (int i{ 0 }; i < roles.size(); i++)
	{
		delete roles[i];
	}
	return 0;
}

class Larry : public Stooge
{
public:
	void slap_strick() override
	{
		cout << "Larry: slap head\n";
	}
};

class Moe : public Stooge
{
public:
	void slap_strick() override
	{
		cout << "Moe: slap head\n";
	}
};

class Curly : public Stooge
{
public:
	void slap_strick() override
	{
		cout << "Curly: slap head\n";
	}
};

// factory method will return rvalue
Stooge *Stooge::make_stooge(int choice)
{
	if (choice == 1)
		return new Larry;
	else if (choice == 2)
		return new Moe;
	else
		return new Curly;
}