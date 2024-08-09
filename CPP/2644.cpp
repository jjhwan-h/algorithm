#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int> > map(101);
int n,m;
pair<int,int> relation;
vector<int> visited(101,0);

void BFS(){
    queue<pair<int,int> > Que;
    Que.push(make_pair(relation.first,0));
    visited[relation.first]=1;

    while(!Que.empty()){
        pair<int,int> s = Que.front();
        Que.pop();

        if(s.first==relation.second) {
            printf("%d",s.second); 
            return;
        }

        for(int i=0;i<map[s.first].size();i++){
            if(!visited[map[s.first][i]]){
                visited[map[s.first][i]] = 1;
                Que.push(make_pair(map[s.first][i], s.second+1));
                //printf("%d",s.second);
            }
        }
    }
    printf("-1");
    return;
    
}

int main(void){
    pair<int,int> tmp;
    freopen("./input_file/2644.txt","rt",stdin);
    scanf("%d",&n);
    scanf("%d %d",&relation.first,&relation.second);
    scanf("%d",&m);
    
    for(int i=0;i<m;i++){
        scanf("%d %d",&tmp.first,&tmp.second);
        map[tmp.first].push_back(tmp.second);
        map[tmp.second].push_back(tmp.first);
    }

    BFS();

    return 0;
}