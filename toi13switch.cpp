#include "bits/stdc++.h"
using namespace std;
char inp[5000005];
char sub[5000005];
#define ll long long
bool rabinkarp(int n , int m)
{
	int cnt=0;
	ll del=1 , x1=0 , x2=0 , chk=1;
	for(int i=1;i<=m;i++)
	{
		del*=53;
		x1=x1*53+inp[i];
		x2=x2*53+sub[i];
	}
	if(x1==x2) cnt++;
	for(int i=m+1;i<=n;i++)
	{
		x1 = x1*53+inp[i]-inp[i-m]*del ;
		if(chk==m)
		{
			if(x1!=x2) return false;
			chk=1;
		}
		else chk++;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",inp+1);
	//cout << inp[1];
	for(int i=1;i<=n;i++)
	{
		sub[i]=inp[i];
		if(n%i==0)
		{
			if(rabinkarp(n,i))
			{
				printf("%d",i) ;
				return 0;
			}
		}
	}
}