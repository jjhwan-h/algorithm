#include<stdio.h>
#include<vector>
#define lld long long

using namespace std;

int N,B,C;
lld res;
vector<int> candidate;
void Input(){
    int tmp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        candidate.push_back(tmp);
    }
    scanf("%d %d",&B,&C);
}

int Solve(int i){
    int tmp=0 , viewer=0;
    
    tmp = candidate[i] - B;
    viewer++;
    if(tmp >0){
        viewer += tmp / C;
        tmp = tmp % C;
        if(tmp>0) viewer++;
    }
    return viewer;
}

int main(void){
    Input();
    for(int i=0;i<N;i++){
        res += Solve(i);
    }

    printf("%lld",res);
    return 0;
}