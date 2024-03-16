/**
 * @file 1068.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief 트리
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

vector<int> tree[51];
vector<int> root;
int N,D,leaf,sum;

void Input(){
    int tmp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        tree[tmp+1].push_back(i+1);
    }
    cin>>D;
    D++;
}
void DFS(int s){
    if(tree[s].size()==0){leaf++; return;}

    int size = tree[s].size();
    for(int i=0;i<size;i++){
        if(tree[s][i]==-1){
            if(size==1){
                 leaf++;
                continue;
            }
        }
        else{
            DFS(tree[s][i]);
        }
    }
}
void removeNode(int r){
    for(int i=0;i<tree[r].size();i++){
        if(tree[r][i]==D) {tree[r][i]=-1; break;}
        removeNode(tree[r][i]);
    }
}
void findRoot(){
    for(int i=0;i<tree[0].size();i++){
        root.push_back(tree[0][i]);
    }
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("./input_file/1068.txt","rt",stdin);

    Input();
    findRoot();
    //for(int i=0;i<root.size();i++) =>트리가 여러개인경우
    if(root[0]!=D){
        removeNode(root[0]);
        for(int i=0;i<root.size();i++){
            leaf=0;
            DFS(root[i]);
            sum+=leaf;
        }//countLeaf
    }
    else sum=0;
    cout<<sum;

    return 0;  
}