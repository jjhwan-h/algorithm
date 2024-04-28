/**
 * @file 11501.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 주식(그리디)
 * @version 0.1
 * @date 2024-04-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int T,N;
long long res=0; //출력조건 64bit

void getValue(){
    int tmp;

    cin>>N;
    vector<int> visited(N,0),origin;
    vector<pair<int,int> > v;
    for(int i=0;i<N;i++){
        cin>>tmp;
        v.push_back(make_pair(tmp,i));
        origin.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        int idx = v[N-i-1].second;
        if(!visited[idx]){
            visited[idx]=1;
            for(int j=idx-1; j>=0; j--){
                if(!visited[j]){
                    int el = origin[j];
                    res+=origin[idx]-el;
                    visited[j]=1;
                }
            }
        }
    }
}
void solve(){
    cin>>T;
    while(T){
        getValue();
        cout<<res<<"\n";
        res=0;
        T--;
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/11501.txt","rt",stdin);

    solve();

    return 0;
}