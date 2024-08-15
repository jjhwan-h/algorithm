/**
 * @file 2470-1.cpp
 * @author jang jeong hwan (you@domain.com)
 * @brief BOJ/2470/두 용액
 * @version 0.1
 * @date 2024-08-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> arr;
void input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
}
void solve(){
    int lt=0, rt=N-1, one,two, res=2147000000;
    sort(arr.begin(),arr.end());

    while(lt!=rt){
        int sum = abs(arr[lt]+arr[rt]);
        if(sum < res){
            res=sum;
            one=lt; two=rt;
        }

        if(arr[lt]+arr[rt]>0) 
            rt--;
        else if(arr[lt]+arr[rt]<0) 
            lt++;
        else break;
    }
    cout<<arr[one]<<" "<<arr[two];
}   
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2470.txt","rt",stdin);

    input();
    solve();

    return 0;
}