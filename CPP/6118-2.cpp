/**
 * @file 6118-2.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/6118/숨바꼭질/다익스트라
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
vector<int>dist(20001,999999999);
priority_queue<pair<int,int> > pq;

void input(){
    int s,e;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>s>>e;
        map[s].push_back(e);
        map[e].push_back(s);
    }
}
void solve(){ //다익스트라
    int max=0,idx=0,cnt=0;
    pq.push(make_pair(0,1)); // 거리, 정점
    dist[1]=0;
    while(!pq.empty()){
        pair<int,int> el = pq.top();
        pq.pop();

        for(int i=0;i<map[el.second].size();i++){
            int v = map[el.second][i];
            if(dist[v]>dist[el.second]+1){
                dist[v]=dist[el.second]+1;
                pq.push(make_pair(-(el.first+1),v));
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(dist[i]>max){
            max=dist[i];
            idx=i;
            cnt=1;
        }
        else if(dist[i]==max){
            idx = (idx>i) ? i : idx;
            cnt++;
        }
    }
    cout<<idx<<" "<<max<<" "<<cnt;

}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/6118.txt","rt",stdin);

    input();
    solve();

    return 0;
}
