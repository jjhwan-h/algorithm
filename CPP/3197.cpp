
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

queue<pair<int,int>> swan, n_swan, water, n_water;
vector<vector<char>> lake;
bool visit[1500][1500];
vector<char> tmp;
vector<pair<int,int>> swan_pos;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool isFind=false;
int R,C;
int Day;



void BFS_Swan(){
    int x,y,nx,ny;
    int a,b;
    while(!swan.empty()){
        x = swan.front().first;
        y = swan.front().second;
        swan.pop();
        for(int i=0;i<4;i++){
                a=Day;
                nx = x+dx[i];
                ny = y+dy[i];
                if(nx>=0 && nx<R && ny>=0 && ny<C){
                    if(visit[nx][ny]==false){
                        if(lake[nx][ny]=='X'){
                            n_swan.push(pair(nx,ny));
                            visit[nx][ny]=true;
                        }
                        else if(lake[nx][ny]=='.'){
                            swan.push(pair(nx,ny));
                            visit[nx][ny]=true;
                        }
                        else if(lake[nx][ny]=='L'){
                            isFind=true;
                            break;
                        }
                    }
                }
        }
    }
}

void BFS_Water(){
    int x,y,nx,ny;

    while(!water.empty()){
        x = water.front().first;
        y = water.front().second;
        water.pop();
        for(int i=0; i<4; i++){
            
            nx = x+dx[i];
            ny = y+dy[i];

            if(nx>=0 && nx<R && ny>=0 && ny<C){
                if(lake[nx][ny]=='X'){
                    lake[nx][ny]='.';
                    n_water.push(pair(nx,ny));
                    
                }
            }
        }
    }
}

void Input(){
    char input;
    int x,y;
    freopen("./input_file/3197","rt",stdin);
    cin>>R>>C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input;
            tmp.push_back(input);
            if(input != 'X'){
                water.push(pair(i,j));
            }
            if(input == 'L'){
                swan_pos.push_back(pair(i,j));
            }
            visit[i][j]=false;
        }
        lake.push_back(tmp);
        
        tmp.clear();
    }
}

void Solve(){
    int x,y;
    swan.push(pair(swan_pos[0].first,swan_pos[0].second));
    visit[swan_pos[0].first][swan_pos[0].second]=true;
    while(!isFind){
        BFS_Swan();
        if(isFind) break;
        BFS_Water();
        swan = n_swan;
        water = n_water;
        
        while(!n_water.empty()){n_water.pop();}
        while(!n_swan.empty()){n_swan.pop();}        

        Day++;
    }
    cout<<Day;
}

int main(void){
    Input();
    Solve();

    return 0;
}