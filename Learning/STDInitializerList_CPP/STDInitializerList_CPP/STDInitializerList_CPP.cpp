#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class IntArray
{
private:
	int m_length{};
	int *m_data{};
public:
	IntArray() = default;
	IntArray(int length):
		m_length{length},
		m_data{ new int[length] {} } 
	{}

	
	IntArray(initializer_list<int> list) :
		IntArray(static_cast<int>(list.size())) // call constructor to create m_length and m_data
	{
		// assigned data
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	IntArray(const IntArray&) = delete; // to avoid shallow copies
	IntArray& operator=(const IntArray& list) = delete;

	IntArray& operator=(initializer_list<int> list)
	{
		int length = list.size();
		if (m_length < length)
		{
			delete[] m_data;
			m_length = length;
			m_data = new int[length];
		}

		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		} 
		return *this;
	}

	~IntArray()
	{
		delete[] m_data;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }
};

int main()
{
	IntArray arr{ 1, 2, 3, 4, 5 }; // call IntArray(initializer_list<int> list) constructor
								   // because brace, CPP will create initializer_list
	for (auto count{ 0 }; count < arr.getLength(); ++count)
		cout << arr[count] << ' ';
	cout << "\n";
	arr = { 1, 3, 5, 7, 9, 11 };
	for (auto count{ 0 }; count < arr.getLength(); ++count)
		cout << arr[count] << ' ';
	return 0;
}

