#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> >map(101,vector<int>(101));
int N, verti, hori;

void input(){
    char el;
    freopen("./input_file/1652.txt","rt",stdin);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>el;
            if(el == '.')
                map[i][j]=0;
            else if(el == 'X')
                map[i][j]=1;
                
        }
    }
}

void solve(){
    int cnt=0;
    //가로
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==0){
                cnt++;
            }
            else if(map[i][j]==1){
                if(cnt>=2){
                    hori++;
                }
                cnt=0;
            }
        }
        if(cnt>=2){
            hori++;
        }
        cnt=0;
    }

    cnt=0;
    //세로
    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            if(map[j][i]==0){
                cnt++;
            }
            else if(map[j][i]==1){
                if(cnt>=2){
                    verti++;
                }
                cnt=0;
            }
        }
        if(cnt>=2){
            verti++;
        }
        cnt=0;
    }
}

int main(void){
    input();
    solve();

    cout<<hori<<" "<<verti<<endl;
    return 0;
}