#include <iostream>
#include <algorithm>
using namespace std;
struct Edge{
	int start;
	int end;
	int value;
};
bool cmp(Edge a, Edge b)
{
	return a.start < b.start;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int big(int *a, int n)
{
	int biggest = a[0];
	int i;
	for (i = 1; i < n; i++)
	{
		if (a[i] > biggest)biggest = a[i];
	}
	return biggest;
}
int main()
{
	int n, i, j;
	int dp[1005];
	Edge edge[1005];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> edge[i].start >> edge[i].end >> edge[i].value;
	}
	sort(edge, edge + n, cmp);
	for (i = 0; i < n; i++)dp[i] = edge[i].value;
	for (i = 0; i < n; i++)
	for (j = i + 1; j < n; j++)
	{
		if (edge[j].start >= edge[i].end)dp[j] = max(dp[j], dp[i] + edge[j].value);
	}
	cout << big(dp, n) << endl;
	return 0;
}
