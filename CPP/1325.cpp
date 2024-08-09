/**
 * @file 1325.cpp
 * @author jang jeonghwan(you@domain.com)
 * @brief 효율적인해킹(BFS)
 * @version 0.1
 * @date 2024-02-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N,M,maximum,cnt=1;

vector<vector<int> > com(10001); //인접리스트
bool visited[10001]; //방문배열
int res[10001];
queue<int> Que;

void Input(){
    int n1,n2;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>n1>>n2;
        com[n2].push_back(n1); //인접리스트 구성
    }
}
void BFS(int n){
    visited[n]=1;
    Que.push(n);
    while(!Que.empty()){
        int idx = Que.front();
        Que.pop();
        
        for(int i=0;i<com[idx].size();i++){
            int nidx=com[idx][i];
            if(!visited[nidx]){
                Que.push(nidx);
                cnt++;
                visited[nidx]=1;
            }
        }
    }
}
void Solve(){
    for(int i=1;i<=N;i++){ //각 컴퓨터마다 BFS호출
        BFS(i);
        if(cnt>=maximum) { // 컴퓨터 중 가장많은 해킹을 당하는 수 
            maximum=cnt; 
        }
        res[i]=cnt; // 각 컴퓨터별 해킹당하는게 가능한 컴퓨터수
        for(int i=0;i<=N;i++){ //방문배열 초기화
            visited[i]=0;
        }
        cnt=1; //해킹당하는게 가능한 컴퓨터수 초기화
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1325.txt","rt",stdin);
    Input();
    Solve();
    
    for(int i=1;i<=N;i++) 
    {
        if(res[i]==maximum) cout<<i<<" ";
    }
    return 0;
}