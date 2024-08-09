/**
 * @file 2156.cpp
 * @author jang jeong hwan (you@domain.com)
 * @brief 포도주 시식(dp)
 * @version 0.1
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
struct el{
    int f;
    int s;
    int t;
};
vector<el> dp;
vector<int> num;
int N;

void input(){
    int tmp;
    cin >> N;
    num.push_back(0);
    for(int i=0;i<N;i++){ 
        cin>>tmp;
        num.push_back(tmp);
    }
}
void solve(){
    int res=0;
    int tmp;
    /*dp초기값 세팅*/
    dp.push_back({0,0,0});
    dp.push_back({num[1],num[1],num[1]});
    dp.push_back({num[2]+num[1],num[2],num[2]});

    for(int i=3;i<N+1;i++){ //dp계산
        int f = (dp[i-1].s >= dp[i-1].t) ? dp[i-1].s+num[i] : dp[i-1].t+num[i];
        tmp = (dp[i-2].f >= dp[i-2].s) ? dp[i-2].f : dp[i-2].s;
        int s = (tmp >= dp[i-2].t) ? tmp+num[i] : dp[i-2].t+num[i];
        tmp = (dp[i-3].f >= dp[i-3].s) ? dp[i-3].f : dp[i-3].s;
        int t = (tmp >= dp[i-3].t) ? tmp+num[i] : dp[i-3].t+num[i];
        dp.push_back({f,s,t});
    }
    for(int i=N;i>N-2;i--){ //최대값 찾기
        tmp = (dp[i].f > dp[i].s) ? dp[i].f : dp[i].s;
        tmp = (tmp > dp[i].t) ? tmp : dp[i].t;
        res = (tmp > res) ? tmp : res;
    }
    cout<<res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2156.txt","rt",stdin);

    input();
    solve();

    return 0;
}