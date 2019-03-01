#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
const int INF = 1e9+29;
#define CLR(a) memset(a,0,sizeof(a))
vector<int> adj[500005];
bool visit[500005];
int dp[500005];
int maxfail=0;
int minnode=INF;
int N , M ;
int dfs(int u)
{
	if(u == M) return -1;
	if(visit[u]) return 0;
	visit[u]=1;
	bool st = false;
	int sum=1;
	for(auto v : adj[u])
	{
		int X = dfs(v);
		if(X==-1) st = true;
		else sum+=X;
	}
	dp[u]=sum-1;
	if(st) return -1;
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M ;
	for(int i=1;i<=N;i++)
	{
		int u , v ;
		cin >> u >> v ;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for(auto uu : adj[M])
	{
		dfs(uu);
	}
	dp[M]=-INF;
	for(int i=1;i<=N;i++)
	{
		if(dp[i]>maxfail) 
		{
			//cout << dp[1] << "\n";
			maxfail=dp[i];
			minnode=i;
		}
		else if(dp[i]==maxfail)
		{
			minnode=min(i,minnode);
		}
	}
	cout << minnode << "\n" << maxfail ;
	//cout << dfs(1,3);
}