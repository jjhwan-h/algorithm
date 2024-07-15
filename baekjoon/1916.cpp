/**
 * @file 1916.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1916
 * @version 0.1
 * @date 2024-07-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


vector<pair<int,int> > map[1001];
int N,M,rs,re;

void input(){
    int s,e,v;
    cin>>N;
    cin>>M;

    for(int i=0;i<M;i++){
        cin>>s>>e>>v;
        map[s].push_back(make_pair(v,e));
    }
    cin>>rs>>re;
}
void solve(){
    vector<int> dijk(N+1,2147000000);
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,rs));
    dijk[rs]=0;

    while(!pq.empty()){
        pair<int,int> el = pq.top();
        pq.pop();
        int v = -el.first, e = el.second;
        if(dijk[e]<v) continue;
        for(int i=0;i<map[e].size();i++){
            pair<int,int> ne = map[e][i];
            if(dijk[ne.second]>dijk[e] + ne.first){
                dijk[ne.second]=dijk[e] + ne.first;
                pq.push(make_pair(-dijk[ne.second],ne.second));
            }
        }
    }

    cout<<dijk[re];
    return;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1916.txt","rt",stdin);

    input();
    solve();

    return 0;
}