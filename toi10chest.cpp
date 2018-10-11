//coordinate compression
#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
vii v;
ll a[5];
ll tmp;
void update(int val)
{
	bool rev=0; //use to check that val is neg or not
	if(val<0){ rev=1; val=-val;}
	while(!(val%2)) {val/=2; a[0]+=(rev ? -1:1);} // !(val%2) = (val%2)==0
	while(!(val%3)) {val/=3; a[1]+=(rev ? -1:1);}
	while(!(val%5)) {val/=5; a[2]+=(rev ? -1:1);}
	while(!(val%7)) {val/=7; a[3]+=(rev ? -1:1);}
}
void compute()
{
	tmp=1;//tmp=the number of factor in that box
	//this is theory to find the number of factors
	for(int k=0;k<4;k++) tmp*=(a[k]+1);
}
int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int val,st,ed;
		scanf("%d%d%d",&val,&st,&ed);
		v.emplace_back(st,val);
		v.emplace_back(ed+1,-val);
	}
	sort(v.begin(),v.end());
	ll ans=1 , cnt=0 , pre=-1; //pre => the lastest action belongs to "pre" gap .
	for(int i=0;i<v.size();i++) //Update the number of factors every the update of number
	{
		if(v[i].first != pre)
		{
			compute();
			if(ans==tmp) cnt+=(v[i].first-pre);
			else if(tmp>ans){
				ans=tmp;
				cnt=0;
				cnt+=(v[i].first-pre);
			}
		}
		update(v[i].second);
		pre = v[i].first;
	}
	cout << ans << " " << cnt ;
} 