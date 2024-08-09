#include<iostream>
#include<vector>

using namespace std;

int N,L,res;
int rMap[101][101];
int cMap[101][101];
class human{
    public:
        int loc;
        vector<int> visited;

    human(int l,int n):visited(n,0){
        this->loc =l;
    };
    void GoOne(int map[][101],int i, int stride=1){
        this->loc+=stride;
    };
    int canDown(int map[][101],int i,int stride){
        for(int j=1;j<L+1;j++){
            if(map[i][this->loc]-map[i][j+this->loc]!=1) return -1;
        }
        for(int i=1;i<stride+1;i++){
           this->visited[this->loc+i]=1;
        }
        return 1;
    };
    int canUp(int map[][101],int i,int stride){
        for(int j=1;j<L;j++){
            if(map[i][this->loc-j]!=map[i][this->loc] 
                || visited[this->loc-j]==1) return -1;
        }
        for(int i=0;i<stride;i++){
            if(visited[this->loc+i]==1)return -1;
            this->visited[this->loc+i]=1;
        }
        return 1;
    };  
    void initVisit(){
        this->visited.assign(visited.size(),0);
    }
};

void Input(){
    cin>> N >> L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>> rMap[i][j];
            cMap[N-j-1][i]=rMap[i][j];
        }
    }
    
}

void Go(int map[][101]){
    human hum(0,N);
    
    for(int i=0;i<N;i++){
        int possible=0;
        hum.loc=0;
        hum.initVisit();
        while(hum.loc<N-1){
                possible=0;
                if(map[i][hum.loc]>map[i][hum.loc+1]){
                    possible=hum.canDown(map,i,L);
                }
                else if(map[i][hum.loc]<map[i][hum.loc+1]){
                    possible=hum.canUp(map,i,L);
                }
                if(possible==-1)break;
                else{ hum.GoOne(map,i,1);}
            }
        if(hum.loc>=N-1) {res++; cout<<i<<" ";}
        cout<<"\n";
    }
}
void Res(){
    cout<<"rMap"<<"\n";
    Go(rMap);
    cout<<"cMap"<<"\n";
    Go(cMap);
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/14890.txt","rt",stdin);
    Input();
    Res();

    cout<<res;
    return 0;
}