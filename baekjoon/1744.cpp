/**
 * @file 1744.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/1744/수묶기
 * @version 0.1
 * @date 2024-06-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> positive;
vector<int> negative;
int N,zero;
long long res;

bool comp(int a, int b){
    return a>b;
}
void input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        if(tmp>0) positive.push_back(tmp);
        else if(tmp<0) negative.push_back(tmp);
        else zero++;
    }
}

void solve(){
    int i=0;
    sort(positive.begin(),positive.end(),comp);
    sort(negative.begin(),negative.end());

    for(i=1;i<positive.size();i=i+2){
        int v1=positive[i]; int v2=positive[i-1];
        if(v1==1 || v2==1) res+= v1+v2;
        else res+= positive[i]*positive[i-1];
    }
    if(positive.size()%2) res+=positive[positive.size()-1];

    for(i=1;i<negative.size();i=i+2){
        res+= negative[i]*negative[i-1];
    }
    if(negative.size()%2) {
        if(zero>0) zero--;
        else res+=negative[negative.size()-1];
    }

    cout<<res;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1744.txt","rt",stdin);

    input();
    solve();

    return 0;
}