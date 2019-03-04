#include "bits/stdc++.h"
using namespace std;
#define mkp make_pair
#define pb push_back
#define F first
#define S second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n,0);
        for(int i=0;i<n;i++)
            p[i]=i;
    }
    int fs(int i) //findset
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j) //issameset
    {
        return (fs(i)==fs(j));
    }
    void us(int i,int j) //unionset
    {
        //int x,y;
        p[fs(i)]=fs(j);
    }
};

vector<pair<int,ii> > v;

int main(){
    //int coun=0;
    //UnionFind uf(n+4); //use n+4 instead of n for safety
    int n,e;
    //UnionFind uf(n+5); //use n+4 instead of n for safety
    scanf("%d %d",&n,&e);
    UnionFind uf(n+5);
    for(int i=1;i<=e;i++){
        int w,x,y;
        scanf("%d %d %d",&x,&y,&w);
        v.push_back(make_pair(w,make_pair(x,y)));
        //printf("PASS\n");
    } //edge list

    //kruskal routine
    sort(v.begin(),v.end(),greater<pair<int,ii> >());
    long long ans=0;
    for(int i=0;i<v.size();i++){
        int a,b,c;
        c=v[i].first;
        a=v[i].second.first;
        b=v[i].second.second;
        //printf("PASS\n");
        if(!uf.iss(a,b)){
            uf.us(a,b);
            //coun++;
            //printf("PASS\n");
            ans+=c;
        }
    }
    //printf("%d\n",coun);
    printf("%lld",ans-(n-1));
    //printf("%lld",ans);
}
/*
6 9
1 2 8
2 3 6
1 4 6
4 2 6
4 5 8
2 5 7
5 6 5
2 6 9
3 6 5

output=33
*/

//edgelist
//kruskal algorithm
