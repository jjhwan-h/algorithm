/**
 * @file 46.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 쇠막대기
 * @version 0.1
 * @date 2024-03-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');
const rl = readline.createInterface({
    input:fs.createReadStream("./input/46.txt"),
    output:process.stdout,
});

const input=[];

rl.on("line",(line)=>{
    input.push(line.split(''));
}).on("close",()=>{
    countStick(input);
    process.exit();
});

const countStick = (input)=>{
    input = input[0];
    let stack=[], res=0, flag=false;

    while(input.length){
        const el = input.pop();
        if(el===')'){
            flag=false;
            stack.push(el);
        }
        else if(el==='('){
            if(flag){
                stack.pop();
                res++;
                continue;
            }
            stack.pop();
            res+=stack.length;
            flag=true;
        }
    }
    console.log(res)
};

