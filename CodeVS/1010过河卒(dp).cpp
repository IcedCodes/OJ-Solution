#include <iostream>
using namespace std;
/*
求解思路就是到某点路径数等于到齐相邻两点路径数之和，边缘特殊处理 
*/
int dp[20][20];
int martix[20][20];
//确定马防守位置 
void locate(int x, int y)
{
	martix[x][y] = 0;
	martix[x - 2][y + 1] = 0;
	martix[x - 1][y + 2] = 0;
	martix[x + 2][y + 1] = 0;
	martix[x + 1][y + 2] = 0;
	martix[x + 2][y - 1] = 0;
	martix[x + 1][y - 2] = 0;
	martix[x - 1][y - 2] = 0;
	martix[x - 2][y - 1] = 0;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	int m, n, i, j, x, y;
	cin >> n >> m >> x >> y;
	for (i = 0; i < 20; i++)
	for (j = 0; j < 20; j++)
	{
		dp[i][j] = 0;
		martix[i][j] = 1;
	}
	locate(x, y);
	if (martix[0][1] != 0)dp[0][1] = 1;
	if (martix[1][0] != 0)dp[1][0] = 1;
	for (i = 0; i <= n; i++)
	for (j = 0; j <= m; j++)
	{
		if (martix[i][j] != 0)
		{
			if (i >= 1 && j >= 1)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
			else if (j == 0 && i != 1 && martix[i - 1][j] != 0)dp[i][j] = dp[i - 1][j];
			else if (i == 0 && j != 1 && martix[i][j - 1] != 0)dp[i][j] = dp[i][j - 1];
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
