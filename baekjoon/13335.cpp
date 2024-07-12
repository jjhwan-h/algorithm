/**
 * @file 13335.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief  BOJ/트럭
 * @version 0.1
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<queue>

using namespace std;

int n,w,l,front,rear,len=0;
queue<int> que;

void input(){
    
    int tmp;
    cin>>n>>w>>l;
    for(int i=0;i<n;i++){
        cin>>tmp;
        que.push(tmp);
    }
}
void solve(){
    int res=0,sum=0;
    queue<int> bridge;
    for(int i=0;i<w;i++){
        bridge.push(0);
    }
    
    while(!que.empty()){
        int bus = bridge.front();
        bridge.pop();
        sum-=bus;
        res++;
        if(sum+que.front()<=l){
            int el = que.front();
            que.pop();
            sum+=el;
            bridge.push(el);
        }else{
            bridge.push(0);
        }
    }
    while(sum!=0){
       int bus = bridge.front();
        bridge.pop();
        sum-=bus;
        res++;
    }

   
    cout<<res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/13335.txt","rt",stdin);

    input();
    solve();

    return 0;
}