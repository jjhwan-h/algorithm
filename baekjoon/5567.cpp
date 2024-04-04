/**
 * @file 5567.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 결혼식(DFS)
 * @version 0.1
 * @date 2024-04-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#define MAX 501
using namespace std;

vector<int> list[MAX];
int visited[MAX]={0,};
int N,M,res;

void Input(){
    int n1,n2;
    cin>>N;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>n1>>n2;
        list[n1].push_back(n2);
        list[n2].push_back(n1);
    }
}
void DFS(int s, int dep){
    if(dep==2) return;
    
    for(int i=0;i<list[s].size();i++){
        if(!visited[list[s][i]]){
            visited[list[s][i]] = 1;
            DFS(list[s][i],dep+1);
        }
   }
}
void Solve(){
    int res=0;
    visited[1]=1;
    for(int i=0;i<list[1].size();i++){
            visited[list[1][i]] = 1;
            DFS(list[1][i],1);
    }
    for(int i=0;i<=N;i++) {
        if(visited[i]==1) res++;
    }

    cout<<--res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/5567.txt","rt",stdin);

    Input();
    Solve();
    
    return 0;
}