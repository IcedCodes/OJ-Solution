#include <iostream>
#include <stack>
#define up 1
#define right 2
using namespace std;
int m, n;
int sum;
int martix[25][25];
class location{
public :
	int x;
	int y;
	int direction;
	location(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->direction = up;
	}
	void nextdirection()
	{
		if (direction == up)direction = right;
		else if (direction == right)direction = 0;
	}
	location* next()
	{
		int a, b;
		a = x;
		b = y;
		if (direction == up)a = x + 1;
		if (direction == right)b = y + 1;
		if (a >=0 && a<= n && b >= 0 && b<= m && martix[a][b] == 1)
		{
			location *lo = new location(a, b);
			return lo;
		}
		else return NULL;
	}
};
//确定马防守的位置 
void locate(int x, int y)
{
	martix[x][y] = 0;
	//if (x >= 2 && n - y >= 1)
	martix[x - 2][y + 1] = 0;
	//if (x >= 1 && n - y >= 2)
	martix[x - 1][y + 2] = 0;
	//if (m - x >= 2 && n - y >= 1)
	martix[x + 2][y + 1] = 0;
	//if (m - x >= 1 && n - y >= 2)
	martix[x + 1][y + 2] = 0;
	//if (m - x >= 2 && y >= 1)
	martix[x + 2][y - 1] = 0;
	//if (m - x >= 1 && y >= 2)
	martix[x + 1][y - 2] = 0;
	//if (x >= 1 && y >= 2)
	martix[x - 1][y - 2] = 0;
	//if (x >= 2 && y >= 1)
	martix[x - 2][y - 1] = 0;
}
int main()
{
	int count = 0;
	int x, y;
	for (int i = 0; i < 25; i++)
	for (int j = 0; j < 25; j++)
	{
		martix[i][j] = 1;
	}
	cin >> n >> m >> x >> y;
	locate(x, y);
	location start(0, 0);
	location end(m, n);
	start.x = 0;
	start.y = 0;
	stack <location> s;
	s.push(start);
	martix[0][0] = 0;
	while(!s.empty())
	{
		if (s.top().direction == 0)
		{
			martix[s.top().x][s.top().y] = 1;
			s.pop();
			if (s.empty())break;
			while (s.top().direction == 0 && !s.empty())
			{
				martix[s.top().x][s.top().y] = 1;
				s.pop();
			}
			if (s.empty())break;
			s.top().nextdirection();
		}
		else if (s.top().x == m && s.top().y == n)
		{
			count++;
			martix[s.top().x][s.top().y] = 1;
			s.pop();
			s.top().nextdirection();
		}
		else
		{
			location *lo = s.top().next();
			if (lo == NULL)
			{
				s.top().nextdirection();
			}
			else
			{
				s.push(*lo);
				martix[s.top().x][s.top().y] = 0;
			}
		}
	}
	cout << count << endl;
	return 0;
}
