/**
 * @file 1026.cpp
 * @author jang jenghwan (you@domain.com)
 * @brief 1026 보물
 * @version 0.1
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
vector<int> a;
vector<int> b;

bool compare(const int a, const int b){ return a>b;}
int main(void){
    int tmp,sum=0;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1026.txt","rt",stdin);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        cin>>tmp;
        b.push_back(tmp);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),compare);

    for(int i=0;i<N;i++) sum+=a[i]*b[i];

    cout<<sum;
    return 0;    
}