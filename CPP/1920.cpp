/*
2024/01/25 장정환 백준 1920번
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nums;
bool flag=false;
void hasNum(int s, int e, int n){
    int mid=(s+e)/2;

    if(s>e) return;
    if(nums[mid]>n) hasNum(s,mid-1,n);
    else if(nums[mid]<n) hasNum(mid+1,e,n);
    else {flag=true; return;}
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,tmp;
    freopen("./input_file/1920.txt","rt",stdin);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        nums.push_back(tmp);
    }

    sort(nums.begin(),nums.end());

    cin >>M;
    for(int i=0;i<M;i++){
        cin>>tmp;
        hasNum(0,nums.size()-1,tmp);
        cout<< flag<<"\n";
        flag=false;
    }

    return 0;

}