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
	//��С�߲���
	for (i = 0; i < len; i++)
	{
		c += '0';
	}
	//�����Ͻ�С��
	c += lena < lenb ? a : b;
	if (lena < lenb)a = c;
	else b = c;
	len = a.size();
	if (lena > lenb)	//a����b
	{
		for (i = len - 1; i >= 0; i--)
		{
			if (a[i] < b[i])borrow(a, i);	//��λ
			a[i] = a[i] - b[i] + '0';
		}
		c = a;
	}
	else if (lena == lenb && a[0] >= b[0])	//a���ڵ���b
	{
		for (i = len - 1; i >= 0; i--)
		{
			if (a[i] < b[i])borrow(a, i);	//��λ
			a[i] = a[i] - b[i] + '0';
		}
		c = a;
	}
	else
	{
		for (i = len - 1; i >= 0; i--)
		{
			if (b[i] < a[i])borrow(b, i);	//��λ
			b[i] = b[i] - a[i] + '0';
		}
		c = '-';
		c += b;
	}
	//ɾ�������0
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

