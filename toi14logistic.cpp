#include "bits/stdc++.h"
#define mkp make_pair
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> pi; //<distance,fuel>,<0/1,node>
vector<ii> e[105];
int dist[105][105][2]; //[node][fuel][0/1]
int p[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	int st,ed,f,m;
	cin >> st >> ed >> f >> m;
	for(int i=1;i<=m;i++){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		e[a].emplace_back(b,w);
		e[b].emplace_back(a,w);
	}
	priority_queue<pi,vector<pi>,greater<pi>> pq;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=f;j++)
			for(int k=0;k<=1;k++)
				dist[i][j][k]=1e8;
	dist[st][0][0]=0;
	pq.emplace(mkp(0,0),mkp(0,st));
	while(!pq.empty()){
		auto fr=pq.top();
		pq.pop();
		int d=fr.f.f;
		int fuel=fr.f.s;
		int cp=fr.s.f;
		int src=fr.s.s;
		if(d>dist[src][fuel][cp]) continue;
		if(fuel<f&&dist[src][fuel+1][cp]>dist[src][fuel][cp]+p[src]){
			dist[src][fuel+1][cp] = dist[src][fuel][cp]+p[src];
			pq.emplace(mkp(dist[src][fuel+1][cp],fuel+1),mkp(cp,src));
		}
		if(cp==0){
			int c=1;
			while(fuel+c<=f){
				if(dist[src][fuel+c][1]>dist[src][fuel][cp]){
					dist[src][fuel+c][1]=dist[src][fuel][cp];
					pq.emplace(mkp(dist[src][fuel+c][1],fuel+c),mkp(1,src));
				}
				c++;
			}
		}
		for(auto eiei : e[src]){
			int sr2=eiei.f,w2=eiei.s;
			if(w2<=fuel&&dist[sr2][fuel-w2][cp]>dist[src][fuel][cp]){
				dist[sr2][fuel-w2][cp]=dist[src][fuel][cp];
				pq.emplace(mkp(dist[sr2][fuel-w2][cp],fuel-w2),mkp(cp,sr2));
			}
		}
	}
	cout << dist[ed][f][1];
	exit(0);
}