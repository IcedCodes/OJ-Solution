#include <iostream>
#include <cstring>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int dp[50][50][50][50] = {0};
int main()
{
	int m, n;
	int i, j, k, l, p, now;
	cin >> n >> m;
	int a[400];
	int b[5] = {0};
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < m; i++)
	{
		cin >> p;
		b[p]++;
	}
	dp[0][0][0][0] = a[0];
	for (i = 0; i <= b[1]; i++)
	for (j = 0; j <= b[2]; j++)
	for (k = 0; k <= b[3]; k++)
	for (l = 0; l <= b[4]; l++)
	{
		now = i + j*2 + k*3 + l*4;		//推算当前位置 
		if (i > 0)dp[i][j][k][l] = max(dp[i - 1][j][k][l] + a[now], dp[i][j][k][l]);
		if (j > 0)dp[i][j][k][l] = max(dp[i][j - 1][k][l] + a[now], dp[i][j][k][l]);
		if (k > 0)dp[i][j][k][l] = max(dp[i][j][k - 1][l] + a[now], dp[i][j][k][l]);
		if (l > 0)dp[i][j][k][l] = max(dp[i][j][k][l - 1] + a[now], dp[i][j][k][l]);
	}
	cout << dp[b[1]][b[2]][b[3]][b[4]] << endl;
	return 0;
}
