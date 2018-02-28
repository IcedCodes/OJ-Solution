#include <iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int i, j, n, a, b;
	int height[25];
	int dp1[25] = {0};
	int dp2[25] = {0};
	i = 0;
	n = 0;
	while (cin >> height[i])
	{
		dp1[i] = dp2[i] = 1;
		i++;
	}
	n = i;
	a = b = 1;
	for (i = 0; i < n; i++)
	for (j = i + 1; j < n; j++)
	{
		if (height[i] >= height[j])
		{
			dp1[j] = max(dp1[j], dp1[i] + 1);
			a = max(a, dp1[j]);
		}
		else
		{
			dp2[j] = max(dp2[j], dp2[i] + 1);
			b = max(b, dp2[j]);
		}
	}
	cout << a << endl << b << endl;
	return 0;
}
