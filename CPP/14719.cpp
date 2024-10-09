/**
 * @file 14719.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/14719/빗물
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<algorithm>

using namespace std;

int H,W;
vector<int> input(){
    vector<int> vec;
    int num;
    cin>>H>>W;
    for(int i=0;i<W;i++){
        cin>>num;
        vec.push_back(num);
    }
    return vec;
}

void solve(vector<int> vec){
    int res=0;
    vector<int> full=vec;

    for(int i=0;i<vec.size();i++){
        int pos = i-1, cnt=0;
        while(pos>=0){
            if (full[pos]>=full[i]){
                if(i-pos==1) break;
                res += vec[i]*(i-pos-1)-cnt;
                for(int j=pos+1;j<i;j++){
                    full[j]=vec[i];
                }
                break;
            }
            cnt+=full[pos];
            pos--;
        }
        cnt=0;
        pos = i+1;
        while(pos<vec.size()){
            if (full[pos]>=full[i]){
                if(pos-i==1) break;
                res+=vec[i]*(pos-i-1)-cnt;
                for(int j=i+1;j<pos;j++){
                    full[j]=vec[i];
                }
                break;
            }
            cnt+=full[pos];
            pos++;
        }
    }

    cout<<res;
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/14719.txt","rt",stdin);

    vector<int> vec =input();
    solve(vec);
}