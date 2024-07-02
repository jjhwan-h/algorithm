/**
 * @file 15724.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/15724/주지수
 * @version 0.1
 * @date 2024-07-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>


using namespace std;

int N,M,K;
vector<vector<int> > map(1025,vector<int>(1025,0));
vector<vector<int> > dp(1025,vector<int>(1025,0));

void input(){
    int tmp;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>tmp;
            map[i][j]=tmp;
            dp[i][j]= map[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
}

int getRes(){
    int x1,y1,x2,y2,res=0;
    cin>> y1 >> x1 >> y2 >> x2;
    
    res=dp[y2][x2]-dp[y2][x1-1]-dp[y1-1][x2]+dp[y1-1][x1-1];
    return res;
}

void solve(){
    cin>>K;
    for(int i=0;i<K;i++){
        cout<<getRes()<<"\n";
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/15724.txt","rt",stdin);

    input();
    solve();

    return 0;
}
