/**
 * @file 11403.cpp
 * @author jang jeong hwan (you@domain.com)
 * @brief 백준 11403 경로찾기
 * @version 0.1
 * @date 2024-05-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>

using namespace std;
int visited[101]={0,};
vector<int> map[101];
int N,res;

void input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>tmp;
            if(tmp==1) map[i].push_back(j);
        }
    }
}

void dfs(int cur){
    for(int i=0;i<map[cur].size();i++){
        int idx = map[cur][i];
        if(!visited[idx]) {
            visited[idx]=1;
            dfs(idx);
        }
    }
}
void solve(){
    for(int i=0;i<N;i++){
        dfs(i);
        for(int j=0;j<N;j++) {
            cout<<visited[j]<<" ";
            visited[j]=0;
        }
        cout<<"\n";
    }
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/11403.txt","rt",stdin);

    input();
    solve();

    return 0;
}