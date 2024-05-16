/**
 * @file 1654.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1654/랜선자르기
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>

using namespace std;
int K,N; //reference point
long long rp;
vector<int> line;

void input(){
    int temp;
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>temp;
        line.push_back(temp);
        rp+=temp;
    }
    rp/=K;
}
int makeLan(int mid){
    long long cnt=0;
    for(int i=0;i<K;i++){
        cnt+=line[i]/mid;
    }
    if(cnt>=N) return 1; // 자르는 랜선의 길이를 늘려도됨
    else return 0; 
}
void solve(){
    
    long long s=1, e=rp;
    long long mid=(s+e)/2, sub=0;
    while(s<=e){
        int res=makeLan(mid);

        if(res==1){
            s=mid+1; 
            if(sub<mid) sub=mid;
        }
        else e=mid-1;

        mid=(s+e)/2;
    }
    cout<<sub;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1654.txt","rt",stdin);

    input();
    solve();

    return 0;
}