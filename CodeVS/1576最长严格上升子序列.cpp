#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int biggest(int *dp, int n)
{
	int big, i;
	big = dp[0];
	for (i = 1; i < n; i++)
	{
		if (dp[i] > big)big = dp[i];
	}
	return big;
}
int main()
{
	int n, i, j;
	cin >> n;
	int dp[5005];
	int a[5005];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		dp[i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[i])dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	cout << biggest(dp, n) << endl;
	return 0;
}
