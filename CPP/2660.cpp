/**
 * @file 2660.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

queue<pair<int,int> > que;
vector<int> member[51];
vector<int> visited(51,0);
vector<int> tmp(51,0);
int N,cnt,minimum=INT32_MAX;

void input(){
    int s,e;
    cin>>N;
    while(1){
        cin>>s>>e;
        if(s==-1 && e==-1) break;
        member[s].push_back(e);
        member[e].push_back(s);
    }
}
int bfs(){
    int round=1;
    while(!que.empty()){
        pair<int,int> idx = que.front();
        que.pop();

        for(int i=0;i<member[idx.first].size();i++){
            int el = member[idx.first][i];
            if(!visited[el]){
                visited[el]=1; cnt++;
                que.push(make_pair(el,idx.second+1));
                if(cnt==N) {round=idx.second+1; break;}
            }
        }
    }
    return round;
}
void getCaptain(){
    vector<int> res;
    for(int i=1;i<=N;i++){
        if(tmp[i]==minimum) res.push_back(i);
    }
    cout<<minimum<<" "<<res.size()<<"\n";
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";

}
void solve(){
    for(int i=1;i<=N;i++){
        visited[i]=1; cnt++;
        for(int j=0;j<member[i].size();j++){
            visited[member[i][j]]=1; cnt++;
            que.push(make_pair(member[i][j],1));
        }
        tmp[i]=bfs();
        minimum = (tmp[i]<minimum) ? tmp[i] : minimum; //회장후보점수
        cnt=0;
        for(int k=0;k<=N;k++) visited[k]=0;
    }
    getCaptain();
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2660.txt","rt",stdin);

    input();
    solve();
    
    return 0;
}