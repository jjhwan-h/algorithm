/*
2023/12/30 장정환
벡준 2294 동전2
*/
#include<iostream>
#include<vector>

using namespace std;



int main(void){
    int n,k,tmp,cur,cnt;

    //freopen("./input_file/2294.txt","rt",stdin);

    cin>>n>>k;
    vector<int> coins; //주어진 동전들
    vector<int> dp(k+1,10001); //만들어야하는 값 dp

    coins.push_back(0);
    dp[0]=0;

    for(int i=0;i<n;i++){
        cin>>tmp;
        coins.push_back(tmp);
    }
    for(int i=1;i<=n;i++){
        for(int j=coins[i];j<=k;j++){
            if(dp[j]>=dp[j-coins[i]]+1)
            dp[j]=dp[j-coins[i]]+1;
        }
    }

    if(dp[k]==10001) cout<<-1;
    else cout<<dp[k];
   

    return 0; 
}