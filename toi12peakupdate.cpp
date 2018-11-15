#include "bits/stdc++.h"
using namespace std;
#define ll long long
set<int> s;
//vector<int> s;
int h[6000000];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		//int temp;
		scanf("%d",&h[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1 && h[i]>h[i+1]) s.emplace(h[i]);
		if(i==n && h[i]>h[i-1]) s.emplace(h[i]);
		if(h[i]>h[i-1] && h[i]>h[i+1]) s.emplace(h[i]);
	}
	if(s.empty()) printf("-1");
	else 
	{
		bool wtf=true;
		if(s.size()<k) wtf=false;
		if(!wtf)
		{
			for(auto e : s) printf("%d\n",e);
		}
		else
		{
			vector<int> s2;
			for(auto x : s) s2.emplace_back(x);
			sort(s2.begin(),s2.end(),greater<int>());
			for(int i=0;i<k;i++)
			{
				printf("%d\n",s2[i]);
			}
		}
	}
}
// 90/100 PTS
// TLE