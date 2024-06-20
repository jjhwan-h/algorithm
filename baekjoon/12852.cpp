/**
 * @file 12852.cpp
 * @author jang jeong hwan (you@domain.com)
 * @brief BOJ/12852/1로 만들기 2
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> vec(1000000,0);

int main(void){
    int a,b,c;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("./input_file/12852.txt","rt",stdin);
    cin>>N;
    int idx=N;

    for(int i = 2; i <= N; ++i) {
        vec[i] = vec[i-1] + 1;
        if(i % 2 == 0) vec[i] = min(vec[i], vec[i/2] + 1);
        if(i % 3 == 0) vec[i] = min(vec[i], vec[i/3] + 1);
    }
    cout<<vec[N]<<"\n";
    cout<<N<<" ";
    while(idx>1){
        a=idx/2; b=idx/3;
        
        if(idx%3==0 && vec[b]==vec[idx]-1) {cout<<b<<" "; idx=b;}
        else if(idx%2==0 && vec[a]==vec[idx]-1) {cout<<a<<" "; idx=a;}
        else {cout<<idx-1<<" "; idx=idx-1;}
    }

    return 0;
}