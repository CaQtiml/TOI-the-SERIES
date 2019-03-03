//maxst and select min
#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define mkp make_pair
#define pb push_back
#define f first
#define s second
const int INF = 1e9+29;
class Unionfind
{
private :
    vi p;
public :
    Unionfind(int n)
    {
        p.assign(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }
    int fs(int i)
    {
        return (p[i]==i) ? i : (p[i]=fs(p[i])) ;
    }
    bool iss(int i , int j)
    {
        return fs(i)==fs(j);
    }
    void us(int i,int j)
    {
        p[fs(i)] = fs(j);
    }
};
vii adj[3000];
int ans[3000];
bool visit[3000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<pair<int,ii>> temp;
    Unionfind uf(n+10);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        temp.emplace_back(w,mkp(u,v));
    }
    sort(temp.begin(),temp.end(),greater<pair<int,ii>>());
    for(int i=0;i<temp.size();i++)
    {
        int c = temp[i].f;
        int a = temp[i].s.f;
        int b = temp[i].s.s;
        if(!uf.iss(a,b))
        {
            adj[a].emplace_back(b,c);
            adj[b].emplace_back(a,c);
            uf.us(a,b);
        }
    }
    int st , ed , pn ;
    scanf("%d%d%d",&st,&ed,&pn);
    ans[st]=INF;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.emplace(0,st);
    while(!pq.empty())
    {
        int d1=pq.top().f;
        int n1=pq.top().s;
        pq.pop();
        if(n1==ed) break;
        if(visit[n1]) continue;
        visit[n1]=true;
        for(auto v : adj[n1])
        {
            int n2= v.f;
            int d2= v.s;
            ans[n2]=min(ans[n1],d2);
            pq.emplace(d2,n2);
        }
    }
    int pp=ans[ed]-1; //delete guide
    if(pn%pp>0) cout << (pn/pp)+1;
    else cout << pn/pp;
}