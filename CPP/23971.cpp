#include<stdio.h>

int H,W,N,M; //행, 열, 세로 공백, 가로 공백

void Input(){
    scanf("%d %d %d %d",&H,&W,&N,&M);
}
int Solve(){
    int row_res=0, col_res=0;
    row_res = H / (N+1);
    if(H%(N+1)) row_res++;
    col_res = W / (M+1);
    if(W%(M+1)) col_res++;

    return row_res * col_res;
}
int main(void){
    int res=0;
    Input();
    res = Solve();
    printf("%d",res);

    return 0;
}