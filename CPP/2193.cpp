/**
 * @file 2193.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 이친수 (DFS, DP)
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
int main(void){
    int N;
    long long dp[91][2]={0,};
    
    cin>>N;

    dp[1][0]=0;
    dp[1][1]=1;
    dp[2][0]=1;
    dp[2][1]=0;

    for(int i=3;i<=N;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[N][0]+dp[N][1];
    return 0;
}