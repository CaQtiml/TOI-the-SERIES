#include "bits/stdc++.h"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,w,l;
	cin >> k >> w >> l ;
	int m = 2*k-1-w-l;
	char dp[2*k+1];
	for(int i=0;i<k-l;i++) dp[i]='L';
	for(int i=k-l;i<=m;i++) dp[i]='W';
	do
	{
		int ll = l;
		int ww = w;
		int c = m ;
		for(;c>=0;c--)
		{
			if(dp[c]=='L') ll++;
			else ww++;
			if(ll==k||ww==k) break;
		}
		for(int i=m;i>=c;i--) cout << dp[i] << " ";
		cout << "\n";
	}while(next_permutation(dp,dp+m+1));
}