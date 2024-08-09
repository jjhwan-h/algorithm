/**
 * @file 2531.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/2531
 * @version 0.1
 * @date 2024-07-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

vector<int> arr(60001,0);
bool flag=false;
int N,d,k,c;

void input(){
    int tmp;
    cin>>N>>d>>k>>c;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr[i]=tmp;
        arr[i+N]=tmp;
    }
}

void solve(){
    int cnt=0,max=0;
    vector<int> sushi(d+1,0);
    for(int i=0;i<k;i++){
        if(!sushi[arr[i]]) cnt++;
        sushi[arr[i]]+=1;
    }
    if(!sushi[c]) cnt++;
    sushi[c]+=1;
    max=cnt;
    for(int i=k;i<N*2;i++){
        if(sushi[arr[i-k]]==1) cnt--;
        sushi[arr[i-k]]-=1;

        if(!sushi[arr[i]]) cnt++;
        sushi[arr[i]]+=1;
        
        max = (max>cnt) ? max : cnt;
    }
    cout<<max;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2531.txt","rt",stdin);

    input();
    solve();

    return 0;
}