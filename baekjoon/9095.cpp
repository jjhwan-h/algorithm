/**
 * @file 9095.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 1,2,3더하기
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int T,N,cnt;
void DFS(int s){
    if(s==N){
        cnt++;
    }
    else if(s>N) return;

    for(int i=1;i<=3;i++){
        DFS(s+i);
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/9095.txt","rt",stdin);

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        DFS(0);
        cout<<cnt<<"\n";
        cnt=0;
    }
    
    return 0;
}