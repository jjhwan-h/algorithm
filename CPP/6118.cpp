/**
 * @file 6118.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/6118/숨바꼭질/BFS
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M;
vector<int> map[20001];
queue<pair<int,int> > que;
vector<int> visited(20001,0);

void input(){
    int s,e;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>s>>e;
        map[s].push_back(e);
        map[e].push_back(s);
    }
}

void solve(){
    int idx=0,max=0,cnt=0;

    que.push(make_pair(1,0));
    visited[1]=1;
    while(!que.empty()){
        pair<int,int> el = que.front();
        que.pop();

        if(el.second>max){
            max=el.second;
            idx=el.first;
            cnt=1;
        }else if(el.second==max){
            idx = (idx>el.first) ? el.first : idx;
            cnt++;
        }

        for(int i=0;i<map[el.first].size();i++){
            int v = map[el.first][i];
            if(!visited[v]){
                que.push(make_pair(v,el.second+1));
                visited[v]=1;
            }
        }
    }
    cout<< idx << " " << max <<" "<< cnt;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/6118.txt","rt",stdin);

    input();
    solve();

    return 0;
}