#include "bits/stdc++.h"
using namespace std;
const int MAXN = 9000010;
bool prime[MAXN];
void sieve(int target)
{
	memset(prime,true,sizeof(prime));
	for(int i=2;i*i<=MAXN-1;i++)
	{
		if(prime[i])
		{
			for(int j=i*2;j<=MAXN-1;j+=i) prime[j]=false;
		}
	}
	int cnt=1;
	for(int i=2;i<=MAXN-1;i++)
	{
		if(prime[i])
		{
			if(cnt==target) 
			{
				cout << i ;
				exit(0);
			}
			else cnt++;
		}
	}
}
int main()
{
	int N;
	cin >> N;
	sieve(N);
}