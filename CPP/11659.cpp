/**
 * @file 11659.cpp
 * @author jang jeong hwan (you@domain.com)
 * @brief 구간합 구하기4(dp)
 * @version 0.1
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
vector<int> dp(100001,0);
int N,M;
void input(){
    int tmp;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>dp[i+1];
        dp[i+1]+=dp[i];
    }
}
void solve(){
    int i,j;
    for(int k=0;k<M;k++){
        cin>>i>>j;
        cout<<dp[j]-dp[i-1]<<"\n";
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/11659.txt","rt",stdin);

    input();
    solve();
}