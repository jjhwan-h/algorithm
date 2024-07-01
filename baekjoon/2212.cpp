/**
 * @file 2212.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/2212/센서
 * @version 0.1
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,K;
vector<int> arr;

bool comp(int &a, int &b){
    return a>b;
}
void input(){
    int tmp;
    cin>>N;
    cin>>K;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
}
void solve(){
    int res=0,cnt=1;
    vector<int> diff;
    sort(arr.begin(),arr.end());
    for(int i=1;i<N;i++){
        int d = arr[i]-arr[i-1];
        diff.push_back(d);
    }
    sort(diff.begin(),diff.end(),comp); //내림차순

    for(int i=0;i<N-1;i++){
        if(cnt<K) {cnt++; continue;}

        res+=diff[i];
    } 
    cout<<res;  
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2212.txt","rt",stdin);

    input();
    solve();

    return 0;
}