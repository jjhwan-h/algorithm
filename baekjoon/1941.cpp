/**
 * @file 1941.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 소문난 칠공주 (백트래킹)
 * @version 0.1
 * @date 2024-03-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<queue>
#define LINE 5
#define MAX 7

using namespace std;
char map[5][5];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<int> selected;
queue<int> Que;
int res;

void Input(){
    for(int i=0;i<LINE;i++){
        for(int j=0;j<LINE;j++){
            cin>> map[i][j];
        }
    }
}
bool isAdjacent(){ //조합으로 구한 원소들이 인접한지확인
    int visited[LINE*LINE]={0,};
    int adj=1;
    Que.push(selected[0]);
    visited[selected[0]]=1;
    while(!Que.empty()){
        int el = Que.front();
        Que.pop();
        int x = el%LINE;
        int y = el/LINE;
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<LINE && ny<LINE && !visited[ny*LINE+nx]){
                for(int j=0;j<MAX;j++){
                    int tx=selected[j]%LINE;
                    int ty=selected[j]/LINE;
                    if(nx==tx && ny==ty){
                        Que.push(selected[j]);
                        visited[selected[j]]=1;
                        adj++;
                    }
                }
            }
        }        
    }
    if(adj==MAX) return true;
    else return false;
}
bool isValidRule(){ // 조합에서 S가 4개이상포함되는지 확인
    int S_cnt=0;
    for(int i=0;i<MAX;i++){
        int el = selected[i];
        if(map[el/LINE][el%LINE]=='S') S_cnt++; 
    }
    if(S_cnt<LINE-1) return false;
    return true;
}
 void makeCombination(int s){ // 7명의 조합을 뽑는다.
    if(selected.size()==MAX){
        if(isValidRule() && isAdjacent()) res++;
        return;
    }
    for(int i=s;i<LINE*LINE;i++){
        selected.push_back(i);
        makeCombination(i+1);
        selected.pop_back();
    }
}
void Solve(){
    makeCombination(0);
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1941.txt","rt",stdin);

    Input();
    Solve();

    cout<<res;
    return 0;
}