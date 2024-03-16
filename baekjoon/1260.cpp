#include<iostream>
#include<queue>
#include<algorithm>

#define MAX 1001

using namespace std;

int visited[MAX]={0,};
int map[MAX][MAX]={0,};
int N,M,V;
queue<int> que;

void initialize(){
    for(int i=1;i<=N;i++){
        visited[i]=0;
    }
}
void DFS(int s){
    visited[s]=1;
    cout<<s<<" ";
    for(int i=1;i<=N;i++){
        if(map[s][i]==1 && visited[i]!=1){
            DFS(i);
        }
    }
}
void BFS(int s){
    que.push(s);
    visited[s]=1;
    while(!que.empty()){
        int start = que.front();
        que.pop();
        cout<<start<<" ";
        for(int i=1;i<=N;i++){
            if(map[start][i]==1 && visited[i]!=1){
                que.push(i);
                visited[i]=1;
            }
        }
        
    }
}

int main(void){
    int s,e;
    //freopen("./input_file/1260.txt","rt",stdin);
    cin>>N>>M>>V;
    
    for(int i=0;i<M;i++){
        cin>>s>>e;
        map[s][e]=1;
        map[e][s]=1;
    }
    DFS(V);
    initialize();
    cout<<"\n";
    BFS(V);

    return 0;
}
