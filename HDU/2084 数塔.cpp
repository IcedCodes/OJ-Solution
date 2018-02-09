#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int c;
	int n;
	int i, j;
	cin >> c;
	while (c--)
	{
		int **a;
		cin >> n;
		a = new int*[n];
		for (i = 0; i < n; i++)
		{
			a[i] = new int[i + 1];
		}
		for (i = 0; i < n; i++)
		for (j = 0; j < i + 1; j++)
		{
			cin >> a[i][j];
		}
		for (i = n - 2; i >= 0; i--)
		for (j = 0; j <= i; j++)
		{
			a[i][j] += max(a[i + 1][j],a[i + 1][j + 1]);
		}
		cout << a[0][0] << endl;
		for (i = 0; i < n; i++)delete[] a[i];
		delete[] a;
	}
	return 0;
}
