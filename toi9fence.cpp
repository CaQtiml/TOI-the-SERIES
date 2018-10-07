#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[505][505];
int main(){

    int T = 2;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k); //size n*k
        int t;
        scanf("%d",&t);
        while(t--){
            int x,y;
            scanf("%d%d",&x,&y);
            dp[x+1][y+1] = 1; //+1 to calculate everything on base start=1
        }
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=k;j++){
//                cout << dp[i][j] << " ";
//            }
//            printf("\n");
//        }
        printf("\n\n");
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=k;j++){
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
            }
        }
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=k;j++){
//                cout << dp[i][j] << " ";
//            }
//            printf("\n");
//        }
        int st = min(n,k);
        bool chkb = false;
        for(int a = st;a>=1;a--){
            for(int i = a;i<=n;i++){
                for(int j = a;j<=k;++j){
                    int now = dp[i][j]-dp[i][j-a]-dp[i-a][j]+dp[i-a][j-a];
                    now-= dp[i-1][j-1]-dp[i-a+1][j-1]-dp[i-1][j-a+1]+dp[i-a+1][j-a+1];
                    if(now==0){
                        printf("%d\n",a);
                        chkb = true;
                        break;
                    }
                }
                if(chkb)
                    break;
            }
            if(chkb)
                break;
        }
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=k;++j){
                dp[i][j]=0;
            }
        }
    }
}
