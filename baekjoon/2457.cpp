/**
 * @file 2457.cpp
 * @author jang jeonghwan (you@domain.com)
 * @brief BOJ/2457 공주님의 정원
 * @version 0.1
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct period{
    int s;
    int e;
};
int n;
vector<period> v;
bool compare(const period &a, const period &b){
    if(a.s==b.s) return a.e < b.e;
    return a.s < b.s;
}
void Input(){
    cin >> n;
    for(int i=0;i<n;i++)
	{
		int ms,ds,me,de;
		cin >> ms >> ds >> me >> de;
        period p = {ms*100+ds,me*100+de};
		v.push_back(p);
	}
}
void Solve(){
    int t = 301,res=0,idx=0;
	while (t<1201)
	{
		int nxt_t = t;
		for(int i=idx;i<n;i++) // 현재 기준 가장 긴 꽃을 구하는 과정
		{
			if(v[i].s <= t && v[i].e > nxt_t) 
			{										   
				nxt_t = v[i].e;
				idx = i;
			}
			else if(v[i].s > t) break; 
		}
		if (nxt_t == t) 
		{
			cout << 0 << "\n";
			return ;
		}
		t = nxt_t;
		res++;
	}
	cout << res << "\n";
    return;
}
int main()
{
    freopen("./input_file/2457.txt","rt",stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    Input();
	sort(v.begin(), v.end(),compare);
    Solve();
	
}