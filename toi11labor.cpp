#include "bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ll> V;
	ll M,n,ans=0;
	cin >> M >> n ;
	while(M--)
	{
		ll t;
		cin >> t ;
		V.emplace_back(t);
	}
	ll st=1 , ed=2e12;
	while(st<=ed)
	{
		ll mid = (st+ed)/2;
		ll sum=0;
		for(auto x : V)
		{
			sum+=(mid/x);
		}
		if(sum>=n) {ans=mid; ed=mid-1;} 
		else st=mid+1;
	}
	cout << ans ;
}
