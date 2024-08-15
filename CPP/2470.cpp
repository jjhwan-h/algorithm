/**
 * @file 2470.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/2470/두 용액
 * @version 0.1
 * @date 2024-08-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int N,f,s,MAX=2147000000;
map<int,int> liquid;

void input(){
    int a,b;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a;
        if(liquid[abs(a)]) {
            if(liquid[abs(a)] < a) {
                f = liquid[abs(a)];
                s = a;
            }else{
                s = liquid[abs(a)];
                f = a;
            }
            MAX=0;
        }
        liquid[abs(a)]=a;
    }
}

void solve(){
    map<int,int,greater<int> > :: iterator it;
    it=liquid.begin();
    for(it=++it; it!=liquid.end(); it++){
        auto prev_it = it;
        --prev_it;
        int absSum = abs(it->second + prev_it->second);
        if( absSum < MAX){
            MAX = absSum;
            if(prev_it->second < it->second){
                f=prev_it->second;
                s=it->second;
            }else{
                s=prev_it->second;
                f=it->second;
            }
        }
    }
    cout<<f<<" "<<s;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2470.txt","rt",stdin);

    input();
    solve();

    return 0;
}   
