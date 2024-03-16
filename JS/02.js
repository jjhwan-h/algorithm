/*
삼각형 판별하기
삼각형이 되기 위해서는 짧은 막대 두개의 합이 큰막대보다는 커야한다.
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
  console.log(triangle(ans[0],ans[1],ans[2]));
  
  rl.close();
});




function triangle(a,b,c){
   console.log(`${a},${b},${c}`)
    let answer="YES",max;
    if(a>b) max=a;
    else max=b;

    if(max<c) max=c;
    
    if(max > (a+b+c-max)) 
        answer="NO";

    return answer;
}


