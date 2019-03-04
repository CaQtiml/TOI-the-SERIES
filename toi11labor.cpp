#include "bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ll> V;
	ll m,n;
	cin >> m >> n ;
	while(m--)
	{
		ll t;
		cin >> t ;
		V.emplace_back(t);
	}
	ll st=1 , ed=2e12;
	while(st<ed)
	{
		ll m = (st+ed)/2;
		ll sum=0;
		for(auto x : V)
		{
			sum+=(m/x);
		}
		if(sum>=n) ed=m ;
		else st=m+1;
	}
	cout << ed ;
}