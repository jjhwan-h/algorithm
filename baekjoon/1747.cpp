#include<iostream>
#include<cstring>

using namespace std;


bool isPrime(int N){
    //1은 소수가 아니다. 제외시켜야한다.
    if(N<2) return false;

    for(int i=2;i*i<=N;i++){
        if(N%i==0) return false;
    }
    return true;
}

// bool isPalindrome(int N){
//     //cout<<N<<endl;
//     int res=0,  num;
//     num = N;
//     while(num!=0){
//         res *= 10;
//         res += (num%10);
//         num /= 10;
//     }
//     return(res==N);
// }

bool isPalindrome(int n){ //주어진 수가 팰린드롬인지 확인하는 함수
    string s=to_string(n);
    for(int i=0; i<s.length()/2; i++){
        if(s[i]!=s[s.length()-i-1]) return 0;
    }
    return 1;
}

int main(void){
    int N;
    cin>>N;

    while(1)
    {
        if (isPrime(N) && isPalindrome(N)) {
            cout<<N;
            break;
        }
        N++;
    }
    return 0;
}