/**
 * @file 15988.cpp
 * @author jang jeong hwan (you@domain.com)
 * @brief 1더하기 2더하기 3 3
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int T,N;
long long dp[1000001]={0,};
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/9095.txt","rt",stdin);

    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        for(int j=4;j<=N;j++){
            dp[j]=(dp[j-1]+dp[j-2]+dp[j-3])%1000000009;
        }
        cout<<dp[N]<<"\n";
    }
    
    return 0;
}