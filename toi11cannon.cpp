#include "bits/stdc++.h"
using namespace std;
vector<int> dp,dp2;
const int INF = 1e9+29;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M,K,L;
	cin >> N >> M >> K >> L ;
	for(int i=1;i<=N;i++)
	{
		int rr;
		cin >> rr;
		dp.emplace_back(rr);
	}
	dp.emplace_back(INF);
	for(int i=1;i<=K;i++)
	{
		int cnt=0;
		for(int j=1;j<=M;j++)
		{
			int pos;
			bool chk=0;
			cin >> pos;
			//vector<int>::iterator lowerit , upperit;
			int lower,upper,templower;
			templower = lower_bound(dp.begin(),dp.begin()+N,pos-L) - dp.begin() ;
			if(j==1) {lower=templower; chk=1;}
			else if(templower>lower) {lower=templower; chk=1;}
			upper = upper_bound(dp.begin(),dp.begin()+N,pos+L) -1 - dp.begin();
			if(chk) cnt+=(upper-lower+1);
			else cnt+=(upper-lower);
			lower=upper;
		}
		//cout << "\n";
		cout << cnt << "\n";
	}
}
