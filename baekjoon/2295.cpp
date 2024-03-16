/**
 * @file 2295.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 2295 세수의합(이분탐색)
 * @version 0.1
 * @date 2024-03-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct El{  //사용되는 수가 중복되면 안되는 문제일 경우는 index를 기억해야한다. (이문제에서는 중복되도 된다.)
    int idx1;
    int idx2;
    int sum;
};
bool compare(const El& a, const El& b){
    return a.sum < b.sum;
};
int N;
vector<El> two;    //두개의 합
vector<int> num;    //input
int res;

void Input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        num.push_back(tmp);
    }
}
void MakeTwo(){
    //사용되는 수가 중복되도 가능.
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            El el = {i,j,num[i]+num[j]};
            two.push_back(el);
        }
    }
}
bool binary_search(int n){ //c++표준라이브러리로 std::binary_search 존재하기는 한다.
    int low=0, high=two.size()-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(n>two[mid].sum){
            low=mid+1;
        }
        else if(n<two[mid].sum){
            high=mid-1;
        }
        else return true;
    }
    return false;
}
void Find(){
    int rp=N-1;
    
    while(rp>=0){
        for(int lp=rp-1;lp>=0;lp--){
            int find = num[rp]-num[lp];
            //cout<<"find:"<<find<<", num[rp]:"<<num[rp]<<", num[lp]:"<<num[lp]<<"\n";
            bool flag = binary_search(find);
            if(flag) {
                res=num[rp];
                return;
            }
        }
        rp--;
    }
    return;
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/2295.txt","rt",stdin);
    
    Input();   
    sort(num.begin(),num.end());
    MakeTwo();
    sort(two.begin(),two.end(),compare);
    Find();
    cout<<res;

    return 0;
}