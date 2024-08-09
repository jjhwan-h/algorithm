/*
2023/01/12 장정환 백준 타일 채우기
*/

#include<iostream>

using namespace std;
int dp[31]={0,};

int main(void){
    int N,tmp=0;
    cin>>N;

    if(N==1 || N%2!=0){
        cout<< 0; return 0;
    } 
    else if(N==2) {
        cout<< 3; return 0;
    }
    else{
        dp[2]=3;
        for(int i=4; i<=N; i+=2){
            tmp=0;
            for(int j=4;i-j>=0;j+=2){
                tmp+=dp[i-j];
            }
            dp[i]=dp[i-2]*dp[2] + 2*tmp +2;
        }
    }
    
    cout<<dp[N];

    return 0;
}