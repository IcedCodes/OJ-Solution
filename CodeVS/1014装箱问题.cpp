#include <iostream>
using namespace std;
int main()
{
	int v, n;
	int *f, *a;
	cin >> v >> n;
	f = new int[v + 1];
	a = new int[n];
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i <= v; i++)f[i] = 0;
	for (i = 0; i <= n; i++)
	for (j = v; j >= a[i]; j--)
	{
		if (f[j] < (f[j - a[i]] + a[i]))f[j] = f[j - a[i]] + a[i];
	}
	cout << v - f[v] << endl;
	delete[] f;
	delete[] a;
	return 0;
}
