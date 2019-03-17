#include "bits/stdc++.h"
using namespace std;
int arr[1010][1010];
int dp[1010][1010];
int way[1010][1010];
int cway=0;
int cnow=-1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(i==1)
			{
				cin >> arr[i][j];
				dp[i][j]=arr[i][j];
				way[1][j]=1;
			}
			else
			{
				if(i%2==0)
				{
					if(j==M)
					{
						cin >> arr[i][j];
						dp[i][j]+=(dp[i-1][j]+arr[i][j]);
						way[i][j]=way[i-1][j];
					}
					else
					{
						cin >> arr[i][j];
						for(int k=0;k<=1;k++)
						{
							if(dp[i-1][j+k]+arr[i][j]>dp[i][j])
							{
								if(k==0)
								{
									dp[i][j]=dp[i-1][j+k]+arr[i][j];
									way[i][j]+=way[i-1][j+k];
								}
								if(k==1)
								{
									dp[i][j]=dp[i-1][j+k]+arr[i][j];
									way[i][j]=way[i-1][j+k];
								}
							}
							else if(dp[i-1][j+k]+arr[i][j]==dp[i][j])
							{
								way[i][j]+=way[i-1][j+k];
							}
						}
					}
				}
				if(i%2==1)
				{
					if(j==1)
					{
						cin >> arr[i][j];
						dp[i][j]+=(dp[i-1][j]+arr[i][j]);
						way[i][j]=way[i-1][j];
					}
					else
					{
						cin >> arr[i][j];
						for(int k=-1;k<=0;k++)
						{
							if(dp[i-1][j+k]+arr[i][j]>dp[i][j])
							{
								if(k==-1)
								{
									dp[i][j]=dp[i-1][j+k]+arr[i][j];
									way[i][j]+=way[i-1][j+k];
								}
								if(k==0)
								{
									dp[i][j]=dp[i-1][j+k]+arr[i][j];
									way[i][j]=way[i-1][j+k];
								}
							}
							else if(dp[i-1][j+k]+arr[i][j]==dp[i][j])
							{
								way[i][j]+=way[i-1][j+k];
							}
						}
					}
				}
			}
		}
	}
	
	int mx=-1;
	for(int i=1;i<=M;i++)
	{
		mx=max(mx,dp[N][i]);
	}
	int cnt=0;
	for(int i=1;i<=M;i++)
	{
		if(dp[N][i]==mx) cnt+=way[N][i];
	}
	cout << mx << " " << cnt;
}




