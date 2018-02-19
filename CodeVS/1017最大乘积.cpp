#include <iostream>
#include <string>
/*
dp[1][0~n]�洢��λ���ӵ���������1234546�����Ϊ1,12,
123,....,123456��dp[i][j]��ʾ���� i,��j��*�ŵ������
dp[i][j]= max(dp[i][j],dp[x][j - 1]*calc(x+1,i))��x��j��i��
������㵽1234������*��ʱ��j = 2;f[x][1]��j~i��ʾ��1,12,123,
1234,�в�һ��*�ŵĽ����ȡ���Ĳ巨��ʣ�������˽��,��:12��
1��*���Ϊ2����˽��Ϊ2*34��calc����ȡ��34��ֵ�� 
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
	//�ַ���ת������ 
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
