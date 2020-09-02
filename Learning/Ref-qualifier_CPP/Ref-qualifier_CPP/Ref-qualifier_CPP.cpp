#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Widget
{
public:
	using DataType = vector<double>;
	DataType& data() &  // for lvalue Widgets,
	{
		return values;	// return lvalue
	}

	DataType&& data() && // for rvalue Widgets,
	{
		return move(values); // return rvalue
	}

private:
	DataType values{ 1, 2, 3, 4 };
};

Widget makeWidget()
{
	Widget w;
	return w; // no address when out of func -> return rvalue
}

Widget* makeDymWidget()
{
	return new Widget; // has address -> return lvalue
}

int main()
{
	Widget w;
	auto vals1 = w.data(); // call lvalue
	auto vals2 = makeWidget().data(); // call rvalue
	auto val = Widget{}.data(); // call rvalue
	auto vals3 = makeDymWidget()->data(); // call lvalue
}