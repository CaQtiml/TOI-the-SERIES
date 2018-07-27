#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define f first
#define y second
#define ii pair<int,int>
ii p[100005];
vector<int> num;
int main(int argc, char const *argv[])
{
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].first);
		p[i].first+=p[i-1].first;
		p[i].second=i;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		num.emplace_back(p[i].f);
		p[i].y=max(p[i-1].y,p[i].y);
	}
	for(int i=1;i<=m;i++){
		int q;
		scanf("%d",&q);
		auto it=upper_bound(num.begin(),num.end(),q);
		it--;
		int po=it-num.begin()+1;
		printf("%d\n",p[po].y);
	}
}