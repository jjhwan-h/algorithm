/**
 * @file 2217.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> arr;
int N,Max;

bool compare(int i, int j){return i>j;}
void Input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
}
void Solve(){
    int tmp;
    for(int i=0;i<N;i++){
        tmp = arr[i]*(i+1);
        if(Max<tmp) Max =tmp;
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2217.txt","rt",stdin);

    Input();
    sort(arr.begin(),arr.end(),compare);
    Solve();

    cout<<Max;

    return 0;
}
