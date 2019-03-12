#include "bits/stdc++.h"
using namespace std;
int dp[1005][1005];
char arr[1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n ;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	//Matrix Chain Multiplication Concept
	for(int len=2;len<=n;len++)
	{
		for(int i=1,j=len ; j<=n ; i++,j++)
		{
			for(int k=i;k<j;k++)
			{
				if(arr[i]==arr[j])
				{
					dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
					break;
				}
				else
				{
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
		}
	}
	cout << dp[1][n];
}