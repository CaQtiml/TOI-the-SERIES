#include "bits/stdc++.h"
using namespace std;
bool dp[3][256][256];
char arr[256];
int main()
{
	int TT=20;
	while(TT--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",arr+1);
		memset(dp,0,sizeof dp); //don't forget to clear  array before reuse
		for(int len=1;len<=n;len++)
		{
			for(int i=1,j=len ; j<=n ; i++,j++)
			{
				if(len==1)
				{
					dp[arr[i]-'0'][i][i]=1;
					continue;
				}
				for(int k=i;k<j;k++)
				{
					if(dp[0][i][k]&&dp[0][k+1][j])dp[2][i][j] = true;
					if(dp[0][i][k]&&dp[1][k+1][j])dp[1][i][j] = true;
					if(dp[0][i][k]&&dp[2][k+1][j])dp[0][i][j] = true;
					if(dp[1][i][k]&&dp[0][k+1][j])dp[2][i][j] = true;
					if(dp[1][i][k]&&dp[1][k+1][j])dp[1][i][j] = true;
					if(dp[1][i][k]&&dp[2][k+1][j])dp[1][i][j] = true;
					if(dp[2][i][k]&&dp[0][k+1][j])dp[1][i][j] = true;
					if(dp[2][i][k]&&dp[1][k+1][j])dp[2][i][j] = true;
					if(dp[2][i][k]&&dp[2][k+1][j])dp[1][i][j] = true;
				}
			}
		}
		if(dp[0][1][n]) printf("yes\n");
		else printf("no\n");
	}
}