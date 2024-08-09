/**
 * @file 1926.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 그림(BFS)
 * @version 0.1
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>
#define MAX 500

using namespace std;
int N,M;
vector<int> canvas[MAX];
queue<pair<int,int> > Que;
int visited[MAX][MAX]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void Input(){
    int tmp;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>tmp;
            canvas[i].push_back(tmp);
        }
    }
}
int BFS(int i, int j){
    int cnt=0;
    if(canvas[i][j] && !visited[i][j]){
        Que.push(make_pair(i,j));
        visited[i][j]=1;
        cnt++;
        while(!Que.empty()){
            pair<int,int> tmp = Que.front();
            Que.pop();
            for(int k=0;k<4;k++){
                int nx=tmp.second+dx[k];
                int ny=tmp.first+dy[k]; 
                if(nx>=0 && nx<M && ny>=0 && ny<N && !visited[ny][nx] && canvas[ny][nx]){
                    {
                        Que.push(make_pair(ny,nx));
                        visited[ny][nx]=1;
                        cnt++;
                    }
                }
            }
        }
    }

    return cnt;
}
void Solve(){
    int cnt=0,res1=0,res2=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cnt=BFS(i,j);
            res1 = (cnt>0)?res1+1:res1;
            res2 = (cnt>res2)?cnt:res2;
        }
    }
    cout<<res1<<"\n"<<res2;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1926.txt","rt",stdin);

    Input();
    Solve();

    return 0;

}
