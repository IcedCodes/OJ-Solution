#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a: b;
}
int main()
{
	int n, m, i ,j;
	int *f, *weight, *value;
	cin >> n >> m;
	f = new int[m + 1];
	weight = new int[n];
	value = new int[n];
	for (i = 0; i <= m; i++)f[i] = 0;
	for (i = 0; i < n; i++)
	{
		cin >> weight[i] >> value[i];
	}
	for (i = 0; i < n; i++)
	for (j = m; j >= weight[i]; j--)
	{
		f[j] = max(f[j], f[j - weight[i]] + value[i]);
	}
	cout << f[m] << endl;
	delete[] f;
	delete[] weight;
	delete[] value;
	return 0;
}
