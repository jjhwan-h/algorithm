/**
 * @file 9251.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief  BOJ/9251
 * @version 0.1
 * @date 2024-08-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<string>


using namespace std;

int dp[1002][1002]={0,};
string s1,s2;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/9251.txt","rt",stdin);


    cin>>s1; cin>>s2;

    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            if(s1[i]==s2[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else {
                dp[i+1][j+1] = (dp[i+1][j] > dp[i][j+1]) ? dp[i+1][j] : dp[i][j+1];
            }
        }
    }
    
    cout<<dp[s1.length()][s2.length()];

    return 0;
}