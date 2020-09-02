#include "tabtenn0.h"
#include <iostream>

using namespace std;
int main()
{
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": has a table";
	else
		cout << ": hasn't a table.\n";
		
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();
	cout << "; Rating: " << rplayer1.Rating() << endl;
	RatedPlayer rplayer2(1212, player1);
	rplayer2.Name();
	cout << "; Rating: " << rplayer2.Rating() << endl;
	return 0;
}