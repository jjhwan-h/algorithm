/**
 * @file 15685.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 드래곤커브(구현, 삼성sw역량테스트기출)
 * @version 0.1
 * @date 2024-03-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#define X_SIZE 101
#define Y_SIZE 101
using namespace std;
int map[Y_SIZE][X_SIZE]={0,};
//우,상,좌,하
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int N,cnt;
struct el{
    int x;
    int y;
    int d;
    int g;
};

el Input(){
    int x,y,d,g;
    el el;
    cin>>el.x>>el.y>>el.d>>el.g;
    return el;
}
void draw(el el, vector<int> &v){
    int x=el.x;
    int y=el.y;
    for(int i=0;i<v.size();i++){
        map[y][x]=1;
        x= x+dx[v[i]];
        y = y+dy[v[i]];
    }
    map[y][x]=1;
}
void Dragon(el el){
    int d = el.d;
    int g = el.g;
    vector<int> dir;
    dir.push_back(d);

    while(g--){
        for(int i=dir.size()-1;i>=0;i--){
            if(dir[i]==0) dir.push_back(1);
            else if(dir[i]==1) dir.push_back(2);
            else if(dir[i]==2) dir.push_back(3);
            else if(dir[i]==3) dir.push_back(0);
        }
    }
    draw(el,dir);
}
void CountBox(){
    for(int i=0;i<Y_SIZE-1;i++){
        for(int j=0;j<X_SIZE-1;j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
                cnt++;
        }
    }
}
void Solve(){
    cin>> N;
    while(N--){
        el el= Input();
        Dragon(el);
    }
    CountBox();
    cout<<cnt;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/15685.txt","r",stdin);
    Solve();

    // for(int i=0;i<Y_SIZE;i++){
    //     for(int j=0;j<X_SIZE;j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<"\n"; 
    // }
    return 0;
    
}