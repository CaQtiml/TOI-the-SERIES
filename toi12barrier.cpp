#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int INF = 1e9+29;
ll dp[6000010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,W;
	cin >> N >> W;
	deque<int> q;
	ll a1=0 , a2=0;
	for(int i=1; i< N+W ;i++)
	{
		if(i<=N) cin >> dp[i] ;
		dp[i]+=dp[i-1];
		while(!q.empty() && i-W==q.front()) q.pop_front();
		while(!q.empty() && dp[q.back()]<dp[i]) q.pop_back();
		q.push_back(i);
		if(i>=W)
		{
			ll num = dp[q.front()]-dp[i-W];
			ll len = q.front()-(i-W);
			if(num > a1)
			{
				a1=num;
				a2=len;
			}
			else if(num==a1 && len<a2) a2=len; 
		}
	}
	cout << a1 << "\n" << a2;
}