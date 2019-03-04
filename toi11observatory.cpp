#include "bits/stdc++.h"
using namespace std;
int arr[2005][2005];
int dp[2005][2005];
int dpl[2005][2005];
int dpr[2005][2005];
int main()
{
	int n , m , k ;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&arr[i][j]);
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dpl[i][j]=dpl[i-1][j-1]+dp[i][j]-dp[i-1][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dpr[i][j]=dpr[i-1][j+1]+dp[i][m]-dp[i-1][m]-dp[i][j-1]+dp[i-1][j-1];
		}
	}
	int mx=-1e11;
	for(int i=k;i<=n;i++)
	{
		for(int j=k;j<=m;j++)
		{
			int now = dpl[i][j]-dp[i][j-k]+dp[i-k][j-k]-dpl[i-k][j-k];
			mx=max(mx,now);
		}
	}
	for(int i=k;i<=n;i++)
	{
		for(int j=1;j<=m-k+1;j++)
		{
			int now=dpr[i][j]-dpr[i-k][j+k]-(dp[i][m]-dp[i-k][m]-dp[i][j+k-1]+dp[i-k][j+k-1]);
			mx=max(mx,now);
		}
	}
	printf("%d",mx);
}