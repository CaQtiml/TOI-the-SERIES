#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
ii dp[1005][1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int limit , N ;
	cin >> limit >> N ;
	int a[N+5];
	int b[N+5];
	for(int i=1;i<=N;i++)
	{
		cin >> a[i];
		int x = dp[i-1][0].f ;
		int y = dp[i-1][0].s ;
		if(y+a[i]>limit)
		{
			x++;
			y=a[i];
		}
		else y+=a[i];
		dp[i][0]=make_pair(x,y);
	}
	for(int i=1;i<=N;i++)
	{
		cin >> b[i];
		int x = dp[0][i-1].f;
		int y = dp[0][i-1].s;
		if(y+b[i]>limit)
		{
			x++;
			y=b[i];
		}
		else y+=b[i];
		dp[0][i]=make_pair(x,y);
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{	
			int x,y;
			int ax = dp[i-1][j].f ;
			int ay = dp[i-1][j].s ;
			int bx = dp[i][j-1].f ;
			int by = dp[i][j-1].s ; 
			if(ay+a[i]>limit)
			{
				ax++;
				ay=a[i];
			}
			else ay+=a[i];
			if(by+b[j]>limit)
			{
				bx++;
				by=b[j];
			}
			else by+=b[j];
			if(ax==bx)
			{
				if(ay<by)
				{
					x=ax;
					y=ay;
				}
				else
				{
					x=bx;
					y=by;
				}
			}
			else
			{
				if(ax<bx)
				{
					x=ax;
					y=ay;
				}
				else
				{
					x=bx;
					y=by;
				}
			}
			dp[i][j]=make_pair(x,y);
		}
	}
	cout << dp[N][N].f+1 << "\n" << dp[N][N].s ;
}