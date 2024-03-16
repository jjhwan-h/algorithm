/*
2023/01/03 장정환 백준 14501 퇴사 문제
*/

#include<iostream>
#include<vector>

using namespace std;


vector<std::pair<int,int> > schedule;

int N;

void Input(){
    int day,income;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>> day >> income;
        schedule.push_back(make_pair(day,income));
    }
}

int main(void){
    //freopen("./input_file/14501.txt","rt",stdin);

    Input();
    vector<int> dp(N+1,0);
    for(int i=schedule.size()-1;i>=0;i--){
        if(i+schedule[i].first<=N){
            if(dp[i+1] > dp[i+schedule[i].first] + schedule[i].second)
                dp[i]=dp[i+1];
            else
                dp[i]=dp[i+schedule[i].first] + schedule[i].second;          
        }
        else{
            dp[i]=dp[i+1];
        }
    }

    cout<<dp[0];

    return 0;

}