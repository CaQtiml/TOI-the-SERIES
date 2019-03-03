#include "bits/stdc++.h"
using namespace std;
char arr1[1005] , arr2[1005];
bool dp[1005][1005]; 
int main()
{
	scanf("%s%s",arr1+1,arr2+1);
	int len1 = strlen(arr1+1);
	int len2 = strlen(arr2+1);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char key[2005];
		scanf("%s",key+1);
		dp[0][0]=true;
		for(int i=1;i<=len1;i++)
		{
			dp[i][0] = dp[i-1][0] && (arr1[i]==key[i]);
		}
		for(int i=1;i<=len2;i++)
		{
			dp[0][i] = dp[0][i-1] && (arr2[i]==key[i]);
		}
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				dp[i][j] = ( ( dp[i-1][j] && ( arr1[i]==key[i+j] ) ) || ( dp[i][j-1] ) && ( arr2[j]==key[i+j] ) );
			}
		}
		if(dp[len1][len2]) printf("Yes\n");
		else printf("No\n");
	}
}