/**
 * @file 10816.cpp
 * @author jang jeong hwan (you@domain.com)
 * @brief 숫자카드2 (STL_MAP)
 * @version 0.1
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int N,M;
map<int,int> Map;

void Input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        Map[tmp]++;
    }
}
void Solve(){
    int tmp;
    cin>>M;
    for(int i=0;i<M;i++){
        cin >>tmp;
        cout<<Map[tmp]<<" ";
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/10816.txt","rt",stdin);

    Input();
    Solve();

    
}