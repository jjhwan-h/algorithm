/*
문자 찾기
*/

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('',(str)=>{
    rl.question('',(c)=>{
        console.log(CountChar(str,c));
        rl.close();
    })
    
})


const CountChar = (str,c)=>{

    /*
        return str.length - str.replaceAll(char,"").length;
        //전체 문장에서 찾는 문자를 빈칸으로 바꾼 후 전체문장과 뺄셈을 한다.
    */
    let cnt=0;
    [...str].forEach((el)=>{
        if(el===c) cnt++;
    })
    return cnt;
}
