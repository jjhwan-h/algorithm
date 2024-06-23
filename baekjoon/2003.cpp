/**
 * @file 2003.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/2003/수들의합
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
int N,M,res;
vector<int> arr;

void input(){
    int tmp;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
}
void solve(){
    int lp=-1,rp=-1,sub=0;

    while(rp<N){
        if(sub<M) sub+=arr[++rp];
        else if(sub>M) sub-=arr[++lp];
        else{
            res++;
            sub-=arr[++lp];
        }
    }
    while(lp<N){
        if(sub==M) res++;
        sub-=arr[++lp];
    }
    cout<<res;
    return;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("./input_file/2003.txt","rt",stdin);

    input();
    solve();

    return 0;
}