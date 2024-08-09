#include<stdio.h>
#include<vector>

using namespace std;
vector<int> com(101);
int cnt;

int FIND(int a){
    if(com[a]!=a) {com[a]=FIND(com[a]);}
    return com[a];
}
void UNION(int a, int b){
    int s = FIND(a);
    int e = FIND(b);

    // if(s<e) com[e]=s;
    // else com[s]=e;
    if(s!=e) com[s]=e;
}

int main(void){
    int N,K,a,b;
    freopen("./input_file/2606.txt","rt",stdin);

    scanf("%d",&N);
    for(int i=1;i<=N;i++) com[i]=i;

    scanf("%d",&K);
    for(int j=0;j<K;j++){
        scanf("%d %d",&a,&b);
        UNION(a,b);
    }
    
    for(int i=1;i<=N;i++) printf("%d ",com[i]);

    for(int i=2;i<=N;i++) {
        if(FIND(1)==FIND(i)) cnt++;
    }

    printf("%d",cnt);

    return 0;
}