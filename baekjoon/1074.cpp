/**
 * @file 1074.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief  BOJ/Z
 * @version 0.1
 * @date 2024-06-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<cmath>

using namespace std;

int main(void){
    int N,r,c;

    cin>>N>>r>>c;
    int expo=N,sum=0,base=2,remainR=0,remainC=0;

    while(r!=0 || c!=0){
        int x=0,y=0;
        int line= pow(base,expo-1);
        if(r>=line) {y=1; r-=line;}
        if(c>=line) {x=1; c-=line;}
        sum+=pow(base,2*(expo-1))*(x+2*y);
        expo--; 
    }

    cout<<sum;
    
    return 0;
}