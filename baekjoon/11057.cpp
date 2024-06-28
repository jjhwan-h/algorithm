/**
 * @file 11057.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/11057/오르막 수
 * @version 0.1
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
int N;
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;
    vector<vector<int> > DP(10,vector<int> (N+1));

    for(int i=0;i<10;i++){
        DP[i][0]=1;
    }
    for(int i=1;i<=N+1;i++){
        DP[9][i]=1;
    }
    for(int i=8;i>=0;i--){
        for(int j=1;j<N+1;j++){
            DP[i][j]=(DP[i][j-1]+DP[i+1][j])%10007;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<N+1;j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<DP[0][N];
   
    return 0;
}