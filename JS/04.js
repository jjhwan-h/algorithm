/*
1부터 N까지 합 출력하기
*/
const readline = require('readline');

// readline 모듈을 사용하여 인터페이스를 생성합니다.
const rl = readline.createInterface({
  input: process.stdin,  // 표준 입력 스트림을 사용합니다.
  output: process.stdout // 표준 출력 스트림을 사용합니다.
});

let ans=[];
// 사용자에게 질문을 물어봅니다.
rl.question('', (ans) => {
  // 사용자로부터 정수를 입력받는데 빈칸을 기준으로 나눈다.
  //입력받은 수는 자동으로 string형태가 되는데 이를 map함수를 통해 각각 정수형으로 변형.
//   ans = ans.split(' ');
//   ans = ans.map(str=>parseInt(str,10));
  ans = parseInt(ans,10); //str을 int로 변경
  console.log(Sum(ans));
  
  rl.close();
});

function Sum(n){
    let res
    if(n%2===0){
        console.log(`${n+1}, ${n/2}`)
        res = (n+1)*(n/2);
        
    }
    else{
        res = (n+1)*Math.floor(n/2);
        res += Math.ceil(n/2);
    }
    return res
}