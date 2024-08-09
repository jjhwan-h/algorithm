/**
 * @file 20366.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 같이눈사람 만들래?(투포인터, DFS)
 * @version 0.1
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<int> snow;
int N, res=INT32_MAX;

void Input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        snow.push_back(tmp);
    }
}

void Solve(){
    int left, right, anna, elsa, tmp=0;

    for(int i=0;i<N-3;i++){
        for(int j=i+3;j<N;j++){
            left = i+1;
            right = j-1;
            
            while(left<right){
                anna = snow[i]+snow[j];
                elsa = snow[left]+snow[right];
                tmp = abs(anna-elsa);

                res = min(tmp,res);

                if(anna>elsa) left++;
                else right--;
            }
        }
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/20366.txt","rt",stdin);

    Input();
    sort(snow.begin(),snow.end());
    Solve();

    cout<<res;

    return 0;
}