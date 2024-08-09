/**
 * @file 1439.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1439/뒤집기
 * @version 0.1
 * @date 2024-07-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    int idx=0,cnt=0,tmp=-1;
    string s;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1439.txt","rt",stdin);

    vector<int> arr;

    cin>>s;
    while(idx<s.length()){
        arr.push_back(s[idx]-48);
        idx++;
    }

    int start = arr[0];

    for(int i=1;i<arr.size();i++){
        if(arr[i]!=start && arr[i]!=tmp) cnt++;
        tmp=arr[i];
    }
    
    cout<<cnt;

    return 0;
}