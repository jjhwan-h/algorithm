/**
 * @file 15666.cpp
 * @author jangjeonghwan
 * @brief 백준 N과M(12) -백트래킹
 * @version 0.1
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024/01/29
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int N,M;
vector<int> ch;
void Input(vector<int> &num){
    for(int i=0;i<N;i++){
        cin >> num[i];
    }
}
void DFS(vector<int> &num,int i){
    if(ch.size() == M) {
        for(int k=0;k<M;k++){
            cout<<ch[k]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int j=i;j<num.size();j++){
        ch.push_back(num[j]);
        DFS(num,j);
        ch.pop_back();
    }
}
// vector<int> remove(vector<int> &tmp){ //중복제거
//     int pre=0,it=0;
//     vector<int> num;
//     num.push_back(tmp[0]);
//     while(it<tmp.size()){
//        if(tmp[pre] != tmp[it]){
//             num.push_back(tmp[it]);
//             pre=it;
//        }
//        it++;
//     }
//     return num;
// }

vector<int> remove(vector<int> &tmp){ //set을 이용한 중복제거
    set<int>s;
    vector<int> v;
    for(const auto it:tmp){
        s.insert(it);
    }
    for(const auto it:s){
        v.push_back(it);
    }
    return v;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/15666.txt","rt",stdin);
    cin>> N >> M;
    vector<int> tmp(N);
    
    Input(tmp);
    sort(tmp.begin(),tmp.end());
    vector<int> num = remove(tmp);
    DFS(num,0);

    return 0;

}