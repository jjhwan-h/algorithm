/**
 * @file 1541.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 잃어버린 괄효 그리디
 * @version 0.1
 * @date 2024-04-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<string>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1541.txt","rt",stdin);

    string input;
    string num;
    bool isMinus=false;
    int res=0;

    cin>>input;
    for(int i=0;i<=input.size();i++){
        if(input[i]=='-' || input[i]=='+' || i==input.size()){
            if(isMinus){
                res-=stoi(num);
                num="";
            }
            else{
                res+=stoi(num);
                num="";
            }
        }
        else{
            num+=input[i];
        }
        if(input[i]=='-'){
            isMinus=true;
        }
    }
    cout<<res;
    return 0;
}