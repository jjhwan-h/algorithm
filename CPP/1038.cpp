/**
 * @file 1038.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1038/감소하는 수
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<queue>

using namespace std;

void solve(){
    int N,cnt=0;
    queue<long long> que;

    cin>>N;

    if (N>1022){
        cout<<-1<<endl;
        return;
    }else if (0<=N && N<10){
        cout<<N<<endl;
        return;
    }else{
        for(int i=0;i<10;i++){
            que.push(i);
        }
        cnt=9;
        while (!que.empty()){
            long long el = que.front();
            que.pop();
            int remain = el%10;
            long long tmp = el*10;
            for(int j=0;j<remain;j++){
                cnt++;
                if (cnt==N){
                    cout<<tmp+j<<endl;
                    return;
                }
                que.push(tmp+j);
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}