/*
2024/01/15 장정환 백준 부분분할
*/

#include<iostream>
#include<vector>

using namespace std;

int N,S;

int main(void){
    freopen("./input_file/1806.txt","rt",stdin);
    int pre=0,post=0,res,tmp;
    vector<int> nums;
    cin>> N >> S;
    for(int i=0;i<N;i++){
        cin>> tmp;
        nums.push_back(tmp);
    }

    res= N+1; tmp=0;
    
    while(pre<=post && post<N){
        tmp+=nums[post++];

        while(tmp>=S){
            if(res>post-pre){
                res=post-pre;
            }
            tmp-=nums[pre++];
        }
        
    }

    if(res==N+1) cout<<0;
    else cout<< res;

    return 0;


    
}