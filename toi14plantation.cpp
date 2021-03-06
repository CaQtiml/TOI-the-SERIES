#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+10;
const int INF=(1<<30);
#define x first
#define y second
#define ll long long
#define ii pair<int,int>
#define mkp make_pair
pair<int,int> v[N],aux[N];
inline ll expon(int x)
{
	return 1LL*x*x;
}
inline ll dist(const ii &a , const ii &b)
{
	return 1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y);
}
bool pcompare(ii &a , ii &b)
{
	if(a.y==b.y) return a.x<b.x;
	else return a.y<b.y ;
}
ll cp(int st , int ed) //closest pair function
{
	if(st>=ed) return INF;
	if(ed-st==1) return dist(v[st],v[ed]);
	int mid = (st+ed)>>1;
	ll d = min(cp(st,mid),cp(mid+1,ed));
	int k=0;
	for(int i=st;i<=ed;i++)
	{
		if(expon(v[mid].x-v[i].x)<=d) aux[k++] = v[i];
	}
	sort(aux,aux+k,pcompare);
	for(int i=0;i<k;i++)
	{
		for(int j=i+1 ; j<k && (expon(aux[j].y-aux[i].y)<d) ; j++)
		{	
			d = min( d , dist(aux[i],aux[j]) );
		}
	}
	return d;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,w;
	double ra;
	int dd;
	cin >> w;
	while(w--)
	{
		cin >> n >> ra >> dd;
		for(int i=1;i<=n;i++)
		{
			int xx,yy;
			cin >> xx >> yy ;
			v[i]=mkp(xx,yy);
		}
		sort(v+1,v+n+1);
		if (sqrt(cp(1,n))-2*ra>=dd) cout << "Y\n";
		else cout << "N\n";  
	}
}

