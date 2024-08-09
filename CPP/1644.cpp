/**
 * @file 1644.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 소수의 연속합
 * @version 0.1
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
int N;
vector<int> prime;
void Input(){
    cin>>N;
}
void findPrime(){
    bool flag=false;
    for(int i=2;i<=N;i++)
    {   
        flag=false;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){ flag=true; break;}
        }
        if(!flag) prime.push_back(i);
    }
}
int countSumPrime(){
    int lp=0, rp=0, sum=0, res=0;
    while(rp<=prime.size()-1){
        if(sum<N) sum+=prime[rp++];
        else if(sum>N) sum-=prime[lp++];
        else if(sum==N) {res++; sum+=prime[rp++];}
    }
    while(lp<=prime.size()-1){
        sum-=prime[lp++];
        if(sum==N) res++;
    }
    return res;
}
void Solve(){
    findPrime();
    int res = countSumPrime();
    cout<<res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1644.txt","rt",stdin);

    Input();
    if(N==1){cout<<0; return 0;}
    else if(N==2){cout<<1; return 0;}
    Solve();

    return 0;
}