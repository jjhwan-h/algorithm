/**
 * @file 18870.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 좌표압축(투포인터)
 * @version 0.1
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int N;
vector<pair<int,int> > arr;
vector<pair<int, int> > res;
map<int,int> num;
bool compare(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}
void Input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(make_pair(tmp,i));    // 원소값, index
    }
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/18870.txt","rt",stdin);

    Input();
    std::sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<arr.size();i++){
        num[arr[i].first]=arr[i].second; //key값에 대해 자동오름차순 정렬 //second값은 덮어씌어짐
    }

    int p=0,idx=0;
    for(const auto& pair : num){
        while(arr[p].first==pair.first) {
            res.push_back(make_pair(arr[p].second,idx));
            p++;
        }
        idx++;
    }

    std::sort(res.begin(),res.end(),compare);

    for(int i=0;i<res.size();i++){
        cout<<res[i].second<<" ";
    }

    return 0;
}