/*
2023/01/04 장정환 백준 14502 연구소문제
*/

#include<iostream>
#include<vector>
#include<queue>
#define barrier 3

using namespace std;

int map[9][9]={0,};
int copymap[9][9]={0,};
int N,M,safe_area,cnt,Max;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

vector<pair<int,int> > blank;
queue<pair<int,int> > virus;

void Input(){
    int tmp;
    freopen("./input_file/14502.txt","rt",stdin);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmp;
            map[i][j]=tmp;
            copymap[i][j]=tmp;
            if(tmp==0) 
                blank.push_back(make_pair(i,j));
            else if(tmp==2) 
                virus.push(make_pair(i,j));
        }
    }
   
    safe_area=blank.size()-barrier;
    
}
void Init(){
    for(int i=0; i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]!=1) map[i][j]=copymap[i][j];
            if(map[i][j]==2) virus.push(make_pair(i,j));
        }
    }
    safe_area=blank.size()-barrier;
}
void BFS(){
    while(!virus.empty()){
        pair<int,int> crdnt = virus.front();
        virus.pop();

        for(int i=0;i<4;i++){
            int nx = crdnt.second + dx[i];
            int ny = crdnt.first + dy[i];
            if(nx>=0 && nx<M && ny>=0 && ny<N
                && map[ny][nx]==0){
                    map[ny][nx]=2;
                    virus.push(make_pair(ny,nx));
                    safe_area--;
                    //cout<<safe_area<<endl;
                }
        }
    }
    
}
void DFS(int n){
    if(cnt>=barrier){
        BFS(); //장벽 선택 후 virus BFS
        if(Max<safe_area) Max=safe_area;  //안전 영역 크기 비교
        Init(); //값들 초기화
        return;
    }
    for(int i=n+1;i<blank.size();i++){
        map[blank[i].first][blank[i].second] = 1;
        cnt++;
        DFS(i);
        map[blank[i].first][blank[i].second] = 0;
        cnt--;
    }
}
void SetBarrier(){ //장벽 선택
    for(int i=0;i<blank.size();i++){
        map[blank[i].first][blank[i].second] = 1;
        cnt++;
        DFS(i);
        map[blank[i].first][blank[i].second] = 0;
        cnt--;
    }
}

int main(void){
    Input();
    SetBarrier();
    
    BFS();

    cout<<Max;
    return 0;
    
}