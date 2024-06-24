/**
 * @file 1743.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1743/음식물 피하기
 * @version 0.1
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>

using namespace std;
vector<pair<int,int> > trash;
vector<vector<int> > map(101,vector<int>(101,0));
vector<vector<int> > visited(101,vector<int>(101,0));
int N,M,K;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void input(){
    int y,x;
    cin>>N>>M>>K;
    for(int i=0;i<K;i++){
        cin>>y>>x;
        map[y][x]=1;
        trash.push_back(make_pair(y,x));
    }
}
int DFS(pair<int,int> v){
    int y=v.first;
    int x=v.second;
    if(visited[y][x]) return 0;
    visited[y][x]=1;

    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=1 && ny<=N && nx>=1 && nx<=M
            && !visited[ny][nx] && map[ny][nx]){
                map[y][x]+=DFS(make_pair(ny,nx));
            }
    }
    return map[y][x];
}
void solve(){
    int max=0;
    for(int i=0;i<trash.size();i++){
        int res =DFS(trash[i]);
        max = (max<res) ? res: max;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<max;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1743.txt","rt",stdin);

    input();
    solve();

    return 0;
}