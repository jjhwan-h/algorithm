#include<stdio.h>

using namespace std;

int main(void){
    int N, min=2, max=1, six=6, multiple=1, res=1;

    scanf("%d",&N);

    while(N>=min){
        max+= six * multiple;
        min=max+1;
        multiple++;
        res++;
    }

    printf("%d",res);

    return 0;
}