#include <iostream>
#include <string>
/*
dp[1][0~n]存储逐位增加的数，例如1234546逐个存为1,12,
123,....,123456。dp[i][j]表示长度 i,用j个*号的最大结果
dp[i][j]= max(dp[i][j],dp[x][j - 1]*calc(x+1,i))，x从j到i。
例如计算到1234用两个*号时，j = 2;f[x][1]从j~i表示从1,12,123,
1234,中插一个*号的结果中取最大的插法与剩余的数相乘结果,例:12插
1个*最大为2，相乘结果为2*34（calc函数取得34的值） 
*/
using namespace std;
int a[50];
long long dp[50][10] = {0};
int max(long long a, long long b)
{
	return a > b ? a : b;
}
long long calc(int x, int y)
{
	int i;
	long long ans;
	ans = 0;
	for (i = x; i <= y; i++)
	{
		ans = ans*10 + a[i - 1];
	}
	return ans;
}
int main()
{
	int n, k, i, j, x;
	cin >> n >> k;
	string s;
	cin >> s;
	//字符串转存数组 
	for (i = 0; i < n; i++)
	{
		a[i] = s[i] - '0';
	}
	dp[1][0] = a[0];
	for (i = 2; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0]*10 + a[i - 1];
	}
	for (i = 2; i <= n; i++)
	for (j = 1; j <= k; j++)
	for (x = j; x <= i; x++)
	{
		dp[i][j] = max(dp[i][j], dp[x][j - 1]*calc(x + 1, i));
	}
	cout << dp[n][k] << endl;
	return 0;
}
