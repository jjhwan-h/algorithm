/**
 * @file 14940.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/14940
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct v{
    int y;
    int x;
    int dist;
};
int N,M;
vector<int> map[1001];
vector<vector<int> > visited(1001,vector<int>(1001,0));
vector<vector<int> > res(1001,vector<int>(1001,-1));
queue<v> que;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void input(){
    int tmp;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmp;
            map[i].push_back(tmp);
            if(tmp==2){
                que.push(v{i,j,0});
                visited[i][j]=1;
            }
        }
    }
}
void solve(){
    while(!que.empty()){
        v el = que.front();
        que.pop();
        res[el.y][el.x]=el.dist;
        for(int i=0;i<4;i++){
            int nx = dx[i]+el.x;
            int ny = dy[i]+el.y;
            if(nx>=0 && nx<M && ny>=0 && ny<N
                && !visited[ny][nx]){
                    if(map[ny][nx]==0) continue;
                    que.push(v{ny,nx,el.dist+1});
                    visited[ny][nx]=1;
                }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0) res[i][j]=0;
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/14940.txt","rt",stdin);

    input();
    solve();

    return 0;
}