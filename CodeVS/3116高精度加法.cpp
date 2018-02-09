#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b, c, d;
	int i, j, lena, lenb, len;
	cin >> a >> b;
	lena = a.size();
	lenb = b.size();
	len = lena > lenb ? (lena - lenb) : (lenb - lena);
	for (i = 0; i <= len; i++)	//补0补齐,多补一位 
	{
		c += '0';
	}
	if (lena == lenb)
	{
		c = '0';
		c += a;
		a = c;
		c = '0';
		c += b;
		b = c;
	}
	else if (lena >lenb)
	{
		c += b;
		b = c;
		c = '0';
		c += a;
		a = c;
	}
	else 
	{
		c += a;
		a = c;
		c = '0';
		c += b;
		b = c;
	}
	len = a.size();
	for (i = len - 1; i >= 0; i--)
	{
		if (a[i] > '9')		//进位 
		{
			a[i] -= 10;
			a[i - 1]++;
		}
		a[i] += b[i] - '0';
		if (a[i] > '9')
		{
			a[i] -= 10;
			a[i - 1]++;
		}
	}
	i = 0;
	if (a[0] == '0')	//除掉首位0 
	{
		i++;
	}
	for (; i < len; i++)
	{
		d += a[i];
	}
	cout << d << endl;
}
