#include<stdio.h>


using namespace std;

int DP[301];
int stair[301];

int main(void){
    int N;
    //freopen("./input_file/2579.txt","rt",stdin);
    scanf("%d",&N);

    for(int i=1;i<=N;i++){
        scanf("%d",&stair[i]);
    }

    DP[1] = stair[1];
    DP[2] = stair[1]+stair[2];

    for(int index = 3; index<=N; index++){
        DP[index] = ((DP[index-2]) > (DP[index-3]+stair[index-1]) ?  (DP[index-2]) : (DP[index-3]+stair[index-1])) + stair[index];
    }
    
    printf("%d",DP[N]);

    return 0;

    return 0;

}