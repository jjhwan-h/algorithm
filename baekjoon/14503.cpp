/*
2024/01/09 장정환 14503 로봇청소기
*/

#include<iostream>
#include<vector>

using namespace std;
int N,M,rx,ry,rori;
int map[51][51]={0,}; //청소안된거:0, 벽:1, 청소한거:2
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int cnt;

class robot{
    public : 
        pair<int,int> loc;
        int ori;// 북:0, 동:1, 남:2, 서:3

    robot(int x, int y, int l){
        this->loc.first=x;
        this->loc.second=y;
        this->ori =l;
        
    }
    void Rotate(int i){
        ori = i;
    }
    void Move(){
        switch(ori){
            case 0:{
                loc.first=loc.first+dx[0];
                loc.second=loc.second+dy[0];
                break;
            }
            case 1:{
                loc.first=loc.first+dx[1];
                loc.second=loc.second+dy[1];
                break;
            }
            case 2:{
                loc.first=loc.first+dx[2];
                loc.second=loc.second+dy[2];
                break;
            }
            case 3:{
                loc.first=loc.first+dx[3];
                loc.second=loc.second+dy[3];
                break;
            }
        }
    }
    void Back(){
        loc.first=loc.first-dx[ori];
        loc.second=loc.second-dy[ori];
    }
};
void Input(){
    //freopen("./input_file/14503.txt","rt",stdin);
    cin >> N >> M;
    cin >> ry >> rx >> rori;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
} 

void Clean(robot* r){
    int flag;
    while(1){
        flag=0;
        int x=r->loc.first;
        int y=r->loc.second;
        int orient = r->ori;

        if(map[y][x]==0){
            map[y][x]=2;
            cnt++;
        }
            
        for(int i=0;i<4;i++){ //현재 진행방향 포함 먼저가 아닌, 반시계 방향으로 90도회전 먼저.
            orient= (orient-1<0) ? 3 :orient-1; 
            int nx= x+dx[orient];
            int ny = y+dy[orient];
            int roc = map[ny][nx];
            if(nx >=0 && nx<M && ny >=0 && ny<N
                && map[ny][nx]==0){
                    r->Rotate(orient);
                    r->Move();
                    flag=1;
                    break;
                }
        }
        if (flag ==1 ) continue;
        r->Back();//후진
        x=r->loc.first;
        y=r->loc.second;
        if( x<0 || x>=M || y<0 || y>=N
            || map[y][x]==1) break;
    }
}

int main(void){
    Input();
    robot R(rx,ry,rori);
    Clean(&R);

    cout << cnt;

    return 0;
}