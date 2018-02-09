#include <iostream>
#include <algorithm>
using namespace std;
int p[10005];
struct edge
{
        int from,to,l;
}a[10005];
bool cmp(edge a,edge b)
{
        return a.l<b.l;
}
int find(int x)
{
        return x==p[x]?p[x]:find(p[x]);
}
void kruskal(int n,int k)
{
        sort(a,a+k,cmp);
        int i;
        long ans;
        for(i=n;i<k;i++)
        {
                if(find(a[i].from)!=find(a[i].to))
                {
                        p[find(a[i].from)]=find(a[i].to);
                        ans+=a[i].l;
                }
        }
        cout<<ans<<endl;
}
int main()
{
        int n,i,j,k=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        a[k].from=i;
                        a[k].to=j;
                        cin>>a[k].l;
                        p[k]=k;
                        k++;
                }
        }
        kruskal(n,k);
        return 0;
}
