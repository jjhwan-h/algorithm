/**
 * @file 29.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 자릿수의 합(브루트포스)
 * @version 0.1
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/29.txt"),
    output:process.stdout,
});

input=[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    maxDigitSum(input);
    process.exit();
});

const maxDigitSum = (input)=>{
    let max=0;
    let index;
    let n = input[0];
    input[1].forEach((el,idx)=>{

       let sum = el.toString() //split을 사용하기위해 정수를 string으로 변환
                    .split('') //각 자리수를 split
                    .reduce((acc,cur,idx)=>acc+= parseInt(cur,10) ,0); //자리수의 합가산
       if(sum>max) {
            max=sum;
            index=idx;
       } else if(sum===max){
            if(input[1][idx]>input[1][index]) index=idx;
       }
    });
    console.log(input[1][index]);
    return;
}

/**
 * 또는 sum을 구하는부분을 아래와 같이 해도됨. 뭐가 더빠를려나..
 * while(tmp){
 *     sum+=tmp%10;
 *      tmp=Math.floor(tmp/10);
 * }
 */
