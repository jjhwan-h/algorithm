#include<stdio.h>

using namespace std;

int map[2][100001];
int DP[2][100001];

int max(int a, int b){
    if(a>=b) return a;
    return b;
}
void score(){
    int n;
    
    scanf("%d",&n);

    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&map[i][j]);
        }
    }

    DP[0][1] = map[0][1];
    DP[1][1] = map[1][1];

    for(int j=2;j<=n;j++){
        DP[0][j] = max(DP[1][j-1],DP[1][j-2]) + map[0][j];
        DP[1][j] = max(DP[0][j-1],DP[0][j-2]) + map[1][j];
    }
    
    printf("%d\n",max(DP[0][n],DP[1][n]));

}

int main(void){
    int t;
    freopen("./input_file/9465.txt","rt",stdin);

    scanf("%d",&t);

    for(int i=0;i<t;i++) 
        score();

    return 0;
    


}