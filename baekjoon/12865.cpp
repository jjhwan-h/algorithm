#include<stdio.h>
#include<vector>

using namespace std;

int N, K;
vector<pair<int,int>> stuff;

int main(){
    int w,v;
    //freopen("./input_file/12865","rt",stdin);
    scanf("%d %d",&N,&K);

    vector<vector<int>>dp(N+1,vector<int>(K+1,0));

    stuff.push_back(pair(0,0));
    for(int i=0; i<N; i++){
        scanf("%d %d",&w,&v);
        stuff.push_back(pair(w,v));
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<=K;j++){
            if(stuff[i].first>j) dp[i][j]=dp[i-1][j];
            else{
                if(dp[i-1][j-stuff[i].first]+stuff[i].second
                    > dp[i-1][j]){
                        dp[i][j]=dp[i-1][j-stuff[i].first]+stuff[i].second;
                    }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    
    // for(int i=0;i<=N;i++){
    //     for(int j=0;j<=K;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d",dp[N][K]);

    return 0;
}
