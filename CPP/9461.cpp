
/*
2023/11/05 jangjeonghwan
N의 값이 1<= N && N<=100이므로 longlong을 사용해준다.
점화식 두개가능
1) dp[1] 부터 dp[3]은 1, dp[4]부터 dp[5] = 2일때, dp[j]=dp[j-1]+dp[j-5]
2) dp[1]부터 dp[3]은 1일때, dp[j] = dp[j-3]+dp[j-2]
*/
#include<stdio.h>

using namespace std;

long long dp[101]={0,1,1,1,2,2,};
int main(void){
    int T,N;
    

    freopen("./input_file/9461.txt","rt",stdin);
    scanf("%d",&T);

    for(int i=0;i<T;i++){
        scanf("%d",&N);
        if(N>=6){
            for(int j=6;j<=N;j++){
            if(dp[j]==0) dp[j] = dp[j-1] + dp[j-5];
            }
        } 
        printf("%lld\n",dp[N]);
    }

    return 0;
    
}