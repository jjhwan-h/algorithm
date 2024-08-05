/**
 * @file 2493.cpp
 * @author jang jeong hwan (you@domain.com)
 * @brief BOJ/2493/탑
 * @version 0.1
 * @date 2024-08-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int> > tower;
int N;

void solve(){
    int tmp;
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>tmp;

        while(!tower.empty() && tower.back().first<tmp){
            tower.pop_back();
        }
         if(!tower.empty() && tower.back().first>tmp) {
            cout<<tower.back().second<<" ";
        }

        if(tower.empty()){
            cout<<0<<' ';
        }
        tower.push_back(make_pair(tmp,i));
    }
    
    return ;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2493.txt","rt",stdin);

    solve();

    return 0;
}