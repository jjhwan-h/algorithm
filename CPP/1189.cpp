/**
 * @file 1189.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1189/컴백홈
 * @version 0.1
 * @date 2024-07-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int R,C,K,res;
vector<int> map[10];
vector<vector<int> > visited(10,vector<int> (10,0));
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void input(){
    string s;
    cin>>R>>C>>K;

    for(int i=0;i<R;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='.') map[i].push_back(0);
            else if(s[j]=='T') map[i].push_back(1);
        }
    }
}
void DFS(int y, int x, int cnt){
    if(cnt>K) return;
    if(y==0 && x==C-1 && cnt==K) {res+=1; return;}

    for(int i=0;i<4;i++){
        int ny=dy[i]+y;
        int nx=dx[i]+x;

        if(ny>=0 && ny<R && nx>=0 && nx<C
            &&!visited[ny][nx] && map[y][x]!=1){
                visited[ny][nx]=1;
                DFS(ny,nx,cnt+1);
                visited[ny][nx]=0;
            }
    }

}
void solve(){
    visited[R-1][0]=1;
    DFS(R-1,0,1);

    cout<<res;
    return ;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1189.txt","rt",stdin);

    input();
    solve();

    return 0;
}