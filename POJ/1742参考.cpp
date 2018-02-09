#include <iostream>
#include <cstring>
using namespace std;

const int maxn=100;
const int maxm=100001;

int main()
{
    int n,m;
    int a[maxn],c[maxn],dp[maxm];
    while(cin>>n>>m){
        if(!n) break;
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
		//a[i]��ֵ ��c[i]����
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++){    ///j++Ϊ��ѭ��
            if(dp[j]>=0) dp[j]=c[i];     ///�ж������е�dp[j]��ʵ��dp[i-1][j]
            else if(j<a[i]) dp[j]=-1;
            else dp[j]=dp[j-a[i]]-1;
        }
        int num=0;
        for(int i=m;i>=1;i--) if(dp[i]>=0) num++;
        cout<<num<<endl;
    }
    return 0;
}
