
/**
 * @file 17609.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/17609/회문
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<string>

using namespace std;

int N;

int search(string s,int flag){
    int lt=0, rt=s.length()-1;
    while(lt<rt){
            if(s[lt]!=s[rt]){
                if(flag==0){
                    int f1=0,f2=0;
                    if(s[lt+1]==s[rt]){
                        string sub = s.substr(lt+1,rt-lt);
                        f1 = search(sub,1);
                    }
                    if(s[lt]==s[rt-1]){
                        string sub = s.substr(lt,rt-lt);
                        f2 = search(sub,1);
                    }
                    if(f1==1||f2==1) return 1;

                    return 2;
                }else{
                    return 2;
                }
            }else{
                lt++;
                rt--;
            }
    }
    return flag;
}
void solve(){
    cin>>N;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        int flag = search(s,0);
        cout<<flag<<"\n";
    }
}
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("./input_file/17609.txt","rt",stdin);

    solve();

    return 0;
}   