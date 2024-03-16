#include<iostream>
#include<stdio.h>
#include<queue>
#include<limits.h>
#include<string>

using namespace std;
struct node{
    int x,y,cnt;
    node(int a,int b,int c){
        x=a;
        y=b;
        cnt=c;
    }
};

queue<node> Que;
int res=INT_MAX,N,M;
int map[101][101];
int visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void BFS(int a, int b){
    Que.push(node(a,b,1));
    visited[a][b]=1;
    while(!Que.empty()){
        node tmp = Que.front();
        Que.pop();
        if(tmp.x == N && tmp.y == M && res>tmp.cnt){
                res=tmp.cnt;
        }
        for(int i=0;i<4;i++){
            int nx = tmp.x+dx[i];
            int ny = tmp.y+dy[i];
            int cnt = tmp.cnt+1;
            if(nx>=1 && nx<=N && ny>=1 && ny<=M && map[nx][ny]==1 && visited[nx][ny]==0){
                Que.push(node(nx,ny,cnt));
                visited[nx][ny]=1;
            }
        }

    }
    cout<<res<<endl;
}

int main(void){
    string tmp;
    //freopen("./input_file/2178.txt","rt",stdin);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>tmp;
        for(int j=M;j>=1;j--){
            map[i][j]=tmp[j-1]-48; //믄지 -> 숫자
            visited[i][j]=0;
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=M;j++){
    //         printf("%d ",map[i][j]);
    //     }
    //     printf("\n");
    // }

    BFS(1,1);

    return 0;
}