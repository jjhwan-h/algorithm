/*
2023/01/06 장정환 백준 수고르기 
*/

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int N,M;
vector<int> arr;
void Input(){
    int tmp;
    cin>> N >> M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
}
// void quickSort(int s, int e){
//     if(s>=e) return;
//     int pivot = s;
//     int sp=s+1;
//     int ep=e-1;

//     while(sp<ep){
//         while(sp<e && arr[sp]<arr[pivot]) sp++;
//         while(arr[ep]>arr[pivot]) ep--;

//         if(sp>=ep) break;
//         swap(arr[sp],arr[ep]);
//     }
//     swap(arr[ep],arr[pivot]);
//     quickSort(s,ep-1);
//     quickSort(ep+1,e);
// }
void getMin(){
    int pre=0, post=1;
    int min = INT_MAX;
    while(pre<N && post<N){
        int sub = arr[post]-arr[pre];
        if(sub<M){ 
            post++;
            continue;
        }
        if(sub==M){
            cout<<sub;
            return;
        }
        if(sub<min) min=sub;
        pre++;
    }
    cout<<min;
}
int main(void){
    freopen("./input_file/2230.txt","rt",stdin);

    Input();
    //quickSort(0,arr.size());
    sort(arr.begin(),arr.end()); //기본적으로 오름차순정렬
    getMin();

    return 0;


}