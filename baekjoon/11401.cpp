#include<vector>
#include<stdio.h>

using namespace std;
int N,K;
int op = 1000000007;
vector<vector<int>>dp;

int bino_coef(int times, int got){
    // if(times>got){
    //     return -1;
    // }

    if(N==times){
        return got == K;
    }    

    if(dp[times][got] != -1){
        return dp[times][got];
    }

    dp[times][got] = bino_coef(times+1,got) + bino_coef(times+1,got+1);
    // printf("%d %d\n",dp[1][0],dp[1][1]);
    return dp[times][got];
}  

int main(void){
    int res;
    scanf("%d %d",&N,&K);
    vector<int> tmp(N+1,-1);
    // for(int i=0;i<N+1;i++){
    //     printf("%d ",tmp[i]);
    // }
    for(int i=0;i<N+1;i++){
        dp.push_back(tmp);
    }
    // for(int i=0;i<N+1;i++){
    //     for(int j=0;j<N+1;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }

    res = bino_coef(0,0) % op;

    printf("%d",res);

    return 0;

}