/**
 * @file 3109.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/3109/빵집
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
vector<int> map[10001];
vector<int> visited[10001];
struct el {
    int y;
    int x;
};
int R,C,cnt;
int dx[3]={1,1,1};
int dy[3]={-1,0,1};

void input(){
    char tmp;
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>tmp;
            if(tmp=='.') map[i].push_back(0);
            else if(tmp=='x') map[i].push_back(1);
            visited[i].push_back(0);
        }
    }
}
int DFS(el elem){
    int y=elem.y, x=elem.x;
    if(x==C-1) {cnt++; return 1;}
    visited[y][x]=1;
    for(int i=0;i<3;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(ny>=0 && ny<R && nx>=0 && nx<C && !visited[ny][nx] && !map[ny][nx]){
            el nelem={ny,nx};
            if(DFS(nelem)) return 1;
        }
    }
    return 0;
}
void solve(){
    for(int i=0;i<R;i++){
        el elem={i,0};
        DFS(elem);
    }
    cout<<cnt;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/3109.txt","rt",stdin);

    input();
    solve();

    return 0;
}