
//사과:5, 왼:2, 오:3
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N,K,L,cnt;
struct el{
    int x,y,move;
};
int visited[101][101]={0,};
std::queue<el> snake;
std::queue<pair<int,int> > apple;
std::queue<pair<int,char> > change_dir;
//위:0, 아래:1, 왼:2, 오:3
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int handle_D[] = {3,2,0,1};
int handle_L[] = {2,3,1,0};

void Input(){
    //freopen("./input_file/3190.txt","rt",stdin);
    cin>>N;
    cin>>K;
    int x,y;
    for(int i=0;i<K;i++){
        cin>>x>>y;
        visited[x][y]=5;
    }
    cin>>L;
    std::pair<int,char> tmp_dir;
    for(int i=0;i<L;i++){
        cin>>tmp_dir.first>>tmp_dir.second;
        change_dir.push(tmp_dir);
        //cout<<tmp_dir.first<<tmp_dir.second<<endl;
    }
}

int Game(){

    while(1){
        cnt++;
        el head = snake.back();
        head.x = head.x + dx[head.move];
        head.y = head.y + dy[head.move];
        if(head.x ==0 || head.x == N+1
            || head.y ==0 || head.y == N+1
            || visited[head.x][head.y] == 1){
                return cnt;
            }

        
        if(visited[head.x][head.y]!=5){
            el tail = snake.front();
            visited[tail.x][tail.y]=0;
            snake.pop();
        }
        visited[head.x][head.y]=1;

        if(!change_dir.empty()){
            pair<int,char> dir = change_dir.front();
            if(dir.first == cnt){

                if(dir.second == 'D'){
                   head.move = handle_D[head.move];
                }
                else if(dir.second == 'L'){
                    head.move = handle_L[head.move];
                }
                change_dir.pop();
            }
        }
        // for(int i=0;i<11;i++){
        //     for(int j=0;j<11;j++){
        //         printf("%d ",visited[i][j]);
        //         }
        //         printf("\n");
        // }
        // printf("\n");
        snake.push(head);
    }
}

int main(void){
    Input();
    el tmp;
    tmp.move=3;
    tmp.x=1;
    tmp.y=1;
    snake.push(tmp);
    visited[1][1]=1;

    int res = Game();
    cout<<res<<endl;
    return 0;
}