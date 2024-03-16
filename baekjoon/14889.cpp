#include<iostream>
#include<limits>
using namespace std;

int map[22][22]={0,};
int check[22]={0,};
int  N, cnt, res=INT32_MAX;

void Input(){
    cin>> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) {
            cin>>map[i][j];
        }
    }
}
void Cal(){
    int start=0, link=0, diff=0;
   for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(check[i]==1 && check[j]==1) start+=map[i][j];
            if(check[i]==0 && check[j]==0) link+=map[i][j];
        }
    }
    diff = abs(start-link);
    if(res>diff) res=diff;
    return;
}
void DFS(int i){
    
    if(cnt==N/2) Cal();

    for(int j=i+1;j<=N;j++){
        check[j]=1;
        cnt++;
        DFS(j);
        check[j]=0;
        cnt--;
    }
}


int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    freopen("./input_file/14889.txt","rt",stdin);

    Input();
    for(int i=1;i<=N/2;i++){
        check[i]=1;
        cnt++;
        DFS(i);
        check[i]=0;
        cnt--;
    }

    cout<<res;
    return 0;
}