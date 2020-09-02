#include <iostream>

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10};
	Item items[MAX]; // holds stack items
	int top; // index for top stack item
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item); // add item to stack
	bool pop(Item & item); // pop top into item
};

Stack::Stack()
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

int main()
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
	cout << "Please enter A to add a purchase order, \n"
		<< "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else 
			{
				st.pop(po);
				cout << "PO #" << po << "popped\n";
			}
			break;
		default:
			cout << "Input error";
		}
		cout << "Please enter A to add a purchase order, \n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}