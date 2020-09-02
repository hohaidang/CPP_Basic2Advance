#include <iostream>
using namespace std;

int gasStation(int gas[], int cost[], int n)
{
	int total = 0;
	int cur_gas = 0;
	int start_idx = 0;
	for (int i = 0; i < n; ++i)
	{
		cur_gas += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (cur_gas < 0)
		{
			++start_idx;
			cur_gas = 0;
		}
	}
	return (total < 0) ? -1 : start_idx;
}


int main()
{
	int gas[5]  { 1, 2, 3, 4, 5 };
	int cost[5]{ 3, 4, 5, 1, 2 };
	cout << gasStation(gas, cost, 5);
	return 0;
}