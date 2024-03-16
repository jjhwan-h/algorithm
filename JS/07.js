/*
자동차 10부제
자동차 번호의 1의 자리 숫자와 날짜의 일의 자리숫자가 같을경우 차량운행을 금지
7대 차량의 끝 두자리수와 날짜의 일의자리 수가 주어질때 10부제를 어긴 차량의 대수를 세어라
*/
const readline = require('readline');



// readline 모듈을 사용하여 인터페이스를 생성합니다.
const rl = readline.createInterface({
  input: process.stdin,  // 표준 입력 스트림을 사용합니다.
  output: process.stdout // 표준 출력 스트림을 사용합니다.
});


// 사용자에게 질문을 물어봅니다.
rl.question('', (day) => {
    day = parseInt(day,10);// 정수로 변환
    rl.question('',(car)=>{
        // 사용자로부터 정수를 입력받는데 빈칸을 기준으로 나눈다.
        //입력받은 수는 자동으로 string형태가 되는데 이를 map함수를 통해 각각 정수형으로 변형.
        car = car.split(' ');
        car = car.map(str=>parseInt(str,10));
  
        console.log(CountViolate(day,car));
  
        rl.close();
    })  
 
});

function CountViolate(day, car){
    let cnt=0;
    car.forEach((el,i,arr) => {
        if(el%10 === day) cnt++;
       // console.log(`${i}, ${arr}`);
    });

    return cnt;
}