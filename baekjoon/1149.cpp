/**
 * @file 1149.cpp (백준)
 * @author jang jeonghwan (you@domain.com)
 * @brief RGB거리(다이나믹 프로그래밍)
 * @version 0.1
 * @date 2024-02-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
vector<int> R,G,B;
int map[1001][3];
int N;

void Input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin>>map[i][j];
        }
    }
    /*첫번째집의 경우는 먼저 input해준다.*/
    R.push_back(map[0][0]);
    G.push_back(map[0][1]);
    B.push_back(map[0][2]);
}
//현재 집의 색깔과 일치하지 않는 이전의 집 중 최소비용을 가진집과 현재 집의 비용을 더해 dp업데이트.
void setMin(int color,int idx,int c1, int c2){ 
    int tmp = (c1>c2) ? c2 : c1;
    if(color==0) R.push_back(tmp+map[idx][color]);
    else if(color==1) G.push_back(tmp+map[idx][color]);
    else B.push_back(tmp+map[idx][color]);
}
//N개의 집을 탐색하며 dp 업데이트
void Solve(){
    for(int i=1;i<N+1;i++){
        for(int j=0;j<3;j++){
            if(j==0) setMin(0,i,G[i-1],B[i-1]);
            else if(j==1) setMin(1,i,R[i-1],B[i-1]);
            else if(j==2) setMin(2,i,R[i-1],G[i-1]);
        }
    }
}
//최종적으로 업데이트된 R,G,B의 dp값 중 가장작은 것을 선택
int getMin(){
    int tmp = (R[N-1]>G[N-1]) ? G[N-1] : R[N-1];
    int res = (B[N-1]>tmp) ? tmp: B[N-1];
    return res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1149.txt","rt",stdin);

    Input();
    Solve();
    
    cout<<getMin();

    return 0;
}