#include <iostream>
#include <algorithm>
using namespace std;
int p[100001],m,n;
struct edge{
	int from,to;
	long long l;
}a[100001];
void inti(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		p[i]=i;
	}
}
int find(int x)
{
	if(x==p[x])return p[x];
	else return find(p[x]);
}
bool cmp(edge a,edge b)
{
	return a.l<b.l;
}
long long kruskal(int n,int m)
{
	int i;
	long long res=0,c=0;
	sort(a,a+m,cmp);
	for(i=0;i<m;i++)
	{
		if(find(a[i].from)!=find(a[i].to))
		{
			p[find(a[i].from)]=find(a[i].to);
			res+=a[i].l;
			c++;
		}
		if(c==n-1)break;
	}
	return res;
}
int main()
{
	int i,ans;
	cin>>n>>m;
	inti(m);
	for(i=0;i<m;i++)
	{
		cin>>a[i].from>>a[i].to>>a[i].l;
	}
	ans=kruskal(n,m);
	cout<<ans<<endl;
	return 0;
}
