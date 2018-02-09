#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n, m, i, j, count;
	int a[1005],c[1005],dp[100005];
	while (true)
	{
		cin >> n >>m;
		if (m == 0 && n == 0)break;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (i = 0; i < n; i++)
		{
			cin >> c[i];
		}
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= m; j++)
			{
				if (dp[j] >= 0)dp[j] = c[i];
				else if (j < a[i])dp[j] = -1;
				else dp[j] = dp[j - a[i]] - 1;
			}
		}
		count = 0;
		for (i = 1; i <= m; i++)
		{
			if (dp[i] >= 0)count++;
		}
		cout << count << endl;
	}
}
