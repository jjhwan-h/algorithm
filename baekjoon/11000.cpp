/**
 * @file 11000.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/11000/강의실배정
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
priority_queue<int> pq;
vector<pair<int,int> > vec;
void input(){
    int s,t;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s>>t;
        vec.push_back(make_pair(s,t));
    }
}
void solve(){
    sort(vec.begin(),vec.end());

    pq.push(-vec[0].second);
    for(int i=1;i<vec.size();i++){
        if(vec[i].first>=-pq.top()) pq.pop();
        pq.push(-vec[i].second);
    }

    cout<<pq.size();
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/11000.txt","rt",stdin);

    input();
    solve();

    return 0;
}