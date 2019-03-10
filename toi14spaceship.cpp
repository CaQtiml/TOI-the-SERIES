#include "bits/stdc++.h"
using namespace std;
bool dp[1010][1010];
int a[3];
int N,M;
void solve(int i,int j)
{
	vector<int> ans;
	while(dp[i][j])
	{
		//cout << i << " " << j << "\n";
		//cout << "PASS1\n";
		int cnt=0;
		int tj=j;
		//cout << dp[i][tj] << " " << tj << " " << M << "\n";
		while(dp[i][tj]&&tj<=M)
		{
			//cout << "PASS\n";
			//cout << i << " " << tj << "\n";
			dp[i][tj]=0;
			cnt++;
			tj++;
		}
		//cout << cnt << "\n";
		ans.emplace_back(cnt);
		//cout << cnt << "\n";
		if(j>1 && dp[i+1][j-1]) { j--; }
		else if(dp[i+1][j]) {}
		else if(j<M && dp[i+1][j+1]) { j++; }
		i++;
	}
	if(ans[0]==ans[1]) a[0]++;
	else if(ans[0]+2==ans[1] && ans[0]==ans[ans.size()-1]) a[1]++;
	else a[2]++;
}
void bedug()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cout << dp[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int N,M;	
	cin >> M >> N ;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			char tt;
			cin >> tt;
			if(tt=='0') dp[i][j]=0;
			else dp[i][j]=1;
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(dp[i][j]) {solve(i,j);}
		}
	}
	for(int i=0;i<=2;i++)
		cout << a[i] << " ";
}