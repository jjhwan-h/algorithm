/*
대문자 찾기
*/

const readline = require('readline');

const rl = readline.createInterface({
    input:process.stdin,
    output:process.stdout
});

rl.question('',(str)=>{
    console.log(CountUpper(str));
    rl.close();
})

const CountUpper = (str)=>{
    let cnt=0;
   // console.log(str);
    str = [...str].map((el)=>{
       el = el.charCodeAt(0); //문자를 Ascii로 변환
       
       if(el>=65 && el<=90) cnt++;
       // if(el === el.toUpperCase())
       /*
       대문자 65~90
       소문자 97~122
       숫자 48~57
       */
    })

    return cnt;
}