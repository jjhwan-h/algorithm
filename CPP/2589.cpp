/**
 * @file 2589.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/2589/보물섬
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct el{
    int x;
    int y;
    int cnt;
};
vector<int> map[51];
queue<el> que;
int N,M;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void input(){
    string tmp;

    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        for(int j=0;j<tmp.length();j++){
            if(tmp[j]=='W')
                map[i].push_back(1);
            else if(tmp[j]=='L')
                map[i].push_back(0);
        }
    }
}

int BFS(int j,int i){
    int maxLen=0;
    vector<vector<int> > visited(N,vector<int> (M,0));
    que.push(el{j,i,0});
    visited[i][j]=1;

    while(!que.empty()){
        el v = que.front();
        que.pop();

        for(int i=0;i<4;i++){
            int nx = dx[i]+v.x;
            int ny = dy[i]+v.y;
            int ncnt= v.cnt+1;
            if(nx>=0 && nx<M && ny>=0 &&ny<N
                && !visited[ny][nx] && map[ny][nx]==0){
                    maxLen = (maxLen>ncnt) ? maxLen : ncnt;
                    que.push(el{nx,ny,ncnt});
                    visited[ny][nx]=1;
            }
        }
    }
    return maxLen;
}

void solve(){
    int res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==1) continue;
           int tmp = BFS(j,i);
           res = (tmp>res) ? tmp : res;
        }
    }

    cout<<res;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2589.txt","rt",stdin);

    input();
    solve();

    return 0;
}