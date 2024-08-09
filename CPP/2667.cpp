/**
 * @file 2667.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief  BOJ/2667/단지번호붙이기
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int N;
vector<int> map[26];
vector<int> res;
int visited[26][26]={0,};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void input(){
    string tmp;
    cin>>N;
    for(int i=0;i<N;i++){
            cin>>tmp;
            for(char c : tmp){
                map[i].push_back(c-'0');
            }
    }
}

int BFS(int y, int x){
    int cnt=1;
    queue<pair<int,int> > que;
    visited[y][x]=1;
    que.push(make_pair(x,y));

    while(!que.empty()){
        pair<int,int> el = que.front();
        que.pop();

        for(int i=0;i<4;i++){
            int nx = el.first+dx[i];
            int ny = el.second+dy[i];
            if(ny<N && ny>=0 && nx<N && nx>=0
                && !visited[ny][nx] && map[ny][nx]){
                    que.push(make_pair(nx,ny));
                    visited[ny][nx]=1;
                    cnt++;
                }
        }

    }
    return cnt;
}

void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] && !visited[i][j]){
                int cnt = BFS(i,j);
                res.push_back(cnt);
            }
        }
    }
    
    sort(res.begin(),res.end());
    cout<<res.size()<<"\n";
    for(int j=0;j<res.size();j++){
        cout<<res[j]<<"\n";
    }
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2667.txt","rt",stdin);

    input();
    solve();

    return 0;
}
