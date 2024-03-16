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
  ans = ans.split(' ');
  ans = ans.map(str=>parseInt(str,10));
  
  console.log(FindMinimum(ans));
  
  rl.close();
});

function FindMinimum(arr){
    let min = Number.MAX_SAFE_INTEGER;

    for(let i=0;i<arr.length;i++){
        if(arr[i]<min) min = arr[i];
    }
    //내장함수 사용, ...(spread 연산자를 통해 배열을 펼쳐준다.=> arr[0],arr[1],arr[2],...)
    // let answer = Math.min(...arr); 
    //또는 let answer = Math.min.apply(null,arr);
    
    return min
}