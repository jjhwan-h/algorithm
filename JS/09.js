/*
A를 #으로
*/
const readline = require('readline');



// readline 모듈을 사용하여 인터페이스를 생성합니다.
const rl = readline.createInterface({
  input: process.stdin,  // 표준 입력 스트림을 사용합니다.
  output: process.stdout // 표준 출력 스트림을 사용합니다.
});


// 사용자에게 질문을 물어봅니다.
rl.question('', (str) => {
    
        MakePound(str);

        rl.close();
 
});

const MakePound = (str) =>{
    
    //string을 arr로 변환 하고 map함수(배열의 함수)로  if문
    str = [...str].map((el)=>{
        console.log(el)
        if(el==="A") return "#";
        else return el;
    })
    //배열의 값을 다시 string으로
    str = str.join('');

    /*
     let answer = s; // string은 얕은복사가아닌 값의 복사가 따로 일어난다.
     s= s.replace(/A/g , '#'); //stirng의 원소중 A를 전역(g)적을 찾아 #으로 바꾼다.
     
     console.log(s);
     return answer;
    */
    console.log(str);
};