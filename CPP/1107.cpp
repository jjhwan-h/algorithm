/**
 * @file 1107.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1107
 * @version 0.1
 * @date 2024-07-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> broken(10,0);
string N;
void input(){
    int num,tmp;
    cin>>N;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>tmp;
        broken[tmp]=1;
    }
}

bool isPossible(int n){
    string num = to_string(n);
    for(int i=0;i<num.size();i++){
        if(broken[num[i]-'0']) return false;
    }
    return true;
}
void solve(){
    int channel = stoi(N);
    int settingChan = 100;
    int cnt = abs(channel-settingChan);

    for(int i=0;i<=1000000;i++){
        if(isPossible(i)){
            int diff = abs(channel-i);
            string num = to_string(i);
           cnt = (cnt > diff+num.size()) ? diff+num.size() : cnt;
        }
    }

    cout<<cnt;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1107.txt","rt",stdin);

    input();
    solve();

    return 0;
}