/*
연필개수
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
  ans = ans.split(' ');
  ans = ans.map(str=>parseInt(str,10));
  console.log(das(ans));
  
  rl.close();
});

function das(N){
    let res;
    //Math.floor(내림), Math.round(반올림), Math.ceil(올림)
    res = Math.floor( N / 12);
    return res+1;
}