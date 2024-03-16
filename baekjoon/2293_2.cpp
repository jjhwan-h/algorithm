/*
메모리초과로 인해 틀린풀이
*/
#include<stdio.h>
#include<vector>

using namespace std;

int dp[101][10001]={0,};
int n,k;

int main(void){
    int tmp;
    
    //freopen("./input_file/2293.txt","rt",stdin);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        dp[i][0]=tmp;
    }

  for(int j=1;j<=n;j++){
	for(int i=1;i<=k;i++){
		if(i>=dp[j][0]){
			dp[j][i] = dp[j-1][i] + dp[j][i-dp[j][0]];
		}
	}
  }

    printf("%d\n",dp[n][k]);

    return 0;
}