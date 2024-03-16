/**
 * @file 6603.cpp (백준)
 * @author jang jeonghwan (you@domain.com)
 * @brief 로또 (백트래킹)
 * @version 0.1
 * @date 2024-02-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<sstream>
#include<string>

#define LOTTO 6

using namespace std;

int N=-1;
vector<int> lotto;

vector<int> Input(){
    int tmp;
    vector<int> vec;
    string str;

    getline(cin,str);
    istringstream iss(str);
    iss>>N;
    for(int i=0;i<N;i++){
        iss>>tmp;
        vec.push_back(tmp);
    }

    return vec;
}
void DFS(vector<int> &vec, int i){
    if(lotto.size()==LOTTO){
        for(int i=0;i<LOTTO;i++){
            cout<<lotto[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int j=i;j<vec.size();j++){
        lotto.push_back(vec[j]);
        DFS(vec,j+1);
        lotto.pop_back();
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/6603.txt","rt",stdin);

    vector<int> vec = Input();
    while(N!=0){
        DFS(vec,0);
        vec = Input();
        if(N==0) break;
        cout<<"\n";
    }

    return 0;
}