/**
 * @file 6588.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/골드바흐의 추측
 * @version 0.1
 * @date 2024-07-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;
vector<int> prime(1000000);

void calPrime(){
    prime[2]=1;
    prime[3]=1;
    for(int i=4;i<=1000000;i++){
        bool flag=false;
        for(int j=2;j*j<=i;j++){
            if(i%j==0) {flag=true; break;}
        }
        if(!flag) prime[i]=1;
        else prime[i]=0;
    }
}

void solve(){
    int n;
    calPrime();
    while(true){
        int pre=0,post=0;
        cin>>n;
        if(n==0) break;
        
        for(int i=3;i<=n/2;i+=2){
            if(prime[i]&&prime[n-i]) {
                pre=i;
                post=n-i;
                break;
            }
        }
        if(pre && post){
            cout<<n<<" = "<<pre<<" + "<<post<<"\n";
        }else{
            cout<<"Goldbach's conjecture is wrong."<<"\n";
        }
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/6588.txt","rt",stdin);

    solve();

    return 0;
}