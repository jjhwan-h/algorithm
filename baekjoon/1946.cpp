/**
 * @file 1946.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1946/신입사원
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int T,N;

void input(vector<pair<int,int> > &vec){
    int a,b;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
    }
}
void solve(){
    cin>>T;
    for(int i=0;i<T;i++){
        int res=1;
        vector<pair<int,int> > vec;
        input(vec);
        sort(vec.begin(),vec.end());
        int min=vec[0].second;
        for(int j=1;j<N;j++){
            if(min>vec[j].second) {
                res++;
                min=vec[j].second;
            }
        }
        cout<<res<<"\n";
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("./input_file/1946.txt","rt",stdin);
    
    solve();

    return 0;
}