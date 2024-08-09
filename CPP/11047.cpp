/*
2024/01/29 장정환 백준 동전0 11047
*/

#include<iostream>
#include<vector>

using namespace std;

int N,K;

int main(void){
    int rest,it,res=0;
    //freopen("./input_file/11047.txt","rt",stdin);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    vector<int> coin(N);
    it = N-1;

    for(int i=0;i<N;i++){
        cin >> coin[i];
    }

    while(K>0 && it>=0){
        res+=K/coin[it];
        K=K%coin[it];
        it--;
    }

    cout<<res;

    return 0;
    
}