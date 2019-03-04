#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n , k ;
	scanf("%d%d",&n,&k);
	int d1 , d2 ;
	scanf("%d%d",&d1,&d2);
	vector<int> adj;
	if(d1>d2) adj.emplace_back(d1);
	for(int i=3;i<=n;i++)
	{
		int d3;
		scanf("%d",&d3);
		if(d2>d1 && d2>d3) adj.emplace_back(d2);
		d1=d2;
		d2=d3;
	}
	if(d2>d1) adj.emplace_back(d2);
	sort(adj.begin(),adj.end());
	if(adj.size()==0)
	{
		printf("-1");
		return 0;
	}
	auto it = unique(adj.begin(),adj.end());
	int st = it-adj.begin();
	if(st>=k)
	{
		for(int i=st-1;i>=st-k;i--)
		{
			printf("%d\n",adj[i]);
		}
	}
	else
	{
		for(int i=0;i<st;i++)
		{
			printf("%d\n",adj[i]);
		}
	}
}