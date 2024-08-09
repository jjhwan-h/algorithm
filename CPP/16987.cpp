/**
 * @file 16987.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 계란으로 계란치기(백트래킹))
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
struct el{
    int s; //내구도
    int w; //무게
};
vector<el> vec;
int N,cnt,res;

void input(){
    int s,w;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s>>w;
        vec.push_back(el{s,w});
    }
}
int isNotBroken(int idx){
    if(vec[idx].s<=0) return 0;
    else return 1;
}
void beatEgg(int egg1, int egg2){
    vec[egg1].s -= vec[egg2].w;
    vec[egg2].s -= vec[egg1].w;
    if(vec[egg1].s<=0) cnt++;
    if(vec[egg2].s<=0) cnt++;
}
void initEgg(int egg1, int egg2){
    if(vec[egg1].s<=0) cnt--;
    if(vec[egg2].s<=0) cnt--;
    vec[egg1].s += vec[egg2].w;
    vec[egg2].s += vec[egg1].w;
}
void DFS(int idx){
    if(idx==N){
        if(res<cnt) res=cnt;
        return;
    }
    if(!isNotBroken(idx)) DFS(idx+1);
    else{
        int flag=false;
        for(int i=0;i<N;i++){
            if(idx!=i && isNotBroken(i)){
                flag=true;
                beatEgg(idx,i);
                DFS(idx+1);
                initEgg(idx,i);
            }
        }
        if(!flag) DFS(N);
    }
}
void solve(){
    DFS(0);
    cout<<res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/16987.txt","rt",stdin);
    input();
    solve();

    return 0;
}