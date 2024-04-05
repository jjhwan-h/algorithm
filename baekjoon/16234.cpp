/**
 * @file 16234.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 인구이동 (BFS, 구현)
 * @version 0.1
 * @date 2024-04-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, L,R;
vector<int> map[51];
vector<pair<int,int> >tmp;
queue<pair<int,int> > Que;
int visited[51][51]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool flag=false;

void input(){
    int num;
    cin>> N >> L >> R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>num;
            map[i].push_back(num);
        }
    }
}
void bfs(int y, int x){
    while(!Que.empty()){
        pair<int,int> el = Que.front();
        Que.pop();

        for(int i=0;i<4;i++){
            int nx=el.second + dx[i];
            int ny=el.first + dy[i];
            if(nx>=0 && nx <N && ny>=0 && ny<N 
                && !visited[ny][nx]){
                int diff = abs(map[ny][nx]-map[el.first][el.second]);
                if(diff>=L && diff<=R){
                    Que.push(make_pair(ny,nx));
                    tmp.push_back(make_pair(ny,nx));
                    visited[ny][nx]=1;
                }
            }
        }
    }
}
void calPopulation(){
    if(tmp.size()>1) {
        flag=false;
        int sum=0, cnt=0;
        for(int i=0;i<tmp.size();i++){
            sum+=map[tmp[i].first][tmp[i].second];
        }
        cnt = tmp.size();
        int population = sum/cnt;
        for(int i=0;i<tmp.size();i++){
            int y=tmp[i].first;
            int x=tmp[i].second;
            map[y][x]=population;
        }
    }
}
void initVisited(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=0;
        }
    }
}
void solve(){
    int res=0;
    while(!flag){
        flag=true;
        initVisited();  
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                    tmp.clear();
                    if(!visited[i][j]){
                        Que.push(make_pair(i,j));
                        tmp.push_back(make_pair(i,j));
                        visited[i][j]=1;
                        bfs(i,j);
                        calPopulation();
                    }
            }
        }
        res++;
    }
    cout<<--res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/16234.txt","rt",stdin);

    input();
    solve();
    return 0;
}