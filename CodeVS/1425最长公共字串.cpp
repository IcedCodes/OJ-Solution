/*
找到前两个字符串所有公共字串，再和剩下的一一匹配
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string all[1000];
int counts;
bool cmp(string a, string b)
{
	return a.size() > b.size();
}
bool suit(string a, string &b)
{
	int i, lengtha, j, lengthb;
	lengtha = a.size();
	lengthb = b.size();
	if (lengtha >= lengthb)
	{
		for (i = 0; i < lengtha; i++)
		{
			if (a[i] == b[0])
			{
				if (b.size() == 1)return true;
				else
				{
					bool flag = true;
					for (j = 1; j < lengthb; j++)
					{
						if (a[i + j] != b[j])flag = false;
					}
					if (flag == true)return true;
				}
			}
		}
	}
	else
	{
		for (i = 0; i < lengthb; i++)
		{
			if (b[i] == a[0])
			{
				if (a.size() == 1)
				{
					b = a;
					return true;
				}
				else
				{
					bool flag = true;
					for (j = 1; j < lengtha; j++)
					{
						if (b[i + j] != a[j])flag = false;
					}
					if (flag == true)
					{
						b = a;
						return true;
					}
				}
			}
		}
	}
}
int main()
{
	int n, i, j, pos, sum;
	string s[25];
	string a, b, c;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	a = s[0];
	b = s[1];
	counts = 0;
	pos = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				c = a[i];
				while (a[i + pos] == b[j + pos] && (i + pos) < a.size() && (j + pos) < b.size())
				{
					c += a[i + pos];
					pos++;
				}
				all[counts] = c;
				counts++;
				i += pos;
				j += pos;
				pos = 1;
			}
		}
	}
	sort(all, all + counts, cmp);
	if (n <= 2)cout << all[0] << endl;
	else
	{
		sum = 0;
		for (j = 0; j < counts; j++)
		{
			bool flag = true;
			if (suit(s[2], all[j]))
			{
				for (i = 3; i < n; i++)
				{
					if (suit(s[i], all[j]))sum++;
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == true)break;
				sum = 0;
			}
		}
		if (sum == (n - 3))cout << all[j] << endl;
	}
	return 0;
}
