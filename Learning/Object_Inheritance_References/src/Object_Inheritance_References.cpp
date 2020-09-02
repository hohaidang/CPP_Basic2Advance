//============================================================================
// Name        : Object_Inheritance_References.cpp
// Author      : Dang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int LIMIT = 5;

void file_it(ostream &os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed); // save initial formatting state
	os.precision(0);
	os << "Focal length of objective " << fo << "mm\n";
}

int main() {
	ofstream fout;
	const char *fn = "ep-data.txt";
	fout.open(fn);
    if (!fout.is_open())
    {
    	cout << "Cannot open" << fn << "Bye.\n";
    	exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your telescope objective in mm: ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal lenghts, in mm, of" << LIMIT << " eyepieces:\n";
    for(int i = 0; i < LIMIT; ++i)
    {
    	cout << "Eyepiece #" << i + i << ": ";
    	cin >> eps[i];
    }

	return 0;
}
