#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//처음 풀때 실수
/*
    1. 현재의 주사위 상태로 관리하는게 아닌 주사위의 기준면이 북족을 바라보며 항상 일정하다는 가정하에 풀었다.
        이로인해 주사위를 굴릴때 굴려진 주사위 형태가 반영되지 않고 굴린다음 기준면이 항상 북쪽을 바라보도록 회전하는 코드로 짜여짐.

*/
class dice{
    private:
        vector<int> pos; // 주사위눈 값 기록
    public:
        dice(){
            vector<int> init(6,0);
            pos.insert(pos.end(),init.begin(),init.end()); // 처음 모든 주사위의 눈은 0
        }
        void east(); //동족으로 이동
        void west(); //서쪽으로 이동
        void north(); //북쪽으로 이동
        void south(); //남쪽으로 이동
        void print_pos(); //주사위 출력
        void set_bottom(int num); //지도위의 값 주사위 밑면에 할당
        int get_bottom();   // 주사위 밑면 값 리턴
        int get_upper();    // 주사위 윗면 값 리턴
};
int dice:: get_bottom(){
    return pos[0];
}
void dice:: set_bottom(int num){
    pos[0] = num;
}
int dice:: get_upper(){
    return pos[5];
}
void dice::print_pos(){
    for(int i=0;i<pos.size();i++){
        cout<< pos[i] <<" ";
    }
    cout<<"\n";
}
void dice::east(){
    int tmp;
    tmp = pos[1];
    pos[1] = pos[5];
    pos[5] = pos[2];
    pos[2] = pos[0];
    pos[0] = tmp;
}
void dice::west(){
    int tmp;
    tmp = pos[2];
    pos[2] = pos[5];
    pos[5]= pos[1];
    pos[1] = pos[0];
    pos[0] = tmp;
}
void dice::south(){
    int tmp;
    tmp = pos[3];
    pos[3] = pos[0];
    pos[0] = pos[4];
    pos[4] = pos[5];
    pos[5] = tmp;  
}
void dice::north(){
    int tmp;
    tmp = pos[3];
    pos[3] = pos[5];
    pos[5] = pos[4];
    pos[4] = pos[0];
    pos[0] = tmp;
}
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
vector<vector<int> > map;
int N,M,x,y,K;

void Input(){
    //freopen("./input_file/14499.txt","rt",stdin);
    // scanf("%d %d %d %d %d",&N,&M,&x,&y,&K);
    cin>>N>>M>>x>>y>>K;
    vector<int> tmp(M,0);
    for(int i=0;i<N;i++){
        for(int j=0; j<M; j++) cin>>tmp[j];
        map.push_back(tmp);
    }
}
void Solve(){
    int tmp;
    dice dice;
    
    for(int i=0;i<K;i++){
        cin>>tmp;
        x += dx[tmp];
        y += dy[tmp];
        if(x>=N || y>=M || x < 0 || y < 0) {
            x -= dx[tmp];
            y -= dy[tmp];
            continue;
        }
        switch(tmp){
            case 1:
                dice.east();
                break;
            case 2:
                dice.west();
                break;
            case 3:
                dice.north();
                break;
            case 4:
                dice.south();
                break;
            default:
                cout<<"잘못된 입력입니댜";
                break;
        }
        if(map[x][y]==0){
            map[x][y]=dice.get_bottom();
        }
        else{
            dice.set_bottom(map[x][y]);
            map[x][y]=0;
        }
        
        // dice.print_pos();
        // cout<<"dicebottom:"<<dice.get_bottom()<<endl;
        printf("%d\n",dice.get_upper());

    }
}
int main(void){
    Input();
    Solve();

    return 0;
}