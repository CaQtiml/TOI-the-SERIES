#include "bits/stdc++.h"
#define vi vector<int>
using namespace std;
int N,K,T;
//int lv[20000];
vector<vi> lv;
int have[200000];
int visit[200000];
int ans=-1;
vector<vi> e ;
void make(int a)
{
	if(have[a]) return;
	for(auto m : e[a])
	{
		if(!have[m])
		{
			if(visit[m]) {printf("%d",ans); exit(0);}
			visit[m]=1;
			make(m);
			visit[m]=0;
		}
	}
	have[a]=1;
	T--;
}
int main()
{
	scanf("%d%d%d",&N,&K,&T);
	e.assign(N+1000,vi());
	lv.assign(N+1000,vi());
	for(int i=1;i<=N;i++)
	{
		int tlv;
		scanf("%d",&tlv);
		lv[tlv].emplace_back(i);
		int rob;
		scanf("%d",&rob);
		for(int j=1;j<=rob;j++)
		{
			int u;
			scanf("%d",&u);
			e[i].emplace_back(u);
		}
	}
	for(int i=1;i<=K;i++)
	{
		for(auto j : lv[i])
		{
			visit[j]=1; //use to check cycle
			make(j);
			visit[j]=0;
		}
		if(T<0) {printf("%d",ans); exit(0);}
		else ans=i;
	}
	cout << ans ;
}
