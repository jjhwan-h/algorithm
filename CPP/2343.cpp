/**
 * @file 2343.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/2343/기타 레슨
 * @version 0.1
 * @date 2024-07-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

int N,M,l,r,mid;
vector<int> arr;
void input(){
    int tmp;
    cin>>N>>M;

    for(int i=0;i<N;i++){
        cin>>tmp;
        if(l<tmp) l = tmp;
        r+=tmp;
        arr.push_back(tmp);
    }
}

void solve(){

    while(l<=r){
        int sum=0,cnt=1;
        mid=(l+r)/2;

        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(sum>mid){
                sum=0;
                i--;
                cnt++;
            }
        }
        
        if(cnt>M) l=mid+1;
        else r=mid-1;
    }

    cout<<l;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2343.txt","rt",stdin);

    input();
    solve();

    return 0;
}