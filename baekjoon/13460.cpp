#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>

#define MAX 10 //최대 시행 횟수

using std::cout;
using std::cin;
using std::vector;
using std::queue;
using std::pair;

vector<vector<char> > map(11,vector<char>(11));
queue<pair<int,int> > R_que;
queue<pair<int,int> > B_que;
pair<int,int> goal;
int pre; //이전에 이동해온 방향으로 다시 가지않기위해.
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int cnt; // 시행횟수 카운트
bool res=false;
int visited[10][10][10][10]={0,};

int RorB(){
    int res;
    pair<int,int> R_pos, B_pos;
    R_pos.first = R_que.front().first;
    B_pos.first = B_que.front().first;
    R_pos.second = R_que.front().second;
    B_pos.second = B_que.front().second;
    
    if(R_pos.first==B_pos.first){
        if(R_pos.second>B_pos.second) res=1;
        else res=3;
    }
    else if(R_pos.second==B_pos.second){
        if(R_pos.first>B_pos.first) res=2;
        else res=4;
    }
    else res=-1;
    return res;

}


std::pair<int,int> move_ball(int i,queue<pair<int,int> > *Que){
    pair<int,int> q;
   int nx,ny, tmp1,tmp2;

    // do {
    //     tmp1 = Que->front().first + dx[i];
    //     tmp2 = Que->front().second + dy[i];
    //     if(map[tmp1][tmp2] !='.') break;
    //     nx = tmp1;
    //     ny = tmp2;
    //     if(goal.first==nx && goal.second==ny){
    //         cout<<cnt;
    //         res = true;
    //         return;
    //     }
    // } while (map[nx][ny] == '.');
    

    nx = Que->front().first;
    ny = Que->front().second;
    printf("%d %d\n",Que->front().first,Que->front().second);
    //printf("%d %d\n",B_que.front().first,B_que.front().second);
    while(map[nx+dx[i]][ny+dy[i]]=='.'){
        printf("%c\n",map[nx+dx[i]][ny+dy[i]]);
         nx = nx + dx[i];
        ny = ny + dy[i];
        if(goal.first==nx && goal.second==ny){
            cout<<cnt;
            res = true;
            exit(0);
        }
    }
    //printf("%d %d\n",nx,ny);
    q = std::pair<int,int>(nx,ny);
    return q;
    //Que->push(std::pair<int,int>(nx,ny));
    
}

void Move(){
    int pos; // red 와 blue가 가로나 세로로 한직선 상에 놓여있는지.
    pair<int,int> red, blue;
    while(cnt<MAX){
         pos = RorB();

         for(int i=0;i<4;i++){
            if( (i==0 && pos==2) || (i==1 && pos ==3) || (i==2 && pos==1) || (i==3 && pos ==4) ){
                blue = move_ball(i,&B_que);
                red = move_ball(i,&R_que);
                
            }
            else{
                red = move_ball(i,&R_que);
                blue = move_ball(i,&B_que);
                
            }         
        if(visited[red.first][red.second][blue.first][blue.second]==0){
            visited[red.first][red.second][blue.first][blue.second]=1;
            R_que.push(red);
            B_que.push(blue);
            cnt++;
        }
        else{
            cnt--;
        }
         }
         R_que.pop();
        B_que.pop();
        if(res==true) return;
        
    }
    cout<<-1;
    return;
    
}
void Solve(){
    Move();

}
void Input(){
    int N,M;
    char ip;
    freopen("./input_file/13460.txt","rt",stdin);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>ip;
            map[i][j]=ip;
            if(ip=='R'){
                R_que.push(std::pair<int,int>(i,j));
            }
            else if(ip=='B'){
                B_que.push(std::pair<int,int>(i,j));
            }
        }
    }
    visited[R_que.front().first][R_que.front().second][B_que.front().first][B_que.front().second] = 1;

    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }

}
int main(void){
    Input();
    Solve();

    return 0;

}

