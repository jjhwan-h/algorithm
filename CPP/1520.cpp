/*
2024/01/25 장정환 백준 1520번
*/

#include<iostream>

using namespace std;

pair<int, int> map[501][501];
int N,M;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int DFS(int y, int x){
    if(y==M-1 && x==N-1) return 1;
    if(map[y][x].second!=-1) return map[y][x].second;

    map[y][x].second=0;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >=0 && nx <N && ny >=0 && ny <M
            && map[y][x].first > map[ny][nx].first){
                map[y][x].second = map[y][x].second + DFS(ny,nx);
        }            
    }
    return map[y][x].second;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1520.txt","rt",stdin);

    cin>> M >> N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j].first;
            map[i][j].second=-1;
        }
    }
    cout<<DFS(0,0);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<map[i][j].second<<" ";
        }
        cout<<"\n";
    }

    return 0;
}