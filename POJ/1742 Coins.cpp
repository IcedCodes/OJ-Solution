#include <iostream>
#include <cstring>
using namespace std;
/*
n为币值总数，m为最大值,a[i]币值，c[i]数目，
dp[i][j]表示用到币值a[i]的硬币时凑成币值j时币值a[i]的硬币剩余硬币数量 
*/
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
		memset(dp, -1, sizeof(dp));		//全部初始化为-1
		dp[0] = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= m; j++)
			{
				if (dp[j] >= 0)dp[j] = c[i];	//dp[j]即dp[i - 1][j],先前能凑得就不用消耗 
				else if (j < a[i])dp[j] = -1;	//先前币值的硬币未能凑得且j小于当前a[i]币值则设-1表无法凑得 
				else dp[j] = dp[j - a[i]] - 1;	//dp[j-a[i]]再用一个a[i]凑得币值j 
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
