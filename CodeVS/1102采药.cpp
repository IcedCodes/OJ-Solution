#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a: b;
}
int main()
{
	int m, t, i, j;
	int *f, *cost, *value;
	cin >> t >> m;
	f = new int[t + 1];
	cost = new int[m];
	value = new int[m];
	for (i = 0; i <= t; i++)f[i] = 0;
	for (i = 0; i < m; i++)
	{
		cin >> cost[i] >> value[i];
	}
	for (i = 0; i <m; i++)
	for (j = t; j >= cost[i]; j--)
	{
		f[j] = max(f[j], f[j - cost[i]] + value[i]);
	}
	cout << f[t] << endl;
	delete[] f;
	delete[] cost;
	delete[] value;
	return 0;
}
