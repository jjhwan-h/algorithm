/**
 * @file 11726.cpp
 * @author jang jeongwhan (you@domain.com)
 * @brief 2*N 크기의 타일 채우기
 * @version 0.1
 * @date 2024-03-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

vector<int> dp(1000,0);
int N;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/11726.txt","rt",stdin);

    cin>>N;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=N;i++)
        dp[i] = (dp[i-1] + dp[i-2])%10007;

    cout<<dp[N];
    return 0;
}