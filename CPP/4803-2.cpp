/**
 * @file 4803.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 트리
 * @version 0.1
 * @date 2024-02-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M,tree;


bool noTree=false;

int Find(int a, vector<int> &unf){
    if(a == unf[a]) return a;
    return unf[a] = Find(unf[a],unf);
}
void Union(int a, int b, vector<int> &unf){
    a = Find(a,unf);
    b = Find(b,unf);
    if(a!=b) unf[a]=b;
}

void Input(vector<int> (&Graph)[]){
    int s,e;
    tree=0;
   for(int i=0;i<M;i++){
        cin>>s>>e;
        Graph[s].push_back(e);
        Graph[e].push_back(s);
   }
}
void BFS(int root,vector<vector<int> > &visited,vector<int> &unf, vector<int> (&Graph)[]){
    
    queue<int> Que;
    Que.push(root);
    visited[root][0]=1;
    while(!Que.empty()){
        int vertex = Que.front();
        Que.pop();
        for(auto el : Graph[vertex]){
            
            //if(visited[el][vertex]) continue;
            
            int a = Find(vertex,unf);
            int b = Find(el,unf);
            if(a==b){
                noTree=true;
                continue;
            } 
            else{
                Que.push(el);
                visited[el][0]=1;
                visited[vertex][el]=1;
                Union(vertex,el,unf);
            }
        }

    }
}
int main(void){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/4803.txt","rt",stdin);
    
    int t_case=1;
    cin>>N>>M;
    while(N!=0 || M!=0){
        vector<int>Graph[501];
    
        Input(Graph);
        vector<vector<int> > visited(N+1,vector<int>(N+1,0));
        vector<int> unf(N+1);
        for(int i=1;i<=N+1;i++) unf[i]=i;

        for(int i=1;i<=N;i++){
            if(visited[i][0]) continue;
            noTree=false;
            BFS(i,visited,unf,Graph);
            if(!noTree) 
                {tree++;}
        }
        
        cout<<"Case "<<t_case;
        if(tree==0) cout<<": No trees.\n";
        else if(tree==1) cout<<": There is one tree.\n";
        else cout<<": A forest of "<<tree<<"trees.\n";
        t_case++;
        cin>>N>>M;
    }

    return 0;
}