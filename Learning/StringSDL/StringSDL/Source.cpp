#include <iostream>
#include <cstring>

using namespace std;

class StringBad
{
private:
	char *str;
	int len;
	static int num_strings;
public:
	StringBad(const char *s);
	StringBad();
	~StringBad();

	friend std::ostream & operator<<(std::ostream &os, const StringBad &st);
};

StringBad::StringBad(const char *s)
{
	
}

int main()
{
	return 0;
}