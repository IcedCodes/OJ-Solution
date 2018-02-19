#include <iostream>
using namespace std;
int martix[25][25];
int sum;
int n, m;
//确定马防守的位置 
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
void DFS(int x, int y)
{
	if (x == n && y == m)
	{
		sum++;
		return;
	}
	if (x < 0 || y < 0 || x > n || y > m || martix[x][y] == 0)return;
	DFS(x + 1, y);
	DFS(x, y + 1);
}
int main()
{
	int x, y;
	for (int i = 0; i < 25; i++)
	for (int j = 0; j < 25; j++)
	{
		martix[i][j] = 1;
	}
	cin >> n >> m >> x >> y;
	locate(x, y);
	sum = 0;
	DFS(0, 0);
	cout << sum << endl;
	return 0;
}
