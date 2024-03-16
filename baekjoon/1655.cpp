#include<stdio.h>
#include<queue>

using namespace std;

priority_queue<int, vector<int>,less<int>> maxPq;
priority_queue<int, vector<int>,greater<int>> minPq;

int main(void){
    int N,input, diff1,diff2;
    //freopen("./input_file/1655.txt","rt",stdin);
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&input);
        
        if(maxPq.size() ==0 || maxPq.top() >= input){
            maxPq.push(input);
        }
        else{
            minPq.push(input);
        }
        diff1 = maxPq.size() - minPq.size();
        diff2 = minPq.size() - maxPq.size();
        if( diff1 > 1){
            minPq.push(maxPq.top());
            maxPq.pop();
            //printf("%d\n",maxPq.top());
        }
        else if( diff2 >=1){
            maxPq.push(minPq.top());
            minPq.pop();
            //printf("%d\n",maxPq.top());
        }
        printf("%d\n",maxPq.top());
    }
    return 0;
}