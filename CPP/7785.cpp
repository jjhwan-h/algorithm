#include<iostream>
#include<map>

using namespace std;

int N;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    map <string,string,greater<string> > employ;
    string a,b;
    freopen("./input_file/7785.txt","rt",stdin);
    cin>>N;

    for(int i=0;i<N;i++){
        cin>> a >> b;
        employ[a]=b;
    }
    
    map<string, string> :: iterator it;
    for(it=employ.begin(); it!=employ.end() ;it++){
        if(!it->second.compare("enter")) cout<<it->first<<"\n";
    }

    return 0;
}