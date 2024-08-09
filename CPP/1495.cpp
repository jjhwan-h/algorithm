/**
 * @file 1495.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1495
 * @version 0.1
 * @date 2024-07-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N,S,M;
    int list[51];
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1495.txt","rt",stdin);
    
    cin>>N>>S>>M;
    for(int i=1;i<=N;i++){
       cin>>list[i];
    }

    bool dp[2][51][1001]={false};
    dp[0][0][S]=true;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(dp[0][i-1][j]){
                int add = j+list[i];
                int sub = j-list[i];
                if(add<=M) dp[1][i][add]=true;
                if(sub>=0) dp[1][i][sub]=true;
            }
        }
        for(int j=0;j<=M;j++){
           dp[0][i][j] = dp[1][i][j];
           dp[1][i][j]=false;
        }
    }
    int res=-1;
    for(int i=0;i<=M;i++){
        if(dp[0][N][i]) 
            res = (res>i) ? res : i;
    }
    cout<<res;

    return 0;
}