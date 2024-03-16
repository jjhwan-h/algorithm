#include<stdio.h>
#include<vector>

using namespace std;

long long N,B;
vector<vector<int>>m_res(5,vector<int>(5));
vector<vector<int>>m_ans(5,vector<int>(5,0));
void matrix_multi(vector<vector<int>>*a,vector<vector<int>>*b ){
    vector<vector<int>>m_tmp(5,vector<int>(5,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                m_tmp[i][j]+= (*a)[i][k] * (*b)[k][j];
            }
            m_tmp[i][j]%=1000;
        }
    }
    *a = m_tmp;
}
void Input(){
    int tmp;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&tmp);
            m_ans[i][j]=tmp;
        }
        m_res[i][i]=1;
    }
}
void Solve(){
    while(B){
        if(B%2==1){
            matrix_multi(&m_res,&m_ans);
        }
        matrix_multi(&m_ans,&m_ans);
        B = B/2;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",m_res[i][j]);
        }
        printf("\n");
     }

}
void Solution(){
    Input();
    Solve();
}
int main(void){
    //freopen("./input_file/10830.txt","rt",stdin);
    scanf("%lld %lld",&N,&B);

    Solution();

    return 0;
}