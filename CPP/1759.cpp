/**
 * @file 1759.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int L, N;
vector<char> arr;
vector<char> pw;
void Input(){
    char tmp;
    cin>>L>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
}
void DFS(int j){
    if(pw.size()==L){
        int vowel=0, consonant =0;
        for(int i=0;i<L;i++){
           if(pw[i]=='a' || pw[i]=='i' 
                || pw[i] =='e' || pw[i] =='o' 
                || pw[i]== 'u') vowel++;
        }
        consonant = L -vowel;
        if(consonant<2 || vowel <1) return;
        
        for(int i=0;i<L;i++){
            cout<<pw[i];
        }
        cout<<"\n";
        return;
    }

    for(int i=j;i<N;i++){
        pw.push_back(arr[i]);
        DFS(i+1);
        pw.pop_back();
    }
}
void Solve(){
    DFS(0);
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1759.txt","rt",stdin);

    Input();
    sort(arr.begin(),arr.end());
    Solve();

    return 0;
}