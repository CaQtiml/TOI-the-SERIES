#include "bits/stdc++.h"
using namespace std;
int tree[1000010];
int lis[1000010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int ans=-1e9;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> tree[i];
	memset(lis,-1,sizeof(lis));
	for(int i=1;i<=n;i++)
	{
		int st=1 , ed=n+10;
		while(st<=ed)
		{
			int mid = (st+ed)>>1;
			if(lis[mid]==-1 || (lis[mid]!=-1 && tree[i]<lis[mid]) ) ed=mid-1;
			else st=mid+1;
		}
		lis[st] = tree[i];
		ans=max(ans,st);
	}
	cout << n-ans;
}