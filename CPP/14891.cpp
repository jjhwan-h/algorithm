/*
2024/1/22 장정환 백준 14891번
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Cog{ //톱니바퀴
    int tooth[8];
    int r;
};
vector<Cog> map(5);
Cog a, b, c, d;
int N;
void Turn(int ch, int dir, int ori ){ //회전 (회전반영x)
    if(dir==0 || ch==0 || ch==5) return; // 회전x || 가장자리 톱니바퀴인 경우
    if(ori==0){//이전 바퀴에 대해 왼쪽 바퀴
        if(map[ch].tooth[2]==map[ch+1].tooth[6]) 
            Turn(ch-1,0,0);
        else {
            if(dir==1)  map[ch].r-=1;
            else        map[ch].r+=1;   
            Turn(ch-1,-dir,0);
        }
    }
    else{// 이전 바퀴에 대해 오른쪽 바퀴
        if(map[ch].tooth[6]==map[ch-1].tooth[2]) 
            Turn(ch+1,0,1);
        else {
            if(dir==1)  map[ch].r-=1;
            else        map[ch].r+=1;   
            Turn(ch+1,-dir,1);
        }
    }

}
void Present(){
    int jump,start;
    
    for(int i=1;i<=4;i++){
        vector<int>arr(8,0);
        jump=map[i].r; // 회전 정도
        start=abs(jump)%8;

        if(jump<0)//반시계회전 인경우
            start=8-start;

        for(int j=0;j<8;j++){
            arr[start%8]=map[i].tooth[j];
            start++;
        }
        for(int j=0;j<8;j++){
            map[i].tooth[j]=arr[j];
        }
        map[i].r=0;
    }
}

void Input(){
    /*
        choice=>톱니번호(1,2,3,4)
        dir=>톱니회전방향(시계:1,반시계:-1,x:0)
        ori=>이전 톱니바퀴에 대해서 현재 톱니바퀴 위치 좌(0)/우(1)
    */
    int choice, dir, ori; 
    string tmp;
    for(int i=1;i<=4;i++){
        cin>>tmp;
        for(int j=0;j<8;j++){
            map[i].tooth[j]=tmp[j]-48; //문자형 숫자를 정수형으로
        }
    }
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>choice >> dir;
        map[choice].r=dir;
        Turn(choice-1,dir,0);
        Turn(choice+1,dir,1);
        Present();
    }
}
int Res(){ //점수산출
    int res=0,s=1;
    for(int i=1;i<=4;i++){
        if(map[i].tooth[0]==1) res+=s;
        s*=2;
    }
    return res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/14891.txt","rt",stdin);

    a.r=0;  b.r=0;  c.r=0;  d.r=0;
    map[1]=a; map[2]=b; map[3]=c; map[4]=d;
    Input();
    cout<< Res();

    return 0;
}