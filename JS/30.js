/**
 * @file 30.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 뒤집은소수(브루트포스)
 * @version 0.1
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/30.txt"),
    output:process.stdout,
});

input =[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    reversePrime(input);
    process.exit();
});

const reversePrime = (input)=>{
    
    input[1].forEach((el)=>{
        let flag = false
        let num = parseInt(el.toString().split('').reverse().join(''),10);
        for(let i=2;i*i<=num;i++){
            if(num%i===0) {
                flag=true; break;
            }
        }
        if(flag===false && num !==1) console.log(num);
    })
}
