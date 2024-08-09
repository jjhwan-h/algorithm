#include<stdio.h>
#include<vector>

using namespace std;

int dp[10001]={0,};
int n,k;
vector<int> vec;

int main(void){
    int tmp;
    dp[0]=1;
    //freopen("./input_file/2293.txt","rt",stdin);
    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        vec.push_back(tmp);
    }

    for(int i=0;i<vec.size();i++){
        for(int j=vec[i];j<=k;j++){
            dp[j]+=dp[j-vec[i]];
        }
    }

    printf("%d\n",dp[k]);

    return 0;
}