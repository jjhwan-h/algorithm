/**
 * @file 1593.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1593/문자 해독
 * @version 0.1
 * @date 2024-07-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int W,S;
vector<int> per(100,0);
string arr;

void input(){
    string s;
    cin>>W>>S;

    cin>>s;
    for(int i=0;i<s.size();i++){
        per[s[i]-'A']++;
    }
    cin>>arr;
}

void solve(){
    int lt=0,res=0;
    vector<int> cnt(100,0);

    for(int i=0;i<arr.size();i++){
        if(per[arr[i]-'A'] > cnt[arr[i]-'A']){
            cnt[arr[i]-'A']++;
        }else{
            for(int j=lt;j<=i;j++){
                if(arr[i]==arr[j]){
                    lt=j+1;
                    break;
                }
                cnt[arr[j]-'A']-=1;
            }
        }
        if(i-lt+1==W) res++;
    }
    cout<<res;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1593.txt","rt",stdin);

    input();
    solve();

    return 0;
}