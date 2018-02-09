#include <iostream>
#include <string>
using namespace std;
void borrow(string &a, int i)
{
	a[i - 1]--;
	if (a[i - 1] < '0')borrow(a, i - 1);
	a[i] += 10;
}
int main()
{
	string a, b, c, d;
	cin >> a >> b;
	int lena, lenb, i, len;
	lena = a.size();
	lenb = b.size();
	len = lena > lenb ? (lena - lenb) : (lenb - lena);
	//较小者补零
	for (i = 0; i < len; i++)
	{
		c += '0';
	}
	//连接上较小者
	c += lena < lenb ? a : b;
	if (lena < lenb)a = c;
	else b = c;
	len = a.size();
	if (lena > lenb)	//a大于b
	{
		for (i = len - 1; i >= 0; i--)
		{
			if (a[i] < b[i])borrow(a, i);	//借位
			a[i] = a[i] - b[i] + '0';
		}
		c = a;
	}
	else if (lena == lenb && a[0] >= b[0])	//a大于等于b
	{
		for (i = len - 1; i >= 0; i--)
		{
			if (a[i] < b[i])borrow(a, i);	//借位
			a[i] = a[i] - b[i] + '0';
		}
		c = a;
	}
	else
	{
		for (i = len - 1; i >= 0; i--)
		{
			if (b[i] < a[i])borrow(b, i);	//借位
			b[i] = b[i] - a[i] + '0';
		}
		c = '-';
		c += b;
	}
	//删除多余的0
	len = c.size();
	i = 0;
	if (c[0] == '-')
	{
		d += '-';
		i++;
	}
	for (; i < len; i++)
	{
		if (c[i] != '0')break;
	}
	for (; i < len; i++)
	{
		d += c[i];
	}
	cout << d << endl;
}

