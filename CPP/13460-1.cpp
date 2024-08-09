#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX 10

struct el{
    int rx,ry,bx,by,cnt;
};
vector<vector<char> > map(11,vector<char>(11));
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int visited[10][10][10][10]={0,};
el start;
queue<el> que;

int bfs(){
    int res = -1;
    while(!que.empty()){
        int nrx,nry,nbx,nby,count;
        el cur = que.front();
        que.pop();

        if(cur.cnt>MAX) break;
        if(map[cur.rx][cur.ry]=='O' && map[cur.bx][cur.by]!='O') return cur.cnt;
    
        for(int i=0;i<4;i++){
            nrx=cur.rx;
            nry=cur.ry;
            nbx=cur.bx;
            nby=cur.by;
            count=cur.cnt;
            
            while(map[nrx][nry]!='#' && map[nrx][nry]!='O'){
                nrx+=dx[i];
                nry+=dy[i];
            }
            while(map[nbx][nby]!='#' && map[nbx][nby]!='O'){
                nbx+=dx[i];
                nby+=dy[i];
            }
            if(map[nrx][nry]=='#') {
                nrx-=dx[i];
                nry-=dy[i];
            }
            if(map[nbx][nby]=='#'){
                nbx-=dx[i];
                nby-=dy[i];
            }
            int rdist=0;
            int bdist=0;
           
           if(nrx==nbx && nry==nby && map[nrx][nry]!='O'){
                if(cur.rx==cur.bx){
                    rdist = abs(nry-cur.ry);
                    bdist = abs(nry-cur.by);
                }
                if(cur.ry==cur.by){
                    rdist = abs(nrx-cur.rx);
                    bdist = abs(nrx-cur.bx);
                }
                if(rdist>bdist){
                    nrx=nrx-dx[i];
                    nry=nry-dy[i];
                }
                else{
                    nby=nby-dy[i];
                    nbx=nbx-dx[i];
                }
           }

           if(visited[nrx][nry][nbx][nby]==0){
            visited[nrx][nry][nbx][nby]=1;
            el next;
            next.rx=nrx;
            next.ry=nry;
            next.bx=nbx;
            next.by=nby;
            next.cnt=++count;

            que.push(next);
           }
        }

    }

    return res;
}

void Input(){
    int N,M;
    char ip;
    //freopen("./input_file/13460.txt","rt",stdin);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>ip;
            map[i][j]=ip;
            if(ip=='R'){
                start.rx=i;
                start.ry=j;
            }
            else if(ip=='B'){
                start.bx=i;
                start.by=j;
            }
        }
    }
    visited[start.rx][start.ry][start.bx][start.by] = 1;
    start.cnt=0;
    que.push(start);
    
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         printf("%c ",map[i][j]);
    //     }
    //     printf("\n");
    // }

}

int main(void){
    Input();
    int res=bfs();
    printf("%d",res);

    return 0;
}