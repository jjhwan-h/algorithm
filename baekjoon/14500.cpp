/*
2023/12/28
백준 14500 테트로미노
*/
#include<iostream>
#include<stack>

using namespace std;

int N, M;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int map[550][550];
int visited[550][550]={0,};
int Max,cnt;
int depth;

void DFS(int y, int x){// 행, 열
    if(depth>=3){
        if(cnt>Max) {
            // for(int i=0;i<N;i++){
            //     for(int j=0;j<M;j++){
            //         cout<< visited[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            Max=cnt;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && nx<M && ny>=0 && ny<N
            && !visited[ny][nx]){
                depth++;
                visited[ny][nx]=1;
                cnt+=map[ny][nx];
                DFS(ny,nx);
                visited[ny][nx]=0;
                depth--;
                cnt-=map[ny][nx];
        }
    }
}
void CheckT(int y, int x){// DFS로 확인불가능한 T자형 블록확인
    cnt=map[y][x];

    if(x+1<M && x-1>=0){
        cnt+=map[y][x+1];
        cnt+=map[y][x-1];
        for(int i=0;i<2;i++){
            int ny = y+dy[i];
            if(ny>=0 && ny<N){
                cnt+=map[ny][x];
                if(cnt>Max) {
                    Max=cnt;
                }
                cnt-=map[ny][x];
            }
        }
    }
    
    cnt=map[y][x];

    if(y+1<N && y-1>=0){
        cnt+=map[y+1][x];
        cnt+=map[y-1][x];
        for(int i=2;i<4;i++){
            int nx = x+dx[i];
            if(nx>=0 && nx<M){
                cnt+=map[y][nx];
                if(cnt>Max) {
                    //cout<<cnt<<endl;
                    Max=cnt;
                }
                cnt-=map[y][nx];
            }
        }
    }
    
    return;
}
void Input(){
    int tmp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmp;
            map[i][j] = tmp;
        }
    }
}

void Solve(){
     for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            depth=0;
            cnt=map[i][j];
            visited[i][j]=1;
            DFS(i,j);
            CheckT(i,j);
            visited[i][j]=0;
        }
    }
    cout<<Max<<endl;
}
int main(void){
    //freopen("./input_file/14500.txt","rt",stdin);
    cin>> N >> M;

    Input();
    Solve();

    return 0;
    
}
