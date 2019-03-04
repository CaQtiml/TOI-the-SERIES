#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;
char w[2005][2005];
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf(" %c",&w[i][j]);
    queue<ii> q;
    int di[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
    int ans=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(w[i][j]=='1')
            {
                ans++;
                q.push(mp(i,j));
                while(!q.empty())
                {
                    ii f=q.front();
                    q.pop();
                    int x=f.first,y=f.second;
                    if(w[x][y]=='0') continue;
                    w[x][y]='0';
                    for(int k=0;k<8;k++)
                    {
                        int xx=x+di[k][0],yy=y+di[k][1];
                        if(xx<1||xx>m||yy<1||yy>n) continue;
                        if(w[xx][yy]=='1') q.push(mp(xx,yy));
                    }
                }
            }
            printf("%d",ans);
}
