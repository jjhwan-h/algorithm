/**
 * @file 2565.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/2565
 * @version 0.1
 * @date 2024-07-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int> > line;
vector<int> lis;
int N;

void input(){
    int s,e;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>s>>e;
        line.push_back(make_pair(s,e));
    }
}

int binarySearch(int v){
    int s=0, e= lis.size()-1, m;

    while(s<e){
        m = (s+e)/2;
        if(lis[m]>v) e=m;
        else if(lis[m]<v) s=m+1;
    }

    return e;
}

void solve(){
    sort(line.begin(),line.end());

    for(int i=0;i<line.size();i++){
        if( lis.empty() || lis.back() < line[i].second){
            lis.push_back(line[i].second);
        }
        else{
            int idx = binarySearch(line[i].second);
            lis[idx]=line[i].second;
        }
    }
    cout<< N - lis.size();
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2565.txt","rt",stdin);

    input();
    solve();

    return 0;
}