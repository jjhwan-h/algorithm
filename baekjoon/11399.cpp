/**
 * @file 11399.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/ATM/11399
 * @version 0.1
 * @date 2024-05-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<int> people;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/11399.txt","rt",stdin);
    
    int tmp=0,acc=0,res=0;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        people.push_back(tmp);
    }
    sort(people.begin(),people.end());

    for(int i=0;i<N;i++){
        acc+=people[i];
        res+=acc;
    }
    cout<<res;

    return 0;
}