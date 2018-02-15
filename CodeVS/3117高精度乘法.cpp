#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string a, b, c;
	int i, j, lena, lenb;
	int *d1, *d2, *ans;
	cin >> a >> b;
	lena = a.size();
	lenb = b.size();
	d1 = new int[lena];
	d2 = new int[lenb];
	ans = new int[1005];
	for (i = 0; i < lena; i++)
    {
        d1[i] = a[lena - 1 - i] - '0';
    }
    for (i = 0; i < lenb; i++)
    {
        d2[i] = b[lenb - 1 - i] - '0';
    }
    for (i = 0; i < 1005; i++)ans[i] = 0;
    for (i = 0; i < lena; i++)
    for (j = 0; j < lenb; j++)
    {
        ans[i + j] += d1[i] * d2[j];
    }
    for (i = 0; i < 1005; i++)
    {
        if (ans[i] >= 10)
        {
            ans[i + 1] += ans[i]/10;
            ans[i] %= 10;
        }
    }
    stack <int> ls;
    for (i = 0; i < 1005; i++)
    {
        ls.push(ans[i]);
    }
    while (!ls.empty())
    {
        if (ls.top() == 0)ls.pop();
        else break;
    }
    while (!ls.empty())
    {
        cout << ls.top();
        ls.pop();
    }
    cout <<endl;
    delete[] d1;
    delete[] d2;
    delete[] ans;
    return 0;
}
