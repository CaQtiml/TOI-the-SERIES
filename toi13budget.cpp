#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
const int INF = 1e9+29;
#define f first
#define s second
vector<ii> adj[10005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,st,ed,bd;
    cin >> N >> M >> st >> ed >> bd ;
    for(int i=1;i<=M;i++)
    {
        int u,v,w;
        cin >> u >> v >> w ;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    vector<int> dist(N+5,INF);
    dist[st]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.emplace(0,st);
    while(!pq.empty())
    {
        ii now = pq.top();
        pq.pop();
        int d1 = now.f;
        int n1 = now.s;
        if(d1>dist[n1]) continue;
        for(auto op : adj[n1])
        {
            int d2= op.s ;
            int n2= op.f ;
            if(dist[n2]>dist[n1]+d2 && dist[n1]+d2<=bd)
            {
                dist[n2]=dist[n1]+d2;
                pq.emplace(dist[n2],n2);
            }
        }
    }
    if(dist[ed]<=bd)
    {
        cout << ed << " " << dist[ed] << " 0" ;
        return 0;
    }
    vector<int> keep;
    for(int i=0;i<N;i++)
    {
        if(dist[i]!=INF)
        {
            keep.emplace_back(i);
        }
    }
    vector<int> dist2(N+5,INF);
    dist2[ed]=0;
    //priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.empty();
    pq.emplace(0,ed);
    while(!pq.empty())
    {
        ii now = pq.top();
        pq.pop();
        int d1 = now.f;
        int n1 = now.s;
        if(d1>dist2[n1]) continue;
        for(auto op : adj[n1])
        {
            int d2= op.s ;
            int n2= op.f ;
            if(dist2[n2]>dist2[n1]+d2)
            {
                dist2[n2]=dist2[n1]+d2;
                pq.emplace(dist2[n2],n2);
            }
        }
    }
    int ans=INF;
    int ans2=0;
    for(int i=0;i<N;i++)
    {
        if(dist[i]!=INF && dist2[i]<ans)
        {
            ans2=i;
            ans=dist2[i];
        }
    }
    cout << ans2 << " " << dist[ans2] << " " << ans ;
}