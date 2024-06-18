/**
 * @file 10815.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/10815/숫자 카드
 * @version 0.1
 * @date 2024-06-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v1;
vector<int> v2;
int N,M;

void input(){
    int tmp;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        v1.push_back(tmp);
    }

    cin>>M;
    for(int i=0;i<M;i++){
        cin>>tmp;
        v2.push_back(tmp);
    }
}
bool binarySearch(int s, int e, int target){
    bool flag = false;

    if(s<=e){
        int m=(s+e)/2;

        if(v1[m]==target) flag=true;
        else if(v1[m]>target){
            flag =binarySearch(s,m-1,target);
        }
        else{
            flag =binarySearch(m+1,e,target);
        }
    }
    return flag;
}
void solve(){
    sort(v1.begin(),v1.end());
    for(int i=0;i<M;i++){
        if(binarySearch(0,N-1,v2[i])) cout<<"1 ";
        else cout<<"0 ";
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/10815.txt","rt",stdin);

    input();
    solve();

    return 0;
}