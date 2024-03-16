#include<iostream>
#include<vector>
#include<queue>

#define MAX 10 //최대 시행 횟수

using std::cout;
using std::cin;
using std::vector;
using std::queue;
using std::pair;

vector<vector<char> > map(10,vector<char>(10));
queue<pair<int,int> > R_que;
queue<pair<int,int> > B_que;
pair<int,int> goal;
int pre; //이전에 이동해온 방향으로 다시 가지않기위해.
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int cnt; // 시행횟수 카운트
bool res=false;

int RorB(){
    int res;
    pair<int,int> R_pos, B_pos;
    R_pos.first = R_que.front().first;
    B_pos.first = B_que.front().first;
    R_pos.second = R_que.front().second;
    B_pos.second = B_que.front().second;
    
    if(R_pos.first==B_pos.first){
        if(R_pos.first>B_pos.first) res=4;
        else res=2;
    }
    else if(R_pos.second==B_pos.second){
        if(R_pos.second>B_pos.second) res=1;
        else res=3;
    }
    return res;
}


void move_ball(int i,queue<pair<int,int> > *Que){
   int nx,ny;

    do {
        nx = Que->front().first + dx[i];
        ny = Que->front().second + dy[i];
        if(goal.first==nx && goal.second==ny){
            cout<<cnt;
            res = true;
            return;
        }
    } while (map[nx][ny] == '.');
    Que->pop();
    Que->push(pair(nx-dx[i],ny-dy[i]));
    
}

void Move(){
    int pos; // red 와 blue가 가로나 세로로 한직선 상에 놓여있는지.
    
    while(cnt<MAX || R_que.empty()){
         pos = RorB();

         for(int i=0;i<4;i++){

            if( (i==0 && pos==2) || (i==1 && pos ==3) || (i==2 && pos==1) || (i==3 && pos ==4) ){
                move_ball(i,&B_que);
                move_ball(i,&R_que);
            }
           move_ball(i,&R_que);
           move_ball(i,&B_que);
         }
        if(res==true) return;
        cnt++;
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
            if(ip=='0'){
                goal.first=i;
                goal.second=j;
            }
            else if(ip=='R'){
                R_que.push(pair(i,j));
            }
            else if(ip=='B'){
                B_que.push(pair(i,j));
            }
        }
    }
}
int main(void){
    Input();
    Solve();

    return 0;

}

