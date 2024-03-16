/*
2023/12/27 백준7569번
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int M,N,H;
int map[200][200][200]={-1};

queue<pair<vector<int>,int> > Que; 

int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int unripe=0; //익지않은 토마토

void FindRipe(){//익은 토마토 찾기
    for(int k=0;k<H;k++){
        for(int j=0;j<N;j++){
            for(int i=0;i<M;i++){
                vector<int>tmp;
                if(map[k][j][i] == 1){
                    tmp.push_back(k);
                    tmp.push_back(j);
                    tmp.push_back(i);
                    Que.push(make_pair(tmp,0));
                }
                else if(map[k][j][i]==0) unripe++;
            }
        }
    }
}
int BFS(){
    int day = 0;
    //if(unripe == M * N * H) return 0;
    while(!Que.empty()){
        pair<vector<int>,int> el = Que.front();
        vector<int> ripe = el.first;
        day = el.second;
        Que.pop();

        for(int i=0;i<6;i++){ //우, 좌, 위, 아래, 상, 하
            int nx = ripe[2] + dx[i];
            int ny = ripe[1] + dy[i];
            int nz = ripe[0] + dz[i];

            if(nx>=0 && nx<M && ny>=0 && ny<N && nz>=0 && nz<H
                &&map[nz][ny][nx] == 0){
                vector<int>tmp;
                map[nz][ny][nx] = 1;
                tmp.push_back(nz);
                tmp.push_back(ny);
                tmp.push_back(nx);
                Que.push(make_pair(tmp,day+1));
                unripe--;
            }
        }
    }
    if(unripe ==0) return day; //모든 토마토가 익은 경우
    else return -1; //모든 토마토가 익거나 익을 수 없는 경우

}

int main(void){
    //freopen("./input_file/7569.txt","rt",stdin);
    cin >> M >> N >> H;
    

    for(int k=0;k<H;k++){ //면
        for(int j=0;j<N;j++){ //행
            for(int i=0;i<M;i++){ //열
                cin>> map[k][j][i];
            }
        }
    }

    FindRipe();
    int day = BFS();

    cout<<day<<endl;

    return 0;
}