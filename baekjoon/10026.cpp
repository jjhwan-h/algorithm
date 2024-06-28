/**
 * @file 10026.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/10026/적록색약
 * @version 0.1
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
queue<pair<int,int> > que;
vector<int> map[101];
vector<int> blindMap[101];
int N;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void input(){
    char color;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>color;
            if(color=='R'){
                map[i].push_back(0);
                blindMap[i].push_back(0);
            }else if(color=='G'){
                map[i].push_back(1);
                blindMap[i].push_back(0);
            }else if(color=='B'){
                map[i].push_back(2);
                blindMap[i].push_back(1);
            }
        }
    }
}
void numOfArea(vector<int> (&map)[101]){
    int cnt=0;
    vector<vector<int> > visited(101,vector<int> (101,0));
    for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
            if(!visited[j][k]){
                cnt++;
                que.push(make_pair(j,k));
                while(!que.empty()){
                    pair<int,int> el = que.front();
                    que.pop();
                    for(int i=0;i<4;i++){
                        int nx= el.second+dx[i];
                        int ny= el.first+dy[i];
                        if(nx>=0&&nx<N && ny>=0&&ny<N
                            && !visited[ny][nx] && map[el.first][el.second] == map[ny][nx] ){
                                visited[ny][nx]=1;
                                que.push(make_pair(ny,nx));
                            }
                    }
                }
            }
        }
    }
    cout<<cnt<<" ";
}
void solve(){
    numOfArea(map);
    numOfArea(blindMap);
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/10026.txt","rt",stdin);

    input();
    solve();

    return 0;
}