#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
#define mkp make_pair
int p[2005][2005];
int dist[2005][2005];
bool visit[2005][2005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M,ans=0,bag=0;
	cin >> N >> M;
	queue<ii> q;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			char h;
			cin >> h;
			if(h=='E') p[i][j]=1;
			else if(h=='A') p[i][j]=2;
			else if(h=='W') p[i][j]=-1;
			else if(h=='X')
			{
				q.emplace(i,j);
				dist[i][j]=1;
			}
		}
	}
	int di[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	//cout << q.empty() << "\n";
	while(!q.empty())
	{
		//cout << "PASS\n";
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(visit[x][y]) continue;
		visit[x][y]=1;
		if(p[x][y]==2)
		{
			bag+=1;
			ans+=(dist[x][y]-1)*2;
		}
		for(int i=0;i<4;i++)
		{
			int xx = x+di[i][0];
			int yy = y+di[i][1];
			if(xx<1||xx>N||yy<1||yy>M) continue;
			if(!visit[xx][yy] && p[xx][yy]!=-1)
			{
				if(dist[xx][yy]==0) dist[xx][yy]=dist[x][y]+1;
				else dist[xx][yy]=min(dist[xx][yy],dist[x][y]+1);
				q.emplace(xx,yy);
			}
		}
	}
	cout << bag << " " << ans ;
}