/**
 * @file 15683.cpp
 * @author jangjenoghwan
 * @brief 백준 15683 감시
 * @version 0.1
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int dx[4] = {0, -1, 0, 1}; 
int dy[4] = {1, 0, -1, 0};
int map[9][9]={0,};
int N,M,Min=INT32_MAX;

class CCTV{
    public:
    int x;
    int y;
    int ori;
    CCTV(int x,int y){
        this->x=x; this->y=y;
        this->ori=-1;
    }
    void Rotate(){
        ori = (ori+1)%4;
    };
    void CheckBlind(int i){
        int nOri=(ori+i)%4;
        int nx=x+dx[nOri]; int ny=y+dy[nOri];
        while(nx>=0 && nx<M && ny>=0 && ny<N && map[ny][nx]!=6){
            if(map[ny][nx]!=-1 && map[ny][nx]==0){
                map[ny][nx]=-1;
            }
            nx+=dx[nOri]; ny+=dy[nOri];
        }
    };
};

vector<CCTV*> cctv;

void initMap(vector<vector<int> > &tmp){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j]=tmp[i][j];
        }
    }
}
void refMap(vector<vector<int> > &tmp){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmp[i][j]=map[i][j];
        }
    }
}

int getRes(){
    int res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0) res++;
        }
    }
    return res;
}
void DFS(int i){
    vector<vector<int> >tmp(N,vector<int>(M));
    if(i==cctv.size()){
        int res=getRes();
        if(Min>res) Min=res;
        return;
    }
    refMap(tmp);
    for(int j=0;j<4;j++){
        if(map[cctv[i]->y][cctv[i]->x]==1){
            cctv[i]->Rotate();
            cctv[i]->CheckBlind(0);
        }
        else if(map[cctv[i]->y][cctv[i]->x]==2){
            cctv[i]->Rotate();
            cctv[i]->CheckBlind(0);
            cctv[i]->CheckBlind(2);
        }
        else if(map[cctv[i]->y][cctv[i]->x]==3){
            cctv[i]->Rotate();
            cctv[i]->CheckBlind(0);
            cctv[i]->CheckBlind(1);
        }
        else if(map[cctv[i]->y][cctv[i]->x]==4){
            cctv[i]->Rotate();
            cctv[i]->CheckBlind(0);
            cctv[i]->CheckBlind(1);
            cctv[i]->CheckBlind(2);
        }
        else if(map[cctv[i]->y][cctv[i]->x]==5){
            cctv[i]->Rotate();
            cctv[i]->CheckBlind(0);
            cctv[i]->CheckBlind(1);
            cctv[i]->CheckBlind(2);
            cctv[i]->CheckBlind(3);
        }
        DFS(i+1);
        
        initMap(tmp);
    }
}

void Input(){
    cin >>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]!=0 && map[i][j]!=6) cctv.push_back(new CCTV(j,i));
        }
    }
}

int main(void){
    freopen("./input_file/15683.txt","rt",stdin);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    Input();
    DFS(0);

    cout<<Min;

    return 0;
}

// for(int k=0;k<N;k++){
//     for(int z=0;z<M;z++){
//         cout<<map[k][z]<<" ";
//     }
//     cout<<"\n";
// }