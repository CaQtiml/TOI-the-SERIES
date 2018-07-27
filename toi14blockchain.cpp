#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
#define f first
#define s second
int n,m;
map<vector<ii>,int> M;
std::vector<ii> rt()
{
    int z;
    scanf("%d",&z);
    vector<ii> V;
    int u,v;
    for(int i=1;i<z;i++)
    {
        scanf("%d %d",&u,&v);
        if(u>v) swap(u,v);
        V.emplace_back(u,v);
    }
    sort(V.begin(),V.end());
    return V;
}
int main(int argc, char const *argv[])
{
    scanf("%d %d",&n,&m);
    while(n--) M[rt()]++;
    while(m--) printf("%d\n",M[rt()]);
}