#include<vector>
#include<stdio.h>

using namespace std;
int N,K;
int op = 1000000007;
vector<vector<int>>dp;

int bino_coef(int N, int K){
    // if(times>got){
    //     return -1;
    // }
    for(int i=0;i<N+1;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<K+1;j++){
        dp[j][j]=1;
    }

    for(int i=1;i<N+1;i++){
        for(int j=1;j<K+1;j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    //  for(int i=0;i<N+1;i++){
    //     for(int j=0;j<K+1;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[N][K];
}  

int main(void){
    int res;
    scanf("%d %d",&N,&K);
    vector<int> tmp(K+1,0);
   
    for(int i=0;i<N+1;i++){
        dp.push_back(tmp);
    }
   
    res = bino_coef(N,K) % op;

    printf("%d",res);

    return 0;

}