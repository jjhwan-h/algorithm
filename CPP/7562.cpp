/**
 * @file 7562.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/7562/나이트의 이동
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct el{
    int y;
    int x;
    int cnt=0;
};
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={-1,-2,-2,-1,1,2,2,1};
int N,M;

void BFS(pair<int,int> s,pair<int,int> e,vector<vector<int> > &visited){
    //
    queue<el> que;
    que.push({s.second,s.first,0});
    visited[s.second][s.first]=1;
    while(!que.empty()){
        el v = que.front();
        que.pop();
        if(v.y==e.second && v.x==e.first) {
            cout<<v.cnt<<"\n";
            return;
        }
        for(int i=0;i<8;i++){
            int nx=v.x+dx[i];
            int ny=v.y+dy[i];
            int ncnt=v.cnt;
            if(nx>=0 && nx<M && ny>=0 && ny<M
                && !visited[ny][nx]){
                    que.push({ny,nx,++ncnt});
                    visited[ny][nx]=1;
                }
        }
    }
}
void solve(){
    pair<int, int> s,e;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>M;
        vector<vector<int> > visited(M+1,vector<int>(M+1,0));
        cin>>s.first; cin>>s.second;
        cin>>e.first; cin>>e.second;
        BFS(s,e,visited);
    }

}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/7562.txt","rt",stdin);

    solve();

    return 0;
}